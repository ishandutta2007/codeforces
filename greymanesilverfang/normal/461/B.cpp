// #dp #tree

#include <cstdio>
#include <vector>
const int N = 1e5+1, INF = 1e9+7;
int x[N], cnt[N];
long long f[N], g[N];
std::vector<int> adj[N];

void DFS(int u = 0)
{
	cnt[u] = x[u];
	for (int v : adj[u])
	{
		DFS(v);
		cnt[u] += cnt[v];
	}
	if (cnt[u] == 0)
	{
		f[u] = 1;
		g[u] = 0;
		return;
	}
	if (x[u] == 0)
	{
		f[u] = 1;
		for (int v : adj[u])
			(f[u] *= f[v] + g[v]) %= INF;
		long long tmp = 1;
		g[u] = 1;
		for (int v : adj[u])
		{
			(g[u] *= f[v] + g[v]) %= INF;
			(g[u] += g[v] * tmp ) %= INF;
			(tmp  *= f[v] + g[v]) %= INF;
		}
		(g[u] += INF - tmp) %= INF;
	}
	if (x[u] == 1)
	{
		f[u] = 0;
		g[u] = 1;
		for (int v : adj[u])
			(g[u] *= f[v] + g[v]) %= INF;
	}
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int p; scanf("%d", &p);
		adj[p].push_back(i);
	}
	for (int i = 0; i < n; ++i)
		scanf("%d", &x[i]);
	DFS();
	printf("%lld", g[0]);
	return 0;
}