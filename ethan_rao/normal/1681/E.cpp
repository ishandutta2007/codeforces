#include "bits/stdc++.h"
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
template <typename T>
struct sgt_nt
{
	int L, R, n;
	vector<int> _ys;
	int *ys;
	T *a;
	vector<T> _s;
	T *s;
#ifdef revsum
	vector<T> _rs;
	T *rs;
#endif
	int z, y, fir;
	T dt;

private:
	void build(int x, int l, int r)
	{
		if (l == r)
		{
			ys[l] = x;
			s[x] = a[l];
#ifdef revsum
			rs[x] = a[l];
#endif
			return;
		}
		int c = x * 2, m = l + r >> 1;
		build(c, l, m);
		build(c + 1, m + 1, r);
		s[x] = s[c] + s[c + 1];
#ifdef revsum
		rs[x] = rs[c + 1] + rs[c];
#endif
	}
	void init(int n)
	{
		_ys.resize(n + 1);
		ys = _ys.data();
		n <<= 2;
		_s.resize(n);
		s = _s.data();
#ifdef revsum
		_rs.resize(n);
		rs = _rs.data();
#endif
	}

public:
	sgt_nt()
	{
		n = 0;
	}
	sgt_nt(T b, int lt, int rt)
	{
		assert(lt <= rt);
		L = lt;
		R = rt;
		init(n = R - L + 1);
		vector<T> _a(n, b);
		a = _a.data() - 1;
		build(1, 1, n);
	}
	sgt_nt(T *b, int lt, int rt)
	{
		assert(lt <= rt);
		L = lt;
		R = rt;
		init(n = R - L + 1);
		a = b + L - 1;
		build(1, 1, n);
	}
	void modify(int p, T b)
	{
		assert(L <= p && p <= R);
		// cerr<<"modify "<<p<<" to "<<b<<endl;
		p = ys[p - L + 1];
		s[p] = b;
#ifdef revsum
		rs[p] = b;
#endif
		while (p >>= 1)
		{
			s[p] = s[p * 2] + s[p * 2 + 1];
#ifdef revsum
			rs[p] = rs[p * 2 + 1] + rs[p * 2];
#endif
		}
	}

private:
	void ask_sum(int x, int l, int r)
	{
		if (z <= l && r <= y)
		{
			dt = fir ? s[x] : dt + s[x];
			fir = 0;
			return;
		}
		int c = x * 2, m = l + r >> 1;
		if (z <= m)
			ask_sum(c, l, m);
		if (y > m)
			ask_sum(c + 1, m + 1, r);
	}

public:
	T ask_sum(int l, int r)
	{
		assert(L <= l && l <= r && r <= R);
		z = l - L + 1;
		y = r - L + 1;
		fir = 1;
		ask_sum(1, 1, n);
		// cerr<<"sum of ["<<l<<','<<r<<"] = "<<dt<<endl;
		return dt;
	}
#ifdef revsum
private:
	void ask_revsum(int x, int l, int r)
	{
		if (z <= l && r <= y)
		{
			dt = fir ? rs[x] : dt + rs[x];
			fir = 0;
			return;
		}
		int c = x * 2, m = l + r >> 1;
		if (y > m)
			ask_revsum(c + 1, m + 1, r);
		if (z <= m)
			ask_revsum(c, l, m);
	}

public:
	T ask_revsum(int l, int r)
	{
		assert(L <= r && r <= l && l <= R);
		z = r - L + 1;
		y = l - L + 1;
		fir = 1;
		ask_revsum(1, 1, n);
		// cerr<<"revsum of ["<<l<<','<<r<<"] = "<<dt<<endl;
		return dt;
	}
#endif
};
const ll inf = 1e18;
template <int n>
struct matrix
{
#define all(x) (x).begin(), (x).end()
	array<array<ll, n>, n> a;
	matrix(char c = 'O')
	{
		int i;
		if (c == 'O')
			for (i = 0; i < n; i++)
				fill(all(a[i]), inf);
		else if (c == 'E')
			for (i = 0; i < n; i++)
				fill(all(a[i]), 0);
		else
			assert(0);
	}
	matrix operator+(const matrix &o) const
	{
		matrix r;
		int i, j, k;
		for (k = 0; k < n; k++)
		{
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
					r.a[i][j] = min(r.a[i][j], a[i][k] + o.a[k][j]);
		}
		return r;
	}
};
struct Q
{
	int x, y;
	Q operator+(const Q &o) const { return {x + o.x, y + o.y}; }
	int level() const { return max(x, y); }
};
int dis(const Q &o, const Q &p) { return abs(p.x - o.x) + abs(p.y - o.y); }
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, i, j;
	cin >> n;
	vector<array<Q, 2>> d(n), dd(n + 1);
	for (i = 1; i < n; i++)
		for (j = 0; j < 2; j++)
			cin >> d[i][j].x >> d[i][j].y;
	cin >> m;
	vector<matrix<2>> a(n);
	for (i = 1; i < n; i++)
	{
		dd[i + 1][0] = d[i][0] + Q{1, 0};
		dd[i + 1][1] = d[i][1] + Q{0, 1};
	}
	for (i = 1; i < n - 1; i++)
	{
		static Q p[4];
		p[0] = d[i][0] + Q{1, 0};
		p[1] = d[i][1] + Q{0, 1};
		p[2] = d[i + 1][0];
		p[3] = d[i + 1][1];
		a[i].a[0] = {dis(p[0], p[2]) + 1, dis(p[0], p[3]) + 1};
		a[i].a[1] = {dis(p[1], p[2]) + 1, dis(p[1], p[3]) + 1};
	}
	sgt_nt<matrix<2>> s;
	if (n > 2)
		s = sgt_nt<matrix<2>>(a.data(), 1, n - 2);
	while (m--)
	{
		static Q p[2];
		for (i = 0; i < 2; i++)
			cin >> p[i].x >> p[i].y;
		if (p[0].level() > p[1].level())
			swap(p[0], p[1]);
		int L = p[0].level(), R = p[1].level();
		assert(L <= R);
		if (L == R)
		{
			cout << dis(p[0], p[1]) << '\n';
			continue;
		}
		int ds[2][2] = {{dis(p[0], d[L][0]), dis(p[0], d[L][1])}, {dis(p[1], dd[R][0]), dis(p[1], dd[R][1])}};
		// for (i = 0; i < 2; i++)
		//	for (j = 0; j < 2; j++)
		//		cerr << ds[i][j] << " \n"[j == 1];
		// cerr << '\n';
		if (L + 1 == R)
		{
			cout << min(ds[0][0] + ds[1][0], ds[0][1] + ds[1][1]) + 1 << '\n';
			continue;
		}
		auto x = s.ask_sum(L, R - 2);
		ll ans = 1e18;
		for (i = 0; i < 2; i++)
			for (j = 0; j < 2; j++)
				ans = min(ans, ds[0][i] + ds[1][j] + x.a[i][j]);
		cout << ans + 1 << "\n";
	}
}