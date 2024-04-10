#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
const int N = 1e5+1;
bool chk[N];
std::vector<int> adj[N];

int main()
{
	int n, m; std::cin >> n >> m;
	for (int i = 1; i <= m; ++i)
	{
		int u, v; std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	std::priority_queue<int,std::vector<int>,std::greater<int>> heap;
	heap.push(1);
	chk[1] = true;
	while (!heap.empty())
	{
		int u = heap.top();
		heap.pop();
		std::cout << u << ' ';
		for (int v : adj[u])
			if (!chk[v])
			{
				heap.push(v);
				chk[v] = true;
			}
	}
	return 0;
}