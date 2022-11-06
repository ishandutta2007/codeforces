#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define M 200000
#define D 524288 + 5
#define E 5000000 + 5
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, tot, Head[N], Min[N][2], Max[N][2], Point[N << 2][2];
LL ans;

struct Edge
{
	int next, node;
}h[E];

struct Segment_Tree
{
	int Min, del;
	LL Sum;
}Tree[D];

inline void addedge(int u, int v)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v;
}

inline void Prepare()
{
	for (int i = 1; i <= M; i ++)
		for (int j = i; j <= M; j += i)
			addedge(j, i);
}

inline void Update(int u, int pos)
{
	if (!Min[u][0]) Min[u][0] = pos;
	else if (!Min[u][1]) Min[u][1] = pos;
	Max[u][1] = Max[u][0], Max[u][0] = pos;
}

inline void update(int x)
{
	Tree[x].Sum = Tree[ls(x)].Sum + Tree[rs(x)].Sum;
	Tree[x].Min = Tree[ls(x)].Min;
}

inline void Build(int x, int l, int r)
{
	Tree[x].del = 0;
	Tree[x].Sum = 1LL * (l + r - 2) * (r - l + 1) / 2;
	Tree[x].Min = l - 1;
	if (l == r) return ;
	int mid = l + r >> 1;
	Build(ls(x), l, mid);
	Build(rs(x), mid + 1, r);
	update(x);
}

inline int Find(int x, int l, int r, int k)
{
	if (l == r) return l;
	int mid = l + r >> 1;
	if (Tree[rs(x)].Min >= k)
		return Find(ls(x), l, mid, k);
	else return Find(rs(x), mid + 1, r, k);
}

inline void apply(int x, int l, int r, int k)
{
	Tree[x].Sum = 1LL * (r - l + 1) * k;
	Tree[x].Min = k;
	Tree[x].del = k;
}

inline void push(int x, int l, int r)
{
	if (Tree[x].del)
	{
		int mid = l + r >> 1;
		apply(ls(x), l, mid, Tree[x].del);
		apply(rs(x), mid + 1, r, Tree[x].del);
		Tree[x].del = 0;
	}
}

inline void Modify(int x, int l, int r, int s, int t, int k)
{
	if (l == s && r == t)
	{
		apply(x, l, r, k);
		return ;
	}
	push(x, l, r);
	int mid = l + r >> 1;
	if (t <= mid) Modify(ls(x), l, mid, s, t, k);
	else if (s > mid) Modify(rs(x), mid + 1, r, s, t, k);
	else Modify(ls(x), l, mid, s, mid, k), Modify(rs(x), mid + 1, r, mid + 1, t, k);
	update(x);
}

inline LL Query(int x, int l, int r, int s, int t)
{
	if (l == s && r == t) return Tree[x].Sum;
	push(x, l, r);
	int mid = l + r >> 1;
	if (t <= mid) return Query(ls(x), l, mid, s, t);
	else if (s > mid) return Query(rs(x), mid + 1, r, s, t);
	else return Query(ls(x), l, mid, s, mid) + Query(rs(x), mid + 1, r, mid + 1, t);
}

inline void Solve(int l, int r, int val)
{
	if (l > r) return ;
	if (Tree[1].Min >= r) return ;
	int t = Find(1, 1, n, r);
	if (t < l) return ;
	ans += (1LL * (t - l + 1) * r - Query(1, 1, n, l, t)) * val;
	Modify(1, 1, n, l, t, r);
}

int main()
{
	Prepare();
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i ++)
	{
		scanf("%d", &x);
		for (int j = Head[x]; j; j = h[j].next)
		{
			int d = h[j].node;
			Update(d, i);
		}
	}
	Build(1, 1, n);
	for (int i = M; i; i --)
	{
		if (!Min[i][1]) continue ;
		Solve(Min[i][1] + 1, n, i);
		Solve(Min[i][0] + 1, Max[i][0] - 1, i);
		Solve(1, Max[i][1] - 1, i);
	}
	printf("%I64d\n", ans);
	return 0;
}