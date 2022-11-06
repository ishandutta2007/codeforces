#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair <LL, LL> Pii;
#define N 300000 + 5
#define M 1048576 + 5
#define LOGN 19
#define INF 8234567890987654321LL
#define mp make_pair
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, q, Head[N], Go[N][LOGN], Dep[N], Log[N], L[N], R[N], Ord[N];
LL T[N], A[N], W[N][LOGN][4];

struct Edge
{
	int next, node;
	LL a, b;
}h[N << 1];

struct SegTree
{
	LL del, Min;
}Tree[M];

inline void addedge(int u, int v, LL a, LL b)
{
	static int tot = 0;
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v, h[tot].a = a, h[tot].b = b;
}

void dfs(int z)
{
	static int ord = 0;
	Ord[++ ord] = z, L[z] = ord;
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		LL a = h[i].a, b = h[i].b;
		if (d == Go[z][0]) continue ;
		Go[d][0] = z, Dep[d] = Dep[z] + 1, A[d] = A[z] + a + b;
		for (int j = 1, x = z; Go[x][j - 1]; x = Go[x][j - 1], j ++)
			Go[d][j] = Go[x][j - 1];
		dfs(d);
	}
	R[z] = ord;
}

inline void update(int x)
{
	Tree[x].Min = min(Tree[ls(x)].Min, Tree[rs(x)].Min);
}

void Build(int x, int l, int r)
{
	Tree[x].del = 0;
	if (l == r)
	{
		Tree[x].Min = A[Ord[l]];
		return ;
	}
	int mid = l + r >> 1;
	Build(ls(x), l, mid);
	Build(rs(x), mid + 1, r);
	update(x);
}

inline void apply(int x, LL k)
{
	Tree[x].Min += k, Tree[x].del += k;
}

inline void push(int x)
{
	if (Tree[x].del)
	{
		apply(ls(x), Tree[x].del);
		apply(rs(x), Tree[x].del);
		Tree[x].del = 0;
	}
}

void Modify(int x, int l, int r, int s, int t, LL k)
{
	if (l == s && r == t)
	{
		apply(x, k);
		return ;
	}
	push(x);
	int mid = l + r >> 1;
	if (t <= mid)
		Modify(ls(x), l, mid, s, t, k);
	else if (s > mid)
		Modify(rs(x), mid + 1, r, s, t, k);
	else Modify(ls(x), l, mid, s, mid, k), Modify(rs(x), mid + 1, r, mid + 1, t, k);
	update(x);
}

void DFS(int z)
{
	A[z] = Tree[1].Min;
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		LL a = h[i].a, b = h[i].b;
		if (d == Go[z][0]) continue ;
		Modify(1, 1, n, 1, n, a + b);
		Modify(1, 1, n, L[d], R[d], -2 * (a + b));
		DFS(d);
		Modify(1, 1, n, 1, n, -(a + b));
		Modify(1, 1, n, L[d], R[d], 2 * (a + b));
	}
}

void Dfs(int z)
{
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		LL a = h[i].a, b = h[i].b;
		if (d == Go[z][0]) continue ;
		W[d][0][0] = a, W[d][0][3] = b, W[d][0][1] = A[d] + b, W[d][0][2] = A[d] + a;
		for (int j = 1, x = z; Go[x][j - 1]; x = Go[x][j - 1], j ++)
			for (int k = 0; k < 4; k ++)
			{
				W[d][j][k] = INF;
				for (int c = 0; c < 2; c ++)
					W[d][j][k] = min(W[d][j][k], W[d][j - 1][(k & 2) | c] + W[x][j - 1][(c << 1) | (k & 1)]);
			}
		Dfs(d);
	}
}

int LCA(int u, int v)
{
	if (Dep[u] < Dep[v])
		swap(u, v);
	for (int t = Dep[u] - Dep[v]; t; t -= (t & -t))
		u = Go[u][Log[t & -t]];
	if (u == v) return u;
	for (int i = LOGN - 1; Go[u][0] != Go[v][0]; i --)
		if (Go[u][i] != Go[v][i])
			u = Go[u][i], v = Go[v][i];
	return Go[u][0];
}

Pii Travel(int src, int t)
{
	static LL res[2];
	res[src + 1 & 1] = 0, res[src & 1] = A[src + 1 >> 1];
	for (int u = src + 1 >> 1; t; t -= (t & -t))
	{
		int k = Log[t & -t];
		LL a0 = min(res[0] + W[u][k][0], res[1] + W[u][k][2]);
		LL a1 = min(res[0] + W[u][k][1], res[1] + W[u][k][3]);
		res[0] = a0, res[1] = a1;
		u = Go[u][k];
	}
	return mp(res[0], res[1]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%lld", T + i);
	for (int i = 2, u, v; i <= n; i ++)
	{
		LL a, b;
		scanf("%d%d%lld%lld", &u, &v, &a, &b);
		addedge(u, v, a, b);
		addedge(v, u, a, b);
		Log[i] = Log[i >> 1] + 1;
	}
	dfs(1);
	for (int i = 1; i <= n; i ++)
		A[i] += T[i];
	Build(1, 1, n);
	DFS(1);
	Dfs(1);
	scanf("%d", &q);
	for (int i = 1, u, v; i <= q; i ++)
	{
		scanf("%d%d", &u, &v);
		int lca = LCA(u + 1 >> 1, v + 1 >> 1);
		Pii lhs = Travel(u, Dep[u + 1 >> 1] - Dep[lca]);
		Pii rhs = Travel(v, Dep[v + 1 >> 1] - Dep[lca]);
		LL tmp1 = min(lhs.first + rhs.first, lhs.second + rhs.second);
		LL tmp2 = min(lhs.first + rhs.second, lhs.second + rhs.first) + A[lca];
		printf("%lld\n", min(tmp1, tmp2));
	}
	return 0;
}