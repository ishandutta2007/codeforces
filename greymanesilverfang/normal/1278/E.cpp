#include <cstdio>
#include <vector>
const int N = 6e5;
std::vector<int> adj[N];
struct dat {
	int l, r;
} res[N];

void dfs(int u, int p, int l, int &r)
{
	r += adj[u].size();
	res[u] = {l, r};
	l = r;
	for (int v : adj[u])
		if (v != p)
			dfs(v, u, --l, r);
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int cur = 2;
	dfs(1, 0, 1, cur);
	for (int i = 1; i <= n; ++i)
		printf("%d %d\n", res[i].l, res[i].r);
}