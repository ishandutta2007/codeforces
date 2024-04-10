#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5
#define INF 0x7fffffff

int n, m, w, ans, Fa[N], W[N], V[N], Tot_W[N], Tot_V[N], Dp[2][N];
bool Flag[N];

inline int Find(int x)
{
	return Fa[x] == x ? x : Fa[x] = Find(Fa[x]);
}

int main()
{
	scanf("%d%d%d", &n, &m, &w);
	for (int i = 1; i <= n; i ++)
		scanf("%d", W + i);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", V + i);
		Fa[i] = i, Tot_W[i] = W[i], Tot_V[i] = V[i];
	}
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		u = Find(u), v = Find(v);
		if (u == v) continue ;
		Fa[u] = v;
		Tot_W[v] += Tot_W[u], Tot_W[u] = 0;
		Tot_V[v] += Tot_V[u], Tot_V[u] = 0;
	}
	for (int i = 0; i <= w; i ++)
		Dp[0][i] = Dp[1][i] = -INF;
	Dp[0][0] = Dp[1][0] = 0;
	for (int i = 1; i <= n; i ++) Fa[i] = Find(i);
	for (int i = 1; i <= n; i ++)
	{
		if (Flag[Fa[i]]) continue ;
		Flag[Fa[i]] = 1;
		for (int j = w; j >= Tot_W[Fa[i]]; j --)
			Dp[1][j] = max(Dp[1][j], Dp[0][j - Tot_W[Fa[i]]] + Tot_V[Fa[i]]);
		for (int k = 1; k <= n; k ++)
		{
			if (Fa[k] != Fa[i]) continue ;
			for (int j = w; j >= W[k]; j --)
				Dp[1][j] = max(Dp[1][j], Dp[0][j - W[k]] + V[k]);
		}
		for (int j = 0; j <= w; j ++)
			Dp[0][j] = Dp[1][j];
	}
	for (int i = 0; i <= w; i ++)
		ans = max(ans, Dp[0][i]);
	printf("%d\n", ans);
	return 0;
}