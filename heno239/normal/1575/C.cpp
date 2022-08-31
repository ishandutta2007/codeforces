//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
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
constexpr ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int>P;

#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define all(v) (v).begin(),(v).end()
typedef pair<ll, ll> LP;
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
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
const int max_n = 1 << 2;
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

int get_premitive_root(const ll& p) {
	int primitive_root = 0;
	if (!primitive_root) {
		primitive_root = [&]() {
			set<int> fac;
			int v = p - 1;
			for (ll i = 2; i * i <= v; i++) while (v % i == 0) fac.insert(i), v /= i;
			if (v > 1) fac.insert(v);
			for (int g = 1; g < p; g++) {
				bool ok = true;
				for (auto i : fac) if (mod_pow(g, (p - 1) / i, p) == 1) { ok = false; break; }
				if (ok) return g;
			}
			return -1;
		}();
	}
	return primitive_root;
}

typedef vector <ll> poly;
void dft(poly& f, const ll& p, const int& proot, bool inverse = false) {
	int n = f.size(); if (n == 1)return;

	poly w{ 1 }, iw{ 1 };
	for (int m = w.size(); m < n / 2; m *= 2) {
		ll dw = mod_pow(proot, (p - 1) / (4 * m), p), dwinv = mod_pow(dw, p - 2, p);
		w.resize(m * 2); iw.resize(m * 2);
		for (int i = 0; i < m; i++)w[m + i] = w[i] * dw % p, iw[m + i] = iw[i] * dwinv % p;
	}
	if (!inverse) {
		for (int m = n; m >>= 1;) {
			for (int s = 0, k = 0; s < n; s += 2 * m, k++) {
				for (int i = s; i < s + m; i++) {
					ll x = f[i], y = f[i + m] * w[k] % p;
					f[i] = x + y, f[i + m] = x - y;
					if (f[i] >= p)f[i] -= p;
					if (f[i + m] < 0)f[i + m] += p;
				}
			}
		}
	}
	else {
		for (int m = 1; m < n; m *= 2) {
			for (int s = 0, k = 0; s < n; s += 2 * m, k++) {
				for (int i = s; i < s + m; i++) {
					ll x = f[i], y = f[i + m];
					f[i] = x + y, f[i + m] = (x - y) * iw[k] % p;
					if (f[i] >= p)f[i] -= p;
					if (f[i + m] < 0)f[i + m] += p;
				}
			}
		}
		ll n_inv = mod_pow(n, p - 2, p);
		for (ll& v : f)(v *= n_inv) %= p;
	}
}

poly multi(poly g, poly h, const ll& p, int n) {
	const int proot = get_premitive_root(p);
	dft(g, p, proot, false);
	dft(h, p, proot, false);
	poly f(n);
	rep(i, n) {
		f[i] = g[i] * h[i] % p;
	}
	dft(f, p, proot, true);
	return f;
}

constexpr ll m0 = 469762049;
constexpr ll m1 = 167772161;
constexpr ll m2 = 595591169;
const ll inv01 = mod_pow(m0, m1 - 2, m1);
const ll inv012 = mod_pow(m0 * m1, m2 - 2, m2);

ll calc(ll& a, ll& b, ll& c, const ll& p) {
	ll res = 0;
	ll x1 = a;
	ll x2 = (b - x1) * inv01;
	x2 %= m1; if (x2 < 0)x2 += m1;
	ll x3 = (c - x1 - x2 * m0) % m2 * inv012;
	x3 %= m2; if (x3 < 0)x3 += m2;
	res = x1 + x2 * m0 % p + x3 * m0 % p * m1;
	return res % p;
}
poly multiply(poly g, poly h, const ll& p) {

	int resz = g.size() + h.size() - 1;

	int n = 1;
	int pi = 0, qi = 0;
	rep(i, g.size())if (g[i])pi = i;
	rep(i, h.size())if (h[i])qi = i;
	int sz = pi + qi + 2;
	while (n < sz)n *= 2;
	g.resize(n); h.resize(n);

	poly vp[3];
	vp[0] = multi(g, h, m0, n);
	vp[1] = multi(g, h, m1, n);
	vp[2] = multi(g, h, m2, n);
	poly res(resz);
	rep(i, res.size()) {
		ll a, b, c;
		if (i < vp[0].size())a = vp[0][i];
		else a = 0;
		if (i < vp[1].size())b = vp[1][i];
		else b = 0;
		if (i < vp[2].size())c = vp[2][i];
		else c = 0;
		res[i] = calc(a, b, c, p);
	}
	return res;
}


void solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	vector<int> l(n), r(n);
	rep(i, n - 1) {
		l[i + 1] = (l[i] + a[i]) % k;
	}
	rep(i, n - 1) {
		r[i + 1] = (r[i] + a[n - 1 - i]) % k;
	}
	int sum = 0;
	rep(i, n) {
		sum += a[i]; sum %= k;
	}
	poly f(k), g(k), h(k);
	rep(i, n) {
		f[l[i]] += 1;
		g[r[i]] += 1;
	}
	for (int c = 0; c <= m - 2; c++) {
		h[(ll)sum * c % k] += 1;
	}
	poly fg = multiply(f, g,mod);
	modint ans = 0;
	rep(i, fg.size()) {
		int id = i % k;
		int to = k - id; to %= k;
		ans += fg[i] * h[to];
	}
	vector<int> cnt(k);
	int obj = (ll)(m - 1) * sum % k;
	obj = k - obj; obj %= k;
	for (int c = n - 1; c >= 0; c--) {
		cnt[l[n - 1 - c]]++;
		int to = obj - r[c]; if (to < 0)to += k;
		ans += cnt[to];
		//cout << c << " " << cnt[to] << "\n";
	}
	ans -= 1;
	fill(all(cnt), 0);
	for (int c = 1; c <= n - 1; c++) {
		ans += cnt[l[c]];
		cnt[l[c]] += 1;
	}
	ans *= m;
	if ((ll)sum * m % k == 0)ans+=1;
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(8);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}