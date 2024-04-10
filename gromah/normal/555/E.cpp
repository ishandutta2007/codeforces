#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define LOGN 18

int n, m, q, tot = 1, Head[N], _Head[N], Col[N], Fa[N], An[N], _An[N], Dep[N], _Fa[2][N], STL[N][LOGN], Log[N];

struct Edge
{
	int next, node;
	bool flag;
}h[N << 1], Tree[N];

inline void addedge(Edge *E, int *head, int u, int v)
{
	E[++ tot].next = head[u], head[u] = tot;
	E[tot].node = v;
}

inline void dfs(int z, int col)
{
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		if (Col[d] == col) continue ;
		Col[d] = col;
		Fa[d] = z, Dep[d] = Dep[z] + 1;
		h[i].flag = h[i ^ 1].flag = 1;
		dfs(d, col);
	}
}

inline void DFS(int z, int fa)
{
	for (int i = Head[z]; i; i = h[i].next)
	{
		if (!h[i].flag) continue ;
		int d = h[i].node;
		if (d == fa) continue ;
		if (d == _An[d])
		{
			STL[d][0] = _An[z], Dep[d] = Dep[_An[z]] + 1;
			addedge(Tree, _Head, _An[z], d);
		}
		for (int x = _An[z], j = 0; STL[x][j]; x = STL[x][j ++])
			STL[d][j + 1] = STL[x][j];
		DFS(d, z);
	}
}

inline int Find(int x)
{
	return x == An[x] ? x : An[x] = Find(An[x]);
}

inline int Find(int op, int x)
{
	return x == _Fa[op][x] ? x : _Fa[op][x] = Find(op, _Fa[op][x]);
}

inline void Union(int u, int v)
{
	if (Dep[u] < Dep[v]) swap(u, v);
	for (u = Find(u); Dep[u] > Dep[v]; u = Find(Fa[u]))
		An[u] = Find(Fa[u]);
}

inline int LCA(int u, int v)
{
	if (Dep[u] < Dep[v]) swap(u, v);
	for (int t = Dep[u] - Dep[v]; t; t -= (t & -t))
	{
		int d = Log[t & -t];
		u = STL[u][d];
	}
	if (u == v) return u;
	for (int i = LOGN - 1; STL[u][0] != STL[v][0]; i --)
		if (STL[u][i] != STL[v][i])
		{
			u = STL[u][i];
			v = STL[v][i];
		}
	return STL[u][0];
}

inline void Modify(int u, int v, int op)
{
	for (u = Find(op, u); Dep[u] > Dep[v]; u = Find(op, STL[u][0]))
		_Fa[op][u] = Find(op, STL[u][0]);
}

int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1, u, v; i <= m; i ++)
	{ 
		scanf("%d%d", &u, &v);
		addedge(h, Head, u, v), addedge(h, Head, v, u);
	}
	for (int i = 1; i <= n; i ++)
	{
		if (Col[i]) continue ;
		Col[i] = i, Dep[i] = 1;
		dfs(i, i);
	}
	for (int i = 1; i <= n; i ++)
	{
		An[i] = i;
		if (i > 1) Log[i] = Log[i >> 1] + 1;
	}
	for (int i = 2; i <= tot; i += 2)
	{
		if (h[i].flag) continue ;
		Union(h[i].node, h[i ^ 1].node);
	}
	tot = 0;
	for (int i = 1; i <= n; i ++)
	{
		_An[i] = Find(i);
		_Fa[0][i] = _Fa[1][i] = i;
	}
	for (int i = 1; i <= n; i ++)
	{
		if (Col[i] != i) continue ;
		Dep[i] = 1;
		DFS(i, 0);
	}
	bool ok = 1;
	for (int i = 1, u, v; ok && i <= q; i ++)
	{
		scanf("%d%d", &u, &v);
		if (Col[u] != Col[v]) ok = 0;
		u = _An[u], v = _An[v];
		int lca = LCA(u, v);
		Modify(u, lca, 0);
		Modify(v, lca, 1);
	}
	for (int i = 1; ok && i <= n; i ++)
	{
		if (i != _An[i]) continue ;
		int u = Find(0, i), v = Find(1, i);
		if (u != i && v != i) ok = 0;
	}
	puts(ok ? "Yes" : "No");
	return 0;
}