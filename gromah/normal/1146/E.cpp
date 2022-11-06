#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define M 262144 + 5
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, q, sz, A[N];

struct SegTree
{
	bool all_pos, all_neg, flip;
	int del;
}h[M];

void apply(int x, int k)
{
	if (k == 2)
		h[x].all_pos = 1, h[x].all_neg = h[x].flip = 0, h[x].del = k;
	else if (k == 3)
		h[x].all_neg = 1, h[x].all_pos = h[x].flip = 0, h[x].del = k;
	else
	{
		if (!h[x].all_pos && !h[x].all_neg)
			h[x].flip ^= 1;
		else h[x].all_neg ^= 1, h[x].all_pos ^= 1;
		h[x].del ^= 1;
	}
}

void push(int x)
{
	if (h[x].del)
	{
		apply(ls(x), h[x].del);
		apply(rs(x), h[x].del);
		h[x].del = 0;
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
}

int Query(int x, int l, int r, int t)
{
	if (l == r)
	{
		if (h[x].all_neg) return 3;
		if (h[x].all_pos) return 2;
		return h[x].flip;
	}
	push(x);
	int mid = l + r >> 1;
	if (t <= mid)
		return Query(ls(x), l, mid, t);
	else return Query(rs(x), mid + 1, r, t);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		sz = max(sz, A[i] > 0 ? A[i] : -A[i]);
	}
	for (int i = 1, x; i <= q; i ++)
	{
		char ch;
		scanf("\n%c %d", &ch, &x);
		if (ch == '>')
		{
			if (x >= 0)
			{
				if (x < sz)
					Modify(1, 0, sz, x + 1, sz, 3);
			}
			else
			{
				x = -x;
				if (x <= sz)
				{
					Modify(1, 0, sz, 0, x - 1, 1);
					Modify(1, 0, sz, x, sz, 3);
				}
				else Modify(1, 0, sz, 0, sz, 1);
			}
		}
		else
		{
			if (x <= 0)
			{
				x = -x;
				if (x < sz)
					Modify(1, 0, sz, x + 1, sz, 2);
			}
			else
			{
				if (x <= sz)
				{
					Modify(1, 0, sz, 0, x - 1, 1);
					Modify(1, 0, sz, x, sz, 2);
				}
				else Modify(1, 0, sz, 0, sz, 1);
			}
		}
	}
	for (int i = 1; i <= n; i ++)
	{
		int a = A[i] > 0 ? A[i] : -A[i];
		int sign = Query(1, 0, sz, a);
		int ret = sign == 0 ? A[i] : (sign == 1 ? -A[i] : (sign == 2 ? a : -a));
		printf("%d%c", ret, i == n ? '\n' : ' ');
	}
	return 0;
}