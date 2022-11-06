#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define M 262144 + 5
#define INF 9000000000000000000LL
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, m, A[N], K[N];
LL Sum[N], TSum[N];

struct SegTree
{
	LL l, r, del, sum;
}h[M];

inline void update(int x)
{
	h[x].sum = h[ls(x)].sum + h[rs(x)].sum;
	h[x].l = h[ls(x)].l, h[x].r = h[rs(x)].r;
}

void Build(int x, int l, int r)
{
	h[x].del = INF;
	if (l == r)
	{
		h[x].sum = h[x].l = h[x].r = A[l];
		return ;
	}
	int mid = l + r >> 1;
	Build(ls(x), l, mid);
	Build(rs(x), mid + 1, r);
	update(x);
}

inline void apply(int x, int l, int r, LL fix)
{
	h[x].l = fix, h[x].r = fix + Sum[r - 1] - Sum[l - 1];
	h[x].del = fix;
	h[x].sum = fix * (r - l + 1) + TSum[r - 1] - TSum[l - 1] - (n - r) * (Sum[r - 1] - Sum[l - 1]);
}

inline void push(int x, int l, int r)
{
	if (h[x].del != INF)
	{
		int mid = l + r >> 1;
		apply(ls(x), l, mid, h[x].del);
		apply(rs(x), mid + 1, r, h[x].del + Sum[mid] - Sum[l - 1]);
		h[x].del = INF;
	}
}

void Modify(int x, int l, int r, int s, int t, LL fix)
{
	if (l == r)
	{
		if (h[x].l < fix)
			apply(x, l, r, fix);
		return ;
	}
	push(x, l, r);
	int mid = l + r >> 1;
	if (l == s && r == t)
	{
		if (h[x].l >= fix) return ;
		else if (h[x].r <= fix + Sum[r - 1] - Sum[l - 1])
		{
			apply(x, l, r, fix);
			return ;
		}
		else Modify(ls(x), l, mid, s, mid, fix), Modify(rs(x), mid + 1, r, mid + 1, t, fix + Sum[mid] - Sum[l - 1]);
	}
	else
	{
		if (t <= mid)
			Modify(ls(x), l, mid, s, t, fix);
		else if (s > mid)
			Modify(rs(x), mid + 1, r, s, t, fix);
		else Modify(ls(x), l, mid, s, mid, fix), Modify(rs(x), mid + 1, r, mid + 1, t, fix + Sum[mid] - Sum[s - 1]);
	}
	update(x);
}

LL Query(int x, int l, int r, int s, int t)
{
	if (l == s && r == t)
		return h[x].sum;
	push(x, l, r);
	int mid = l + r >> 1;
	if (t <= mid)
		return Query(ls(x), l, mid, s, t);
	else if (s > mid)
		return Query(rs(x), mid + 1, r, s, t);
	else return Query(ls(x), l, mid, s, mid) + Query(rs(x), mid + 1, r, mid + 1, t);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1; i < n; i ++)
	{
		scanf("%d", K + i);
		Sum[i] = Sum[i - 1] + K[i];
		TSum[i] = TSum[i - 1] + 1LL * K[i] * (n - i);
	}
	Build(1, 1, n);
	scanf("%d", &m);
	for (int i = 1, a, b; i <= m; i ++)
	{
		char ch;
		scanf("\n%c %d %d", &ch, &a, &b);
		if (ch == '+')
			Modify(1, 1, n, a, n, Query(1, 1, n, a, a) + b);
		else printf("%lld\n", Query(1, 1, n, a, b));
	}
	return 0;
}