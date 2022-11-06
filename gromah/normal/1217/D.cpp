#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define N 5000 + 5

int n, m, tot, mx, Head[N], Col[N];
bool Vis[N], Ins[N];

struct Edge
{
	int next, node;
}h[N];

void addedge(int u, int v)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v;
}

void dfs(int z)
{
	Vis[z] = 1, Ins[z] = 1;
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		if (!Vis[d])
			Col[i] = 1, dfs(d);
		else Col[i] = 1 + Ins[d];
		mx = max(mx, Col[i]);
	}
	Ins[z] = 0;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	for (int i = 1; i <= n; i ++)
		if (!Vis[i]) dfs(i);
	printf("%d\n", mx);
	for (int i = 1; i <= m; i ++)
		printf("%d%c", Col[i], i == m ? '\n' : ' ');
	return 0;
}