#include <cstdio>
#include <vector>
const int N = 3e5;
std::vector<int> adj[N];
int cnt[2];

void dfs(int u, int color = 0, int p = 0)
{
	++cnt[color];
	for (int v : adj[u])
		if (v != p)
			dfs(v, color ^ 1, u);
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
	dfs(1);
	printf("%d\n", std::min(cnt[0], cnt[1]) - 1);
}