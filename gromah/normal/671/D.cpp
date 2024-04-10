#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 300000 + 5
#define M 1048576 + 5
#define INF 300000000000000LL
#define mp make_pair
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, m, tot, depth, Head[N], Fa[N], Dfn[N], T[N], L[N], R[N], Cur[N];
int Max[M], Pos[M]; // For segment_tree
LL ans, Dp[N];

struct Edge
{
	int next, node;
}h[N << 1];

struct Segment_Tree
{
	LL Min, del_0, del_1;
}Tree[M];

struct Node
{
	int end, val;
	Node (int _end = 0, int _val = 0) {end = _end, val = _val;}
	bool operator < (const Node a) const
	{
		return mp(val, end) < mp(a.val, a.end);
	}
};

vector <Node> Vec[N];

inline void addedge(int u, int v)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v;
}

inline void dfs_index(int z)
{
	T[++ depth] = z;
	L[z] = depth;
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		if (d == Fa[z]) continue ;
		Fa[d] = z;
		Dfn[d] = Dfn[z] + 1;
		dfs_index(d);
	}
	R[z] = depth;
}

inline void update_Max(int x)
{
	Max[x] = max(Max[ls(x)], Max[rs(x)]);
	Pos[x] = Max[ls(x)] > Max[rs(x)] ? Pos[ls(x)] : Pos[rs(x)];
}

inline void Build_Max(int x, int l, int r)
{
	Max[x] = 0, Pos[x] = T[l];
	if (l == r) return ;
	int mid = l + r >> 1;
	Build_Max(ls(x), l, mid);
	Build_Max(rs(x), mid + 1, r);
	update_Max(x);
}

inline void Modify_Max(int x, int l, int r, int t, int k)
{
	if (l == r)
	{
		Max[x] = k;
		return ;
	}
	int mid = l + r >> 1;
	if (t <= mid) Modify_Max(ls(x), l, mid, t, k);
	else Modify_Max(rs(x), mid + 1, r, t, k);
	update_Max(x);
}

inline int Query_Max(int x, int l, int r, int s, int t, int &pos)
{
	if (l == s && r == t)
	{
		pos = Pos[x];
		return Max[x];
	}
	int mid = l + r >> 1;
	if (t <= mid) return Query_Max(ls(x), l, mid, s, t, pos);
	else if (s > mid) return Query_Max(rs(x), mid + 1, r, s, t, pos);
	else
	{
		int pos_1, pos_2, res_1, res_2;
		res_1 = Query_Max(ls(x), l, mid, s, mid, pos_1);
		res_2 = Query_Max(rs(x), mid + 1, r, mid + 1, t, pos_2);
		if (res_1 > res_2) pos = pos_1;
		else res_1 = res_2, pos = pos_2;
		return res_1;
	}
}

inline void Build(int x, int l, int r)
{
	Tree[x].Min = INF;
	if (l == r) return ;
	int mid = l + r >> 1;
	Build(ls(x), l, mid);
	Build(rs(x), mid + 1, r);
}

inline void update(int x)
{
	Tree[x].Min = min(Tree[ls(x)].Min, Tree[rs(x)].Min);
}

inline void apply(int x, LL k, int op)
{
	if (!op)
	{
		Tree[x].Min = k;
		Tree[x].del_0 = k;
		Tree[x].del_1 = 0;
	}
	else
	{
		Tree[x].Min += k;
		Tree[x].del_1 += k;
	}
}

inline void push(int x)
{
	if (Tree[x].del_0)
	{
		apply(ls(x), Tree[x].del_0, 0);
		apply(rs(x), Tree[x].del_0, 0);
		Tree[x].del_0 = 0;
	}
	if (Tree[x].del_1)
	{
		apply(ls(x), Tree[x].del_1, 1);
		apply(rs(x), Tree[x].del_1, 1);
		Tree[x].del_1 = 0;
	}
}

inline void Modify(int x, int l, int r, int s, int t, LL k, int op)
{
	if (l == s && r == t)
	{
		apply(x, k, op);
		return ;
	}
	push(x);
	int mid = l + r >> 1;
	if (t <= mid) Modify(ls(x), l, mid, s, t, k, op);
	else if (s > mid) Modify(rs(x), mid + 1, r, s, t, k, op);
	else Modify(ls(x), l, mid, s, mid, k, op), Modify(rs(x), mid + 1, r, mid + 1, t, k, op);
	update(x);
}

inline LL Query(int x, int l, int r, int s, int t)
{
	if (l == s && r == t) return Tree[x].Min;
	push(x);
	int mid = l + r >> 1;
	if (t <= mid) return Query(ls(x), l, mid, s, t);
	else if (s > mid) return Query(rs(x), mid + 1, r, s, t);
	else return min(Query(ls(x), l, mid, s, mid), Query(rs(x), mid + 1, r, mid + 1, t));
}

inline void dfs_Dp(int z)
{
	LL Sum_Dp = 0;
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		if (d == Fa[z]) continue ;
		dfs_Dp(d);
		Sum_Dp += Dp[d];
	}
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		if (d == Fa[z]) continue ;
		Modify(1, 1, n, L[d], R[d], min(Sum_Dp - Dp[d], INF), 1);
	}
	if (Vec[z].size())
	{
		Modify_Max(1, 1, n, L[z], Dfn[Vec[z][0].end]);
		Modify(1, 1, n, L[z], L[z], min(Sum_Dp + Vec[z][0].val, INF), 0);
	}
	int pos, tmp = Query_Max(1, 1, n, L[z], R[z], pos);
	while (tmp == Dfn[z])
	{
		int last = Cur[pos];
		for (Cur[pos] ++; Cur[pos] < Vec[pos].size() && Dfn[Vec[pos][Cur[pos]].end] >= Dfn[z]; Cur[pos] ++) ;
		if (Cur[pos] >= Vec[pos].size())
		{
			Modify_Max(1, 1, n, L[pos], 0);
			Modify(1, 1, n, L[pos], L[pos], INF, 0);
		}
		else
		{
			Modify_Max(1, 1, n, L[pos], Dfn[Vec[pos][Cur[pos]].end]);
			Modify(1, 1, n, L[pos], L[pos], Vec[pos][Cur[pos]].val - Vec[pos][last].val, 1);
		}
		tmp = Query_Max(1, 1, n, L[z], R[z], pos);
	}
	Dp[z] = min(Query(1, 1, n, L[z], R[z]), INF);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v; i < n; i ++)
	{
		scanf("%d%d", &u, &v);
		addedge(u, v), addedge(v, u);
	}
	for (int i = 1, u, v, c; i <= m; i ++)
	{
		scanf("%d%d%d", &u, &v, &c);
		Vec[u].push_back(Node(v, c));
	}
	for (int i = 1; i <= n; i ++)
		sort(Vec[i].begin(), Vec[i].end());
	dfs_index(1);
	Build_Max(1, 1, n);
	Build(1, 1, n);
	for (int i = Head[1]; i && ans < INF; i = h[i].next)
	{
		int d = h[i].node;
		dfs_Dp(d);
		ans += Dp[d];
	}
	if (ans < INF)
		printf("%I64d\n", ans);
	else puts("-1");
	return 0;
}