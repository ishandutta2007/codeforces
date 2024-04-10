#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 300000 + 5
#define M 1048576 + 5
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, m, A[N];

struct Segment_Tree
{
	LL l, r, del;
	int l_d, r_d, l_u, r_u, sz, Max;
}h[M];

inline void update(int x)
{
	h[x].l = h[ls(x)].l;
	h[x].r = h[rs(x)].r;
	if (h[ls(x)].l_d == h[ls(x)].sz && h[ls(x)].r > h[rs(x)].l)
		h[x].l_d = h[ls(x)].sz + h[rs(x)].l_d;
	else h[x].l_d = h[ls(x)].l_d;
	if (h[rs(x)].r_d == h[rs(x)].sz && h[rs(x)].l > h[ls(x)].r)
		h[x].r_d = h[rs(x)].sz + h[ls(x)].r_d;
	else h[x].r_d = h[rs(x)].r_d;
	if (h[ls(x)].l_u == h[ls(x)].sz)
	{
		if (h[ls(x)].r_d == h[ls(x)].sz)
		{
			if (h[ls(x)].r > h[rs(x)].l)
				h[x].l_u = h[ls(x)].sz + h[rs(x)].l_d;
			else if (h[ls(x)].r < h[rs(x)].l)
				h[x].l_u = h[ls(x)].sz + h[rs(x)].l_u;
			else h[x].l_u = h[ls(x)].sz;
		}
		else
		{
			if (h[ls(x)].r > h[rs(x)].l)
				h[x].l_u = h[ls(x)].sz + h[rs(x)].l_d;
			else h[x].l_u = h[ls(x)].sz;
		}
	}
	else h[x].l_u = h[ls(x)].l_u;
	if (h[rs(x)].r_u == h[rs(x)].sz)
	{
		if (h[rs(x)].l_d == h[rs(x)].sz)
		{
			if (h[rs(x)].l > h[ls(x)].r)
				h[x].r_u = h[rs(x)].sz + h[ls(x)].r_d;
			else if (h[rs(x)].l < h[ls(x)].r)
				h[x].r_u = h[rs(x)].sz + h[ls(x)].r_u;
			else h[x].r_u = h[rs(x)].sz;
		}
		else
		{
			if (h[rs(x)].l > h[ls(x)].r)
				h[x].r_u = h[rs(x)].sz + h[ls(x)].r_d;
			else h[x].r_u = h[rs(x)].sz;
		}
	}
	else h[x].r_u = h[rs(x)].r_u;
	h[x].Max = max(h[ls(x)].Max, h[rs(x)].Max);
	if (h[ls(x)].r > h[rs(x)].l)
		h[x].Max = max(h[x].Max, h[ls(x)].r_u + h[rs(x)].l_d);
	if (h[ls(x)].r < h[rs(x)].l)
		h[x].Max = max(h[x].Max, h[ls(x)].r_d + h[rs(x)].l_u);
}

inline void Build(int x, int l, int r)
{
	h[x].sz = r - l + 1;
	h[x].l = A[l], h[x].r = A[r];
	if (l == r)
	{
		h[x].l_d = h[x].r_d = h[x].l_u = h[x].r_u = h[x].Max = 1;
		return ;
	}
	int mid = l + r >> 1;
	Build(ls(x), l, mid);
	Build(rs(x), mid + 1, r);
	update(x);
}

inline void apply(int x, LL k)
{
	h[x].l += k, h[x].r += k;
	h[x].del += k;
}

inline void push(int x)
{
	if (h[x].del)
	{
		apply(ls(x), h[x].del);
		apply(rs(x), h[x].del);
		h[x].del = 0;
	}
}

inline void Modify(int x, int l, int r, int s, int t, int k)
{
	if (l == s && r == t)
	{
		apply(x, k);
		return ;
	}
	push(x);
	int mid = l + r >> 1;
	if (t <= mid) Modify(ls(x), l, mid, s, t, k);
	else if (s > mid) Modify(rs(x), mid + 1, r, s, t, k);
	else Modify(ls(x), l, mid, s, mid, k), Modify(rs(x), mid + 1, r, mid + 1, t, k);
	update(x);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	Build(1, 1, n);
	for (scanf("%d", &m); m --; )
	{
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		Modify(1, 1, n, l, r, d);
		printf("%d\n", h[1].Max);
	}
	return 0;
}