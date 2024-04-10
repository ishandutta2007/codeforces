#include <cstdio>
#include <algorithm>
#include <vector>
const int N = 3001;
int val[N];
std::vector<int> adj[N];
struct dat 
{
	int cnt; long long max;
	bool operator < (const dat &other) const 
	{
		if (cnt != other.cnt)
			return cnt < other.cnt;
		return max < other.max;
	}
};
const dat MIN = {-1, 0};
int sz[N];
dat dp[N][N];

void maxi(dat &x, const dat &y)
{
	if (x < y) x = y;
}

void dfs(int u, int p)
{
	sz[u] = 1;
	dp[u][0] = {0, val[u]};
	for (int v : adj[u])
		if (v != p)
		{
			dfs(v, u);
			for (int i = sz[u]; i--;)
			{
				dat du = dp[u][i];
				dp[u][i] = MIN;
				for (int j = 0; j < sz[v]; ++j)
				{
					dat dv = dp[v][j];
					maxi(dp[u][i + j], {du.cnt + dv.cnt, du.max + dv.max});
					maxi(dp[u][i + j + 1], {du.cnt + dv.cnt + (dv.max > 0), du.max});
				}
			}
			sz[u] += sz[v];
		}
}

int solve()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		val[i] = 0;
		adj[i].clear();
		std::fill(dp[i], dp[i] + n, MIN);
	}
	for (int i = 1; i <= n; ++i)
	{
		int b; scanf("%d", &b);
		val[i] -= b;
	}
	for (int i = 1; i <= n; ++i)
	{
		int w; scanf("%d", &w);
		val[i] += w;
	}
	for (int i = 1; i < n; ++i)
	{
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	dat res = dp[1][m - 1];
	return res.cnt + (res.max > 0);
}

int main()
{
	int t; scanf("%d", &t);
	for (int i = 0; i < t; ++i)
		printf("%d\n", solve());
}