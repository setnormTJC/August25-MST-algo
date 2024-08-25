#include <iostream>
#include <string>
#include <vector>
#include<fstream> 
#include<iomanip>

#include<algorithm>

using std::cout; 
using std::string; 
using std::vector; 

struct WeightedEdge
{
	string v1; 
	string v2; 
	int weight; 

	bool operator == (const WeightedEdge& otherEdge)
	{
		return (this->v1 == otherEdge.v1
			&&
			this->v2 == otherEdge.v2
			&&
			this->weight == otherEdge.weight);
	}
};

struct Graph
{
	vector<string> vertices; 
	vector<WeightedEdge> edges;

	WeightedEdge returnMinWeightEdge()
	{
		int minWeight = edges.at(0).weight; 
		for (auto& edge : edges)
		{
			if (edge.weight < minWeight)
			{
				minWeight = edge.weight; 
			}
		}

		for (auto& edge : edges)
		{
			if (edge.weight == minWeight)
			{
				return edge;
			}
		}
	}

};

Graph makeFirstExampleGraph()
{
	Graph g; 
	g.vertices =
	{
		"u", "v", "w", "x", "y", "z"
	};

	g.edges =
	{
		{"u", "v", 1},
		{"v", "z", 2},
		{"u", "z", 3},

		{"v", "w", 4},
		{"w", "z", 5},

		{"w", "y", 6},
		{"y", "z", 7},

		{"w", "x", 8},
		{"x", "y", 9}
	};

	return g; 
}


Graph makeMinSpanTree_WithKruskal(Graph graph)
{
	Graph minSpanTree; 

	//Step 1: "select" edge of G with minimum weight (may be more than one): 
	auto minWeightEdge = graph.returnMinWeightEdge(); 
	minSpanTree.edges.push_back(minWeightEdge);
	//minSpanTree.vertices.push_back(minWeightEdge.v1);
	//minSpanTree.vertices.push_back(minWeightEdge.v2);

	//remove that edge from consideration: 
	auto it = std::find(graph.edges.begin(), graph.edges.end(), minWeightEdge);
	graph.edges.erase(it);

	//Step 2: select REMAINING edge of minimum weight: 
	minWeightEdge = graph.returnMinWeightEdge(); 
	minSpanTree.edges.push_back(minWeightEdge);
	//minSpanTree.vertices.push_back(minWeightEdge.v1);
	//minSpanTree.vertices.push_back(minWeightEdge.v2);

	it = std::find(graph.edges.begin(), graph.edges.end(), minWeightEdge);
	graph.edges.erase(it);

	//TERMINATION condition: the number of edges in the min. span. tree
	// is number of graph vertices MINUS 1
	while (minSpanTree.edges.size() != graph.vertices.size() - 1)
	{
		//Step 3: 
		//Select remaining edge of minimum weight 
		//that does NOT form a cycle with previously-selected edges: 
		 
	}

	return minSpanTree; 
}

int main()
{
	auto graph = makeFirstExampleGraph(); 

	auto minSpanTree = makeMinSpanTree_WithKruskal(graph); 


	return 0; 
}