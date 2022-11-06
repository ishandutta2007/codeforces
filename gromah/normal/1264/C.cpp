#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5
#define M 524288 + 5
#define Mod 998244353
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, q, ans, P[N];
set<int> S;
bool Flag[N];

struct SegTree
{
	int k, b;
	SegTree() {}
	SegTree(int k, int b) : k(k), b(b) {}
}h[M];

int Power(int u, int v)
{
	int res = 1;
	for (; v; v >>= 1, u = 1LL * u * u % Mod)
		if (v & 1)
			res = 1LL * res * u % Mod;
	return res;
}

inline SegTree Union(const SegTree &lhs, const SegTree &rhs)
{
	int k1 = lhs.k, b1 = lhs.b;
	int k2 = rhs.k, b2 = rhs.b;
	int k = (1LL * k1 * k2 + k1 + k2) % Mod;
	int b = (1LL * k2 * b1 + b1 + b2) % Mod;
	return SegTree(k, b);
}

inline void update(int x)
{
	h[x] = Union(h[ls(x)], h[rs(x)]);
}

void Build(int x, int l, int r)
{
	if (l == r)
	{
		h[x].b = Power(P[l], Mod - 2);
		h[x].k = 1LL * h[x].b * (1 + Mod - P[l]) % Mod;
		return ;
	}
	int mid = l + r >> 1;
	Build(ls(x), l, mid);
	Build(rs(x), mid + 1, r);
	update(x);
}

SegTree Query(int x, int l, int r, int s, int t)
{
	if (l == s && r == t)
		return h[x];
	int mid = l + r >> 1;
	if (t <= mid)
		return Query(ls(x), l, mid, s, t);
	else if (s > mid)
		return Query(rs(x), mid + 1, r, s, t);
	else return Union(Query(ls(x), l, mid, s, mid), Query(rs(x), mid + 1, r, mid + 1, t));
}

inline void Add(int l, int r, int k)
{
	SegTree t = Query(1, 1, n, l, r - 1);
	ans = (1LL * t.b * k + ans) % Mod;
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1, inv_100 = Power(100, Mod - 2); i <= n; i ++)
	{
		scanf("%d", P + i);
		P[i] = 1LL * P[i] * inv_100 % Mod;
	}
	Build(1, 1, n);
	S.insert(1), S.insert(n + 1);
	SegTree tt = Query(1, 1, n, 1, 1);
	ans = h[1].b;
	for (int x; q; q --)
	{
		scanf("%d", &x);
		if (!Flag[x])
		{
			set<int> ::iterator it = S.lower_bound(x), _it = it;
			_it --;
			Add(*_it, *it, Mod - 1);
			Add(*_it, x, 1);
			Add(x, *it, 1);
			S.insert(x);
		}
		else
		{
			set<int> ::iterator it = S.find(x), _it = it, it_ = it;
			_it --, it_ ++;
			Add(*_it, *it, Mod - 1);
			Add(*it, *it_, Mod - 1);
			Add(*_it, *it_, 1);
			S.erase(it);
		}
		Flag[x] ^= 1;
		printf("%d\n", ans);
	}
	return 0;
}