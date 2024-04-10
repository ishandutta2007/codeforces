#include <cstdio>
#define N 100000 + 5

int n, m, tot, Head[N], Col[N];
bool ok = 1;
struct Edge
{
	int next, node;
}h[N << 1];

inline void addedge(int u, int v)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v;
	h[++ tot].next = Head[v], Head[v] = tot;
	h[tot].node = u;
}

inline void dfs(int z, int op)
{
	if (Col[z] && Col[z] != op) ok = 0;
	if (!ok || Col[z]) return ;
	Col[z] = op;
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		dfs(d, op * -1);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	for (int i = 1; ok && i <= n; i ++)
		if (!Col[i] && Head[i]) dfs(i, 1);
	if (!ok) puts("-1");
	else for (int k = -1; k <= 1; k += 2)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i ++)
			if (Col[i] == k) cnt ++;
		printf("%d\n", cnt);
		for (int i = 1; i <= n; i ++)
			if (Col[i] == k) printf("%d ", i);
		puts(""); 
	}
	return 0;
}