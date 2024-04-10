#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5

int n, m, tot, Vec[N][3], Head[N], Col[N];
bool ok = 1, Flag[N];

struct Edge
{
	int next, node;
	bool w;
}h[N << 1];

inline void addedge(int u, int v, int w)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v, h[tot].w = w;
}

inline bool dfs(int z, int col)
{
	if (Col[z] == col) return 1;
	else if (Col[z]) return 0;
	Col[z] = col;
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node, w = h[i].w;
		if (!w && !dfs(d, col ^ 1)) return 0;
		if (w && !dfs(d, col)) return 0;
	}
	return 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%d", Flag + i);
	for (int i = 1, k; i <= m; i ++)
	{
		scanf("%d", &k);
		for (int j = 1, x; j <= k; j ++)
		{
			scanf("%d", &x);
			Vec[x][++ Vec[x][0]] = i;
		}
	}
	for (int i = 1; i <= n; i ++)
	{
		addedge(Vec[i][1], Vec[i][2], Flag[i]);
		addedge(Vec[i][2], Vec[i][1], Flag[i]);
	}
	for (int i = 1; ok && i <= m; i ++)
		if (!Col[i]) ok = dfs(i, 2);
	puts(ok ? "YES" : "NO");
	return 0;
}