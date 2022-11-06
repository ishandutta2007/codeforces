#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define LOGN 19

int n, m, s, tot, rem, add, W[N], C[N], Ord[N], E[N][2], Fa[N], Head[N], q[N], Dfn[N], Log[N], An[N][LOGN], Max[N][LOGN];
bool Flag[N];
LL Min, Sum;

struct Edge
{
	int next, node, w, id;
}h[N << 1];

inline bool cmp(int u, int v)
{
	return W[u] < W[v];
}

inline int Find(int x)
{
	return x == Fa[x] ? x : Fa[x] = Find(Fa[x]);
}

inline void addedge(int u, int v, int w, int id)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v, h[tot].w = w, h[tot].id = id;
	h[++ tot].next = Head[v], Head[v] = tot;
	h[tot].node = u, h[tot].w = w, h[tot].id = id;
}

inline void dfs(int z)
{
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node, w = h[i].w, id = h[i].id;
		if (d == An[z][0]) continue ;
		An[d][0] = z, Max[d][0] = id, Dfn[d] = Dfn[z] + 1;
		for (int j = 1, x = z; An[x][j - 1]; x = An[x][j - 1], j ++)
		{
			An[d][j] = An[x][j - 1];
			Max[d][j] = W[Max[d][j - 1]] > W[Max[x][j - 1]] ? Max[d][j - 1] : Max[x][j - 1];
		}
		dfs(d);
	}
}

inline int Get_Max(int u, int v)
{
	if (Dfn[u] < Dfn[v]) swap(u, v);
	int res = 0;
	for (int t = Dfn[u] - Dfn[v]; t; t -= (t & -t))
	{
		int d = Log[t & -t];
		if (!res || W[res] < W[Max[u][d]])
			res = Max[u][d];
		u = An[u][d];
	}
	if (u == v) return res;
	for (int i = LOGN - 1; An[u][0] != An[v][0]; i --)
	{
		if (An[u][i] == An[v][i]) continue ;
		if (!res || W[res] < W[Max[u][i]])
			res = Max[u][i];
		if (!res || W[res] < W[Max[v][i]])
			res = Max[v][i];
		u = An[u][i], v = An[v][i];
	}
	if (!res || W[res] < W[Max[u][0]])
		res = Max[u][0];
	if (!res || W[res] < W[Max[v][0]])
		res = Max[v][0];
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++)
	{
		scanf("%d", W + i);
		Ord[i] = i;
	}
	for (int i = 1; i <= m; i ++)
		scanf("%d", C + i);
	for (int i = 1; i <= m; i ++)
		scanf("%d%d", E[i], E[i] + 1);
	scanf("%d", &s);
	sort(Ord + 1, Ord + m + 1, cmp);
	for (int i = 1; i <= n; i ++)
	{
		Fa[i] = i;
		if (i > 1) Log[i] = Log[i >> 1] + 1;
	}
	for (int i = 1; i <= m; i ++)
	{
		int u = E[Ord[i]][0], v = E[Ord[i]][1], w = W[Ord[i]];
		u = Find(u), v = Find(v);
		if (u == v) continue ;
		Fa[u] = v, Sum += w;
		Flag[Ord[i]] = 1;
		addedge(u, v, w, Ord[i]);
		q[++ q[0]] = Ord[i];
	}
	dfs(1);
	Min = Sum;
	for (int i = 1; i <= m; i ++)
	{
		int u = E[i][0], v = E[i][1], w = W[i] - s / C[i];
		int t = Flag[i] ? i : Get_Max(u, v);
		LL tmp = Sum - W[t] + w;
		if (tmp < Min)
			Min = tmp, rem = t, add = i;
	}
	printf("%I64d\n", Min);
	for (int i = 1; i <= q[0]; i ++)
	{
		if (q[i] == rem) continue ;
		printf("%d %d\n", q[i], W[q[i]]);
	}
	if (add) printf("%d %d\n", add, W[add] - s / C[add]);
	return 0;
}