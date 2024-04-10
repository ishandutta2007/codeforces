#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 300000 + 5

int n, tot, W[N], Head[N];
LL ans, Max[N][2];

struct Edge
{
	int next, node, w;
}h[N << 1];

void addedge(int u, int v, int w)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v, h[tot].w = w;
}

void dfs(int z, int fa)
{
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node, w = h[i].w;
		if (d == fa) continue ;
		dfs(d, z);
		Max[z][1] = max(Max[z][1], Max[d][0] + W[d] - w);
		if (Max[z][1] > Max[z][0])
			swap(Max[z][0], Max[z][1]);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", W + i);
	for (int i = 1, u, v, w; i < n; i ++)
	{
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w);
		addedge(v, u, w);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i ++)
		ans = max(ans, W[i] + Max[i][0] + Max[i][1]);
	printf("%lld\n", ans);
	return 0;
}