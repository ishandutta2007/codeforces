#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, k, r, Head[N], T[N], Deg[N], Ans[N], Id[N];

struct Edge
{
	int next, node;
}h[N << 1];

inline void addedge(int u, int v)
{
	static int tot = 1;
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v;
	h[++ tot].next = Head[v], Head[v] = tot;
	h[tot].node = u;
}

void dfs(int z, int in)
{
	Id[Ans[in >> 1]] = z;
	for (int i = Head[z], last = 1; i; i = h[i].next)
	{
		if (i == (in ^ 1)) continue ;
		int d = h[i].node, id = i >> 1;
		for (Ans[id] = last; Deg[z] <= r && Id[Ans[id]] == z; Ans[id] ++) ;
		last = Ans[id], Id[Ans[id]] = z;
	}
	for (int i = Head[z]; i; i = h[i].next)
	{
		if (i == (in ^ 1)) continue ;
		dfs(h[i].node, i);
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1, u, v; i < n; i ++)
	{
		scanf("%d%d", &u, &v);
		addedge(u, v);
		Deg[u] ++, Deg[v] ++;
	}
	for (int i = 1; i <= n; i ++)
		T[Deg[i]] ++;
	for (int i = n - 1; i; i --)
		T[i] += T[i + 1];
	for (r = n; T[r] <= k; r --) ;
	dfs(1, 0);
	printf("%d\n", r);
	for (int i = 1; i < n; i ++)
		printf("%d%c", Ans[i], i == n - 1 ? '\n' : ' ');
	return 0;
}