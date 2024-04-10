#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
const int N = 3e5;
int h[N], val[N];
std::vector<int> adj[N], dep[N];

int dfs(int u)
{
	if (!h[u])
	{
		for (int v : adj[u])
			h[u] = std::max(h[u], dfs(v));
		++h[u];
	}
	return h[u];
}

void solve()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		adj[i].clear();
		dep[i].clear();
		h[i] = val[i] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++i)
		dep[dfs(i)].push_back(i);
	std::vector<int> res;
	for (int i = n; i >= 1; --i)
		for (int x : dep[i])
		{
			if (!val[x])
			{
				--val[x];
				for (int y : adj[x])
				{
					if (!val[y])
					{
						--val[y];
						for (int z : adj[y])
							if (!++val[z])
							{
								val[z] = n;
								for (int t : adj[z])
									--val[t];
							}
					}
					if (~val[y])
						val[y] = n;
				}
			}
			if (~val[x])
				res.push_back(x);
		}
	printf("%u\n", res.size());
	for (int x : res)
		printf("%d ", x);
	printf("\n");
}

int main()
{
	int t; scanf("%d", &t);
	for (int i = 0; i < t; ++i)
		solve();
}