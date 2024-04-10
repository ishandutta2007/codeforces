#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define M 524288 + 5
#define ls(x) x << 1
#define rs(x) x << 1 | 1
#define INF 0x7fffffffu

const constexpr int Pow[9] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
int n, m, A[N];

struct SegTree
{
	unsigned int mn[9][2];
}h[M];

void apply(int x, int k)
{
	for (int i = 0; i < 9; i ++)
	{
		if (k / Pow[i] % 10 != 0)
			h[x].mn[i][0] = k;
		else h[x].mn[i][0] = INF;
	}
}

void update(int x)
{
	for (int i = 0; i < 9; i ++)
	{
		int a = h[ls(x)].mn[i][0], b = h[ls(x)].mn[i][1];
		int c = h[rs(x)].mn[i][0], d = h[rs(x)].mn[i][1];
		if (c < a) swap(a, c);
		if (d < b) swap(b, d);
		if (c < b) swap(b, c);
		h[x].mn[i][0] = a, h[x].mn[i][1] = b;
	}
}

void Build(int x, int l, int r)
{
	for (int i = 0; i < 9; i ++)
		h[x].mn[i][0] = h[x].mn[i][1] = INF;
	if (l == r)
	{
		apply(x, A[l]);
		return ;
	}
	int mid = l + r >> 1;
	Build(ls(x), l, mid);
	Build(rs(x), mid + 1, r);
	update(x);
}

void Modify(int x, int l, int r, int t, int k)
{
	if (l == r)
	{
		apply(x, k);
		return ;
	}
	int mid = l + r >> 1;
	if (t <= mid)
		Modify(ls(x), l, mid, t, k);
	else Modify(rs(x), mid + 1, r, t, k);
	update(x);
}

void Query(int x, int l, int r, int s, int t, int i, unsigned int &a, unsigned int &b)
{
	if (l == s && r == t)
	{
		a = h[x].mn[i][0], b = h[x].mn[i][1];
		return ;
	}
	int mid = l + r >> 1;
	if (t <= mid)
		Query(ls(x), l, mid, s, t, i, a, b);
	else if (s > mid)
		Query(rs(x), mid + 1, r, s, t, i, a, b);
	else
	{
		unsigned int al, bl, ar, br;
		Query(ls(x), l, mid, s, mid, i, al, bl);
		Query(rs(x), mid + 1, r, mid + 1, t, i, ar, br);
		if (ar < al) swap(al, ar);
		if (br < bl) swap(bl, br);
		a = al, b = min(bl, ar);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	Build(1, 1, n);
	for (int i = 1, op, x, y; i <= m; i ++)
	{
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1)
			Modify(1, 1, n, x, y);
		else
		{
			unsigned int ans = -1u;
			for (int i = 0; i < 9; i ++)
			{
				unsigned int a, b;
				Query(1, 1, n, x, y, i, a, b);
				ans = min(ans, a + b);
			}
			if (ans < INF)
				printf("%u\n", ans);
			else puts("-1");
		}
	}
	return 0;
}