#include <algorithm>
#include <iostream>
#include <vector>
const int N = 3e5+1;
int w[N], u[N], v[N], c[N], prv[N];
long long f[N], g[N];
std::vector<int> adj[N];

void dfs(int x)
{
	long long m1 = 0, m2 = 0;
	for (int e : adj[x])
	{
		int y = u[e] + v[e] - x;
		if (y != prv[x])
		{
			prv[y] = x;
			dfs(y);
			m2 = std::max(m2, g[y] - c[e]);
			if (m1 < m2)
				std::swap(m1, m2);
		}
	}
	f[x] = w[x] + m1 + m2;
	g[x] = w[x] + m1;
}

int main()
{
	int n; std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> w[i];
	for (int i = 1; i < n; ++i)
	{
		std::cin >> u[i] >> v[i] >> c[i];
		adj[u[i]].push_back(i);
		adj[v[i]].push_back(i);
	}
	dfs(1);
	long long res = 0;
	for (int i = 1; i <= n; ++i)
		res = std::max(res, f[i]);
	std::cout << res;
	return 0;
}