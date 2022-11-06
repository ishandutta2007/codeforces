#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000000 + 5
#define M 1 << 21 | 5
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, k, sz, tot, A[N], Stack[N], L[N], R[N], Ord[N], Head[N], Dep[N], Ans[N];

struct Edge
{
	int next, node;
}h[N];

struct SegTree
{
	int del, Max;
}T[M];

inline void read(int &res)
{
	char ch = '\n';
	for (; ch < '0' || ch > '9'; ch = getchar()) ;
	res = ch - '0';
	for (ch = getchar(); ch >= '0' && ch <= '9'; ch = getchar())
		res = res * 10 + ch - '0';
}

inline void addedge(int u, int v)
{
	h[++ tot].next = Head[u], Head[u] = tot;
	h[tot].node = v;
}

void dfs(int z)
{
	static int ord = 0;
	L[z] = ++ ord, Ord[ord] = z;
	for (int i = Head[z]; i; i = h[i].next)
	{
		int d = h[i].node;
		Dep[d] = Dep[z] + 1;
		dfs(d);
	}
	R[z] = ord;
}

inline void update(int x)
{
	T[x].Max = max(T[ls(x)].Max, T[rs(x)].Max);
}

void Build(int x, int l, int r)
{
	T[x].del = 0;
	if (l == r)
	{
		T[x].Max = Ord[l] + k > n ? Dep[Ord[l]] : 0;
		return ;
	}
	int mid = l + r >> 1;
	Build(ls(x), l, mid);
	Build(rs(x), mid + 1, r);
	update(x);
}

inline void apply(int x, int k)
{
	T[x].Max += k, T[x].del += k;
}

inline void push(int x)
{
	if (T[x].del)
	{
		apply(ls(x), T[x].del);
		apply(rs(x), T[x].del);
		T[x].del = 0;
	}
}

void Modify(int x, int l, int r, int s, int t, int k)
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

int main()
{
	read(n), read(k);
	for (int i = 1; i <= n; i ++)
		read(A[i]);
	for (int i = n; i; i --)
	{
		for (; sz && A[Stack[sz]] <= A[i]; sz --) ;
		if (sz) addedge(Stack[sz], i);
		Stack[++ sz] = i;
	}
	for (int i = n; i; i --)
		if (!L[i])
			Dep[i] = 1, dfs(i);
	Build(1, 1, n);
	for (int i = n - k + 1; i; i --)
	{
		Ans[i] = T[1].Max;
		if (i > 1)
		{
			Modify(1, 1, n, L[i + k - 1], R[i + k - 1], -1);
			Modify(1, 1, n, L[i + k - 1], L[i + k - 1], -n);
			Modify(1, 1, n, L[i - 1], L[i - 1], Dep[i - 1]);
		}
	}
	for (int i = 1; i <= n - k + 1; i ++)
		printf("%d%c", Ans[i], i == n - k + 1 ? '\n' : ' ');
	return 0;
}