#include <algorithm>
#include <iostream>
#include <vector>
const int N = 200002;
bool not_trace[N];
int c[N], val[N], down[N];
std::vector<int> adj[N];

long long DFS(int u = 1, int p = 0)
{
	long long res = 0; 
	int max = -1;
	bool repeat = true;
	for (int v : adj[u])
		if (v != p)
		{
			res += DFS(v, u);
			if (max == -1 || val[max] < val[v])
			{
				max = v;
				repeat = false;
			}
			else if (val[max] == val[v])
				repeat = true;
		}
	val[u] = c[u];
	if (max != -1)
	{
		res -= val[max];
		if (val[u] > val[max])
			val[u] = val[max];
		if (!repeat)
		{
			down[u] = max;
			not_trace[max] = true;
		}
	}
	return res + val[u];
}

int main()
{
	int n; std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> c[i];
	for (int i = 1; i <= n - 1; ++i)
	{
		int u, v; std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	std::cout << DFS() << " ";
	std::vector<int> v;
	for (int i = 1; i <= n; ++i)
		if (!not_trace[i])
			for (int j = i; j != 0; j = down[j])
				if (val[i] == c[j])
					v.push_back(j);
	std::sort(v.begin(), v.end());
	std::cout << v.size() << std::endl;
	for (int x : v)
		std::cout << x << " ";
	return 0;
}