#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 500000 + 5

int Case, n, k, tot, Head[N], Deg[N];
bool Vis[N];
LL ans, Dp[N][2];
vector<LL> Vec[N];

struct Edge
{
	int next, node, w;
}h[N << 1];

inline void addedge(int u, int v, int w)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v, h[tot].w = w;
}

void dfs(int z, int fa, int in, int rt)
{
	Vis[z] = 1;
	LL val = 0;
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node, w = h[i].w;
		if (d != fa)
		{
			if (Deg[d] > k)
			{
				dfs(d, z, i, rt);
				val += Dp[d][0];
				Vec[z].push_back(Dp[d][1] - Dp[d][0]);
			}
			else Vec[z].push_back(w);
		}
	}
	if (z != rt)
		Vec[z].push_back(h[in].w);
	sort(Vec[z].begin(), Vec[z].end());
	Dp[z][0] = val;
	for (int i = 0; i + k < Deg[z]; i ++)
		Dp[z][0] += Vec[z][i];
	if (z != rt)
	{
		if (h[in].w <= Vec[z][Deg[z] - k - 1])
			Dp[z][1] = Dp[z][0];
		else
		{
			Dp[z][1] = val + h[in].w;
			for (int i = 0; i + k < Deg[z] - 1; i ++)
				Dp[z][1] += Vec[z][i];
		}
	}
}

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d%d", &n, &k);
		ans = tot = 0;
		for (int i = 1; i <= n; i ++)
		{
			Head[i] = Deg[i] = Vis[i] = 0;
			Vec[i].clear();
		}
		for (int i = 1, u, v, w; i < n; i ++)
		{
			scanf("%d%d%d", &u, &v, &w);
			addedge(u, v, w);
			addedge(v, u, w);
			Deg[u] ++, Deg[v] ++;
			ans += w;
		}
		for (int i = 1; i <= n; i ++)
			if (Deg[i] > k && !Vis[i])
			{
				dfs(i, 0, 0, i);
				ans -= Dp[i][0];
			}
		printf("%lld\n", ans);
	}
	return 0;
}