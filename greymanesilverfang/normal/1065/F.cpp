#include <iostream>
#include <vector>
const int N = 1000001;
int n, k, dilen[N], ditiep[N], diluon[N];
std::vector<int> adj[N];

void dfs(int u)
{
	if (adj[u].empty())
	{
		dilen[u] = k;
		ditiep[u] = 1;
	}
	for (int v : adj[u])
	{
		dfs(v);
		if (dilen[v] == 0)
			ditiep[v] = 0;
		else 
		{
			dilen[u] = std::max(dilen[u], dilen[v] - 1);
			ditiep[u] += ditiep[v];
		}
		diluon[u] = std::max(diluon[u], diluon[v] - ditiep[v]);
	}
	diluon[u] += ditiep[u];
}

int main()
{
	std::cin >> n;
	if (n == 1)
	{
		std::cout << '0';
		return 0;
	}
	std::cin >> k;
	for (int i = 2; i <= n; ++i)
	{
		int p; std::cin >> p;
		adj[p].push_back(i);
	}
	dfs(1);
	std::cout << diluon[1];
	return 0;
}