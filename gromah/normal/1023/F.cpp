#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 500000 + 5
#define INF 0x3f3f3f3f

int n, k, m, tot, Fa[N], Pre[N], Dep[N], E[N][2], _E[N][3], Head[N], W[N];
bool Flag[N];
LL ans;

struct Edge
{
	int next, node, w;
}h[N << 1];

int Find(int x)
{
	return x == Fa[x] ? x : Fa[x] = Find(Fa[x]);
}

inline void addedge(int u, int v, int w)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v, h[tot].w = w;
}

void dfs(int z)
{
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node, w = h[i].w;
		if (d != Pre[z])
		{ 
			W[d] = w, Dep[d] = Dep[z] + 1, Pre[d] = z;
			dfs(d);
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= n; i ++)
		Fa[i] = i, Dep[i] = 1;
	for (int i = 1; i <= k; i ++)
	{
		scanf("%d%d", E[i], E[i] + 1);
		int u = Find(E[i][0]), v = Find(E[i][1]);
		if (Find(u) != Find(v))
		{
			if (Dep[u] > Dep[v]) swap(u, v);
			Fa[u] = v, Dep[v] = max(Dep[v], Dep[u] + 1);
			addedge(E[i][0], E[i][1], INF), addedge(E[i][1], E[i][0], INF);
		}
	}
	for (int i = 1; i <= m; i ++)
		scanf("%d%d%d", _E[i], _E[i] + 1, _E[i] + 2);
	for (int x = 1; x <= m; x ++)
	{
		int u = Find(_E[x][0]), v = Find(_E[x][1]), w = _E[x][2];
		if (Find(u) != Find(v))
		{
			if (Dep[u] > Dep[v]) swap(u, v);
			Fa[u] = v, Dep[v] = max(Dep[v], Dep[u] + 1);
			addedge(_E[x][0], _E[x][1], w), addedge(_E[x][1], _E[x][0], w);
			Flag[x] = 1;
		}
	}
	for (int i = 1; i <= n; i ++)
		Dep[i] = 0, Fa[i] = i;
	dfs(1);
	for (int i = 1; i <= m; i ++)
		if (!Flag[i])
			for (int u = Find(_E[i][0]), v = Find(_E[i][1]); u != v; u = Fa[u])
			{
				if (Dep[u] < Dep[v]) swap(u, v);
				W[u] = min(W[u], _E[i][2]);
				Fa[u] = Find(Pre[u]);
			}
	for (int i = 1; ~ans && i <= k; i ++)
	{
		int u = E[i][0], v = E[i][1];
		if (Dep[u] < Dep[v]) swap(u, v);
		if (W[u] == INF) ans = -1;
		else ans += W[u];
	}
	printf("%lld\n", ans);
	return 0;
}