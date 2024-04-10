#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define get_ans(x) (h[ans1[x]] - h[x] + h[ans2[x]] - h[x])
const int N = 2e5+1;
bool is_leaf[N];
int par[N], h[N], ans1[N], ans2[N];
long long dist[N];
std::vector<int> adj[N];

void DFS(int u)
{
	is_leaf[u] = true;
	ans1[u] = ans2[u] = u;
	for (int v : adj[u])
	{
		if (v == par[u])
			continue;
		par[v] = u;
		h[v] = h[u] + 1;
		DFS(v);
		if (!is_leaf[v])
			is_leaf[u] = false;
		else if (h[ans1[v]] >= h[ans1[u]])
		{
			ans2[u] = ans1[u];
			ans1[u] = ans1[v];
		}
		else if (h[ans1[v]] >= h[ans2[u]])
			ans2[u] = ans1[v];
	}
	if (adj[u].size() >= 3)
		is_leaf[u] = false;
}

int BFS(int u)
{
	int res = u;
	par[u] = 0;
	dist[u] = get_ans(u);
	std::queue<int> queue;
	for (queue.push(u); !queue.empty(); queue.pop())
	{
		int u = queue.front();
		for (int v : adj[u])
		{
			if (v == par[u])
				continue;
			if (is_leaf[v])
				continue;
			par[v] = u;
			dist[v] = dist[u] + 1e6;
			if (dist[res] + get_ans(res) < dist[v] + get_ans(v))
				res = v;
			queue.push(v);
		}
	}
	return res;
}

int main()
{
	int n; std::cin >> n;
	for (int i = 1; i < n; ++i)
	{
		int u, v; std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int root = 0;
	for (int i = 1; i <= n; ++i)
		if (adj[i].size() >= 3)
		{
			root = i;
			break;
		}
	DFS(root);
	int node1 = BFS(root);
	int node2 = BFS(node1);
	std::cout << ans1[node1] << " " << ans1[node2] << std::endl 
	          << ans2[node1] << " " << ans2[node2];
	return 0;
}