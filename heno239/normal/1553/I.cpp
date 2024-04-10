#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
#include<array>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n % mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint& a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint& a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint& a, modint b) { a.n = ((ll)a.n * b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint& a, modint b) { a = a / b; return a; }
const int max_n = 1 << 18;
modint fact[max_n], factinv[max_n];
void init_f() {
	fact[0] = modint(1);
	for (int i = 0; i < max_n - 1; i++) {
		fact[i + 1] = fact[i] * modint(i + 1);
	}
	factinv[max_n - 1] = modint(1) / fact[max_n - 1];
	for (int i = max_n - 2; i >= 0; i--) {
		factinv[i] = factinv[i + 1] * modint(i + 1);
	}
}
modint comb(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[b] * factinv[a - b];
}
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}


int get_premitive_root() {
	int primitive_root = 0;
	if (!primitive_root) {
		primitive_root = [&]() {
			set<int> fac;
			int v = mod - 1;
			for (ll i = 2; i * i <= v; i++) while (v % i == 0) fac.insert(i), v /= i;
			if (v > 1) fac.insert(v);
			for (int g = 1; g < mod; g++) {
				bool ok = true;
				for (auto i : fac) if (mod_pow(g, (mod - 1) / i) == 1) { ok = false; break; }
				if (ok) return g;
			}
			return -1;
		}();
	}
	return primitive_root;
}
const int proot = get_premitive_root();

typedef vector <modint> poly;
void dft(poly& f, bool inverse = false) {
	int n = f.size(); if (n == 1)return;

	static poly w{ 1 }, iw{ 1 };
	for (int m = w.size(); m < n / 2; m *= 2) {
		modint dw = mod_pow(proot, (mod - 1) / (4 * m)), dwinv = (modint)1 / dw;
		w.resize(m * 2); iw.resize(m * 2);
		for (int i = 0; i < m; i++)w[m + i] = w[i] * dw, iw[m + i] = iw[i] * dwinv;
	}
	if (!inverse) {
		for (int m = n; m >>= 1;) {
			for (int s = 0, k = 0; s < n; s += 2 * m, k++) {
				for (int i = s; i < s + m; i++) {
					modint x = f[i], y = f[i + m] * w[k];
					f[i] = x + y, f[i + m] = x - y;
				}
			}
		}
	}
	else {
		for (int m = 1; m < n; m *= 2) {
			for (int s = 0, k = 0; s < n; s += 2 * m, k++) {
				for (int i = s; i < s + m; i++) {
					modint x = f[i], y = f[i + m];
					f[i] = x + y, f[i + m] = (x - y) * iw[k];
				}
			}
		}
		modint n_inv = (modint)1 / (modint)n;
		for (modint& v : f)v *= n_inv;
	}
}
poly multiply(poly g, poly h) {
	int n = 1;
	int pi = 0, qi = 0;
	rep(i, g.size())if (g[i])pi = i;
	rep(i, h.size())if (h[i])qi = i;
	int sz = pi + qi + 2;
	while (n < sz)n *= 2;
	g.resize(n); h.resize(n);
	dft(g); dft(h);
	rep(i, n) {
		g[i] *= h[i];
	}
	dft(g, true);
	return g;
}
modint inv2 = (1 + mod) / 2;
struct Data {
	poly p[2][2];
};
Data merge(Data dl, Data dr,int isone) {
	Data res;
	rep(a1, 2)rep(b1, 2)rep(a2, 2)rep(b2, 2) {
		poly r = multiply(dl.p[a1][b1], dr.p[a2][b2]);
		while (r.size() && r.back() == (modint)0)r.pop_back();
		if (isone && b1 && a2) {
			rep(i, r.size())r[i] *= inv2;
		}
		int na = a1, nb = b2;
		if (res.p[na][nb].size() < r.size()) {
			res.p[na][nb].resize(r.size(), 0);
		}
		rep(i, r.size()) {
			res.p[na][nb][i] += r[i];
		}
	}
	return res;
}
void solve(){
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<int> c;
	int cur = 0;
	while (cur < n) {
		if (cur + a[cur] > n) {
			cout << 0 << "\n"; return;
		}
		Rep(j, cur, cur + a[cur]) {
			if (a[cur] != a[j]) {
				cout << 0 << "\n"; return;
			}
		}
		c.push_back(a[cur]);
		cur += a[cur];
	}
	if (c.size() == 1) {
		if (n == 1) {
			cout << 1 << "\n";
		}
		else {
			cout << 2 << "\n";
		}
		return;
	}
	function<Data(int, int)> yaru = [&](int l, int r)->Data {
		if (r - l == 1) {
			int cnt = 0;
			if (c[l] == 1)cnt++;
			if (c[r] == 1)cnt++;
			Data res;
			res.p[0][0] = { 1 };
			res.p[1][1] = { 0,(1 << cnt) };
			return res;
		}
		int m = (l + r) / 2;
		Data dl = yaru(l, m);
		Data dr = yaru(m, r);
		return merge(dl, dr, c[m] == 1);
	};
	Data d = yaru(0, c.size() - 1);
	vector<modint> num;
	rep(i, 2)rep(j, 2) {
		if (num.size() < d.p[i][j].size()) {
			num.resize(d.p[i][j].size());
		}
		rep(k, d.p[i][j].size()) {
			num[k] += d.p[i][j][k];
		}
	}
	int c1 = 0;
	rep(i, c.size())if (c[i] == 1)c1++;
	modint coef = mod_pow(inv2, c1);
	
	modint ans = 0;
	rep(i, num.size()) {
		if (i > c.size())continue;
		modint val = num[i];
		if (i % 2)val *= -1;
		val *= mod_pow(2, c.size() - i);
		val *= fact[c.size() - i];
		val *= coef;
		ans += val;
		//cout << i << " " << val << "\n";
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}