#pragma GCC target("avx2")
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
constexpr ll mod = 1000000007;
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
const ld eps = 1e-4;
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
const int max_n = 1 << 21;
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


LDP operator*(const LDP& a, const LDP& b) {
	return LDP{ a.first * b.first - a.second * b.second , a.first * b.second + a.second * b.first };
}
LDP operator+(const LDP& a, const LDP& b) {
	return LDP{ a.first + b.first,a.second + b.second };
}
LDP operator-(const LDP& a, const LDP& b) {
	return LDP{ a.first - b.first,a.second - b.second };
}
//
//eps=0.01
typedef vector<LDP> poly;
poly dft(poly f, bool inverse = false) {
	int n = f.size(); int i, j, k;
	//bit
	for (i = 0, j = 1; j < n - 1; j++) {
		for (k = n >> 1; k > (i ^= k); k >>= 1);
		if (i > j)swap(f[i], f[j]);
	}
	for (int m = 2; m <= n; m *= 2) {
		LDP zeta = { cos(2 * pi / (ld)m), sin(2 * pi / (ld)m) };
		if (inverse) {
			zeta = { cos(2 * pi * (m - 1) / (ld)m), sin(2 * pi * (m - 1) / (ld)m) };
		}
		for (i = 0; i < n; i += m) {
			LDP powzeta = { 1,0 };
			for (k = i; k < i + m / 2; k++) {
				LDP t1 = f[k], t2 = powzeta * f[k + m / 2];
				f[k] = t1 + t2; f[k + m / 2] = t1 - t2;
				powzeta = powzeta * zeta;
			}
		}
	}
	if (inverse) {
		for (i = 0; i < n; i++) {
			f[i].first /= (ld)n;
			f[i].second /= (ld)n;
		}
	}
	return f;
}
poly multiply(poly g, poly h) {
	int n = 1; int sz = g.size() + h.size();
	while (n <= sz)n *= 2;
	while (g.size() < n) {
		g.push_back({ 0,0 });
	}
	while (h.size() < n) {
		h.push_back({ 0,0 });
	}
	poly gg = dft(g);
	poly hh = dft(h);
	poly ff;
	rep(i, n) {
		ff.push_back(gg[i] * hh[i]);
	}
	return dft(ff, true);
}
void Z_algorithm(const vector<int>& s, vector<int>& a) {
	int sz = s.size();
	a.resize(sz);
	a[0] = sz;
	int i = 1, j = 0;
	while (i < sz) {
		while (i + j < sz && s[j] == s[i + j])++j;
		a[i] = j;
		if (j == 0) { ++i; continue; }
		int k = 1;
		while (i + k < sz && k + a[k] < j)a[i + k] = a[k], ++k;
		i += k; j -= k;
	}
}
void solve() {
	vector<int> p(26);
	rep(i, 26) {
		cin >> p[i]; p[i]--;
	}
	string s, t; cin >> s >> t;
	vector<int> id(26);
	vector<int> loc(26);
	vector<bool> used(26);
	int tmp = 0;
	vector<int> sz;
	rep(i, 26) {
		if (used[i])continue;
		vector<int> c;
		c.push_back(i); used[i] = true;
		int cur = p[i];
		while (cur != i) {
			c.push_back(cur); used[cur] = true; cur = p[cur];
		}
		rep(j, c.size()) {
			id[c[j]] = tmp;
			loc[c[j]] = j;
		}
		sz.push_back(c.size());
		tmp++;
	}
	poly ps(s.size());
	rep(i, s.size()) {
		int c = s[s.size() - 1 - i] - 'a';
		int k = sz[id[c]];
		ld e = pi / (ld)k;
		ld theta = e *2* loc[c];
		ps[i] = { cos(theta),sin(theta) };
	}
	poly pt(t.size());
	rep(i, t.size()) {
		int c = t[i] - 'a';
		int k = sz[id[c]];
		ld e = pi / (ld)k;
		ld theta = e * (1 - 2 * loc[c]);
		pt[i] = { cos(theta),sin(theta) };
	}
	poly pp = multiply(ps, pt);
	vector<int> cnt(t.size() - s.size() + 1);
	ld obj = 0;
	rep(i, s.size()) {
		int c = s[i] - 'a';
		int k = sz[id[c]];
		ld e = pi / (ld)k;
		obj += cos(e);
	}
	rep(i, cnt.size()) {
		LDP val = pp[s.size() - 1 + i];
		ld dif = abs(val.first - obj);
		if (dif < eps)cnt[i]++;
	}
	//rep(i, cnt.size())cout << cnt[i] << "\n";
	vector<int> qs;
	rep(i, s.size()) {
		qs.push_back(id[s[i] - 'a']);
	}
	rep(i, t.size()) {
		qs.push_back(id[t[i] - 'a']);
	}
	vector<int> ra;
	Z_algorithm(qs, ra);
	rep(i, cnt.size()) {
		if (ra[s.size() + i] >= s.size())cnt[i]++;
	}
	string ans;
	ans.resize(t.size() - s.size() + 1);
	rep(i, ans.size()) {
		if (cnt[i] == 2)ans[i] = '1';
		else ans[i] = '0';
	}
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();

	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}