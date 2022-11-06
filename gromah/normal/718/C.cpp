#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define M 262144 + 5
#define Mod 1000000007
#define ls(x) x << 1
#define rs(x) x << 1 | 1

int n, m;

inline int Inc(int a, int b)
{
	return a + b - (a + b >= Mod ? Mod : 0);
}

struct Matrix
{
	int r, c, num[2][2];
	void Init(int op)
	{
		if (op == 0)
		{
			r = 1, c = 2;
			num[0][0] = 0, num[0][1] = 1;
		}
		else if (op == 1)
		{
			r = c = 2;
			num[0][0] = 0;
			num[0][1] = num[1][0] = num[1][1] = 1;
		}
		else if (op == 2)
		{
			r = c = 2;
			num[0][0] = num[1][1] = 1;
			num[0][1] = num[1][0] = 0;
		}
	}
	bool Check()
	{
		if (num[0][0] != 1 || num[1][1] != 1) return 0;
		if (num[0][1] || num[1][0]) return 0;
		return 1;
	}
	void Multi(Matrix a)
	{
		if (r == 1)
		{
			int o = Inc(1LL * num[0][0] * a.num[0][0] % Mod, 1LL * num[0][1] * a.num[1][0] % Mod);
			int i = Inc(1LL * num[0][0] * a.num[0][1] % Mod, 1LL * num[0][1] * a.num[1][1] % Mod);
			num[0][0] = o, num[0][1] = i;
		}
		else
		{
			int o_o = Inc(1LL * num[0][0] * a.num[0][0] % Mod, 1LL * num[0][1] * a.num[1][0] % Mod);
			int o_i = Inc(1LL * num[0][0] * a.num[0][1] % Mod, 1LL * num[0][1] * a.num[1][1] % Mod);
			int i_o = Inc(1LL * num[1][0] * a.num[0][0] % Mod, 1LL * num[1][1] * a.num[1][0] % Mod);
			int i_i = Inc(1LL * num[1][0] * a.num[0][1] % Mod, 1LL * num[1][1] * a.num[1][1] % Mod);
			num[0][0] = o_o, num[0][1] = o_i;
			num[1][0] = i_o, num[1][1] = i_i;
		}
	}
}f, g, _g, T[N], h[M], Del[M];

inline Matrix Get(int x)
{
	_g.Init(1), g.Init(2);
	for (; x; x >>= 1)
	{
		if (x & 1) g.Multi(_g);
		_g.Multi(_g);
	}
	return g;
}

inline void update(int x)
{
	h[x].num[0][0] = Inc(h[ls(x)].num[0][0], h[rs(x)].num[0][0]);
	h[x].num[0][1] = Inc(h[ls(x)].num[0][1], h[rs(x)].num[0][1]);
}

inline void Build(int x, int l, int r)
{
	Del[x].Init(2);
	if (l == r)
	{
		h[x] = T[l];
		return ;
	}
	int mid = l + r >> 1;
	Build(ls(x), l, mid);
	Build(rs(x), mid + 1, r);
	update(x);
}

inline void Apply(int x, Matrix k)
{
	h[x].Multi(k);
	Del[x].Multi(k);
}

inline void push(int x)
{
	if (!Del[x].Check())
	{
		Apply(ls(x), Del[x]);
		Apply(rs(x), Del[x]);
		Del[x].Init(2);
	}
}

inline void Modify(int x, int l, int r, int s, int t)
{
	if (l == s && r == t)
	{
		Apply(x, f);
		return ;
	}
	push(x);
	int mid = l + r >> 1;
	if (t <= mid) Modify(ls(x), l, mid, s, t);
	else if (s > mid) Modify(rs(x), mid + 1, r, s, t);
	else Modify(ls(x), l, mid, s, mid), Modify(rs(x), mid + 1, r, mid + 1, t);
	update(x);
}

inline Matrix Query(int x, int l, int r, int s, int t)
{
	if (l == s && r == t) return h[x];
	push(x);
	int mid = l + r >> 1;
	if (t <= mid) return Query(ls(x), l, mid, s, t);
	else if (s > mid) return Query(rs(x), mid + 1, r, s, t);
	else
	{
		Matrix _0 = Query(ls(x), l, mid, s, mid);
		Matrix _1 = Query(rs(x), mid + 1, r, mid + 1, t);
		_0.num[0][0] = Inc(_0.num[0][0], _1.num[0][0]);
		_0.num[0][1] = Inc(_0.num[0][1], _1.num[0][1]);
		return _0;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, x; i <= n; i ++)
	{
		scanf("%d", &x);
		T[i].Init(0);
		f = Get(x);
		T[i].Multi(f);
	}
	Build(1, 1, n);
	while (m --)
	{
		int type, l, r, x;
		scanf("%d", &type);
		if (type == 1)
		{
			scanf("%d%d%d", &l, &r, &x);
			f = Get(x);
			Modify(1, 1, n, l, r);
		}
		else
		{
			scanf("%d%d", &l, &r);
			f = Query(1, 1, n, l, r);
			printf("%d\n", f.num[0][0]);
		}
	}
	return 0;
}