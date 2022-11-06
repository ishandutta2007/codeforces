#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 131072 + 5
#define M 262144 + 5
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, k, m, q, Fa[21], Id[21];
bool Map[N][6];

struct Segment_Tree
{
	int l, r, cnt, Pre[6], Suf[6];
	Segment_Tree ()
	{
		l = r = cnt = 0;
		memset(Pre, 0, sizeof(Pre));
		memset(Suf, 0, sizeof(Suf));
	}
}h[M];

inline int Find(int x)
{
	return x == Fa[x] ? x : Fa[x] = Find(Fa[x]);
}

inline Segment_Tree Union(Segment_Tree u, Segment_Tree v)
{
	Segment_Tree res;
	res.l = u.l, res.r = v.r, res.cnt = u.cnt + v.cnt;
	for (int i = 1; i <= v.r - v.l + 1 && i <= k; i ++)
		v.Pre[i] += 2 * k, v.Suf[i] += 2 * k;
	if (u.r - u.l + 1 < k)
	{
		for (int i = 1; i <= u.r - u.l + 1; i ++)
			res.Pre[i] = u.Pre[i];
		for (int i = u.r - u.l + 2; i <= k; i ++)
		{
			int j = i - (u.r - u.l + 1);
			if (j > v.r - v.l + 1) break ;
			res.Pre[i] = v.Pre[j];
		}
	}
	else for (int i = 1; i <= k; i ++)
		res.Pre[i] = u.Pre[i];
	if (v.r - v.l + 1 < k)
	{
		for (int i = 1; i <= v.r - v.l + 1; i ++)
			res.Suf[i] = v.Suf[i];
		for (int i = v.r - v.l + 2; i <= k; i ++)
		{
			int j = i - (v.r - v.l + 1);
			if (j > u.r - u.l + 1) break ;
			res.Suf[i] = u.Suf[j];
		}
	}
	else for (int i = 1; i <= k; i ++)
		res.Suf[i] = v.Suf[i];
	for (int i = 1; i <= 4 * k; i ++)
		Fa[i] = i, Id[i] = 0;
	for (int i = u.r; i >= u.l && u.r - i < k; i --)
		for (int j = v.l; j <= v.r && j - i <= k; j ++)
		{
			if (!Map[i][j - i]) continue ;
			int _i = u.Suf[u.r - i + 1];
			int _j = v.Pre[j - v.l + 1];
			_i = Find(_i), _j = Find(_j);
			if (_i != _j)
				Fa[_j] = _i, res.cnt --;
		}
	int t = 0;
	for (int i = 1; i <= res.r - res.l + 1 && i <= k; i ++)
	{
		res.Pre[i] = Find(res.Pre[i]);
		if (!Id[res.Pre[i]]) Id[res.Pre[i]] = ++ t;
		res.Pre[i] = Id[res.Pre[i]];
	}
	for (int i = 1; i <= res.r - res.l + 1 && i <= k; i ++)
	{
		res.Suf[i] = Find(res.Suf[i]);
		if (!Id[res.Suf[i]]) Id[res.Suf[i]] = ++ t;
		res.Suf[i] = Id[res.Suf[i]];
	}
	return res;
}

inline void Build(int x, int l, int r)
{
	h[x].l = l, h[x].r = r;
	if (l == r)
	{
		h[x].Pre[1] = h[x].Suf[1] = h[x].cnt = 1;
		return ;
	}
	int mid = l + r >> 1;
	Build(ls(x), l, mid);
	Build(rs(x), mid + 1, r);
	h[x] = Union(h[ls(x)], h[rs(x)]);
}

inline Segment_Tree Query(int x, int l, int r, int s, int t)
{
	if (l == s && r == t) return h[x];
	int mid = l + r >> 1;
	if (t <= mid) return Query(ls(x), l, mid, s, t);
	else if (s > mid) return Query(rs(x), mid + 1, r, s, t);
	else return Union(Query(ls(x), l, mid, s, mid), Query(rs(x), mid + 1, r, mid + 1, t));
}

int main()
{
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1, u, v; i <= m; i ++)
	{
		scanf("%d%d", &u, &v);
		if (u > v) swap(u, v);
		Map[u][v - u] = 1;
	}
	Build(1, 1, n);
	for (scanf("%d", &q); q; q --)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		Segment_Tree res = Query(1, 1, n, l, r);
		printf("%d\n", res.cnt);
	}
	return 0;
}