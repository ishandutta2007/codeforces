#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define M 18000000 + 5
#define LIM 200000000000000LL

int n, tot, depth, A[N], Fa[N], Head[N], L[N], R[N], Root[N], Ans[N];
LL Dis[N];

struct Edge
{
	int next, node, w;
}E[N];

struct Segment_Tree
{
	int l, r, sum;
}h[M];

inline void addedge(int u, int v, int w)
{
	E[++ tot].next = Head[u], Head[u] = tot;
	E[tot].node = v, E[tot].w = w;
}

inline void update(int x)
{
	h[x].sum = h[h[x].l].sum + h[h[x].r].sum;
}

inline void Modify(int &x, LL l, LL r, LL k)
{
	h[++ tot] = h[x];
	x = tot;
	if (l == r)
	{
		h[x].sum ++;
		return ;
	}
	LL mid = l + r >> 1;
	if (k <= mid) Modify(h[x].l, l, mid, k);
	else Modify(h[x].r, mid + 1, r, k);
	update(x);
}

inline int Query(int x, LL l, LL r, LL s, LL t)
{
	if (!x) return 0;
	if (l == s && r == t) return h[x].sum;
	LL mid = l + r >> 1;
	if (t <= mid) return Query(h[x].l, l, mid, s, t);
	else if (s > mid) return Query(h[x].r, mid + 1, r, s, t);
	else return Query(h[x].l, l, mid, s, mid) + Query(h[x].r, mid + 1, r, mid + 1, t);
}

inline void dfs(int z)
{
	L[z] = ++ depth;
	Modify(Root[depth] = Root[depth - 1], 0, LIM, max(Dis[z] - A[z], 0LL));
	for (int i = Head[z]; i; i = E[i].next)
	{
		int d = E[i].node, w = E[i].w;
		Dis[d] = Dis[z] + w;
		dfs(d);
	}
	R[z] = depth;
	Ans[z] = Query(Root[R[z]], 0, LIM, 0, Dis[z]) - Query(Root[L[z]], 0, LIM, 0, Dis[z]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 2, w; i <= n; i ++)
	{
		scanf("%d%d", Fa + i, &w);
		addedge(Fa[i], i, w);
	}
	tot = 0;
	dfs(1);
	for (int i = 1; i <= n; i ++)
		printf("%d%c", Ans[i], i == n ? '\n' : ' ');
	return 0;
}