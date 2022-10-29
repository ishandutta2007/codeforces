#include <cstdio>
#include <cmath>
#include <vector>
const int N = 3e5;
int n;
struct edge {
	int v, w;
};
std::vector<edge> adj[N];
long long g, b;

int dfs(int u, int p)
{
	int res = 1;
	for (edge e : adj[u])
		if (e.v != p)
		{
			int tmp = dfs(e.v, u);
			res += tmp;
			if (tmp & 1)
				g += e.w;
			b += (long long) e.w * std::min(tmp, n - tmp);
		}
	return res;
}

int main()
{
	int t; scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		g = b = 0;
		scanf("%d", &n);
		n *= 2;
		for (int i = 1; i <= n; ++i)
			adj[i].clear();
		for (int i = 1; i < n; ++i)
		{
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}
		dfs(1, 0);
		printf("%lld %lld\n", g, b);
	}
}