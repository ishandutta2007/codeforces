#include <cstdio>
#include <vector>
const int N = 3e5;
std::vector<int> adj[N];
int mark[N];

void dfs(int u, int x, int val)
{
	mark[u] += val;
	for (int v : adj[u])
		if (mark[v] < val && v != x)
			dfs(v, x, val);
}

long long solve()
{
	int n, m, a, b; scanf("%d%d%d%d", &n, &m, &a, &b);
	for (int i = 1; i <= n; ++i)
	{
		adj[i].clear();
		mark[i] = 0;
	}
	for (int i = 1; i <= m; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(a, b, 1);
	dfs(b, a, 2);
	long long cnt1 = -1, cnt2 = -1;
	for (int i = 1; i <= n; ++i)
	{
		// printf("mark %d %d\n", i, mark[i]);
		if (mark[i] == 1)
			++cnt1;
		if (mark[i] == 2)
			++cnt2;
	}
	return cnt1 * cnt2;
}

int main()
{
	int t; scanf("%d", &t);
	for (int i = 0; i < t; ++i)
		printf("%lld ", solve());
	printf("\n");
}