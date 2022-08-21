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

ll mod_inverse(ll a) {
	return mod_pow(a, mod - 2);
}
ll root[24], invroot[24];
void init() {
	rep(i, 24) {
		int n = (1 << i);
		root[i] = mod_pow(3, (mod - 1) / n);
		invroot[i] = mod_inverse(root[i]);
	}
}
typedef vector <ll> poly;
poly dft(poly f, bool inverse = false) {
	int n = f.size(); int i, j, k;
	//bit
	for (i = 0, j = 1; j < n - 1; j++) {
		for (k = n >> 1; k > (i ^= k); k >>= 1);
		if (i > j)swap(f[i], f[j]);
	}
	for (int j = 1; (1 << j) <= n; j++) {
		int m = 1 << j;
		ll zeta = root[j];
		if (inverse)zeta = invroot[j];
		for (i = 0; i < n; i += m) {
			ll powzeta = 1;
			for (k = i; k < i + m / 2; k++) {
				ll t1 = f[k], t2 = powzeta * f[k + m / 2] % mod;
				f[k] = t1 + t2; while (f[k] >= mod)f[k] -= mod;
				f[k + m / 2] = t1 - t2 + mod; while (f[k + m / 2] >= mod)f[k + m / 2] -= mod;
				(powzeta *= zeta) %= mod;
			}
		}
	}
	if (inverse) {
		ll rv = mod_inverse(n);
		for (i = 0; i < n; i++) {
			(f[i] *= rv) %= mod;
		}
	}
	return f;
}
poly multiply(poly g, poly h) {
	int n = 1;
	int pi = 0, qi = 0;
	rep(i, g.size())if (g[i])pi = i;
	rep(i, h.size())if (h[i])qi = i;
	int sz = pi + qi + 2;
	while (n < sz)n *= 2;
	g.resize(n); h.resize(n);
	/*while (g.size() < n) {
	g.push_back(0);
	}
	while (h.size() < n) {
	h.push_back(0);
	}*/
	poly gg = dft(g);
	poly hh = dft(h);
	poly ff; ff.resize(n);
	rep(i, n) {
		ff[i] = gg[i] * hh[i] % mod;
	}
	return dft(ff, true);
}

poly calc(int n) {

	vector<ll> facts(n + 1);
	facts[0] = 1;
	rep(i, n) {
		facts[i + 1] = facts[i] * (i + 1) % mod;
	}
	poly p1, p2;
	rep(i, n) {
		ll c = mod_pow((i + 1), n) * mod_pow(facts[i + 1], mod - 2) % mod;

		p1.push_back(c);
	}
	rep(i, n) {
		ll c = mod_pow(facts[i], mod - 2);
		if (i % 2) {
			c = mod - c;
			if (c == mod)c = 0;
		}
		p2.push_back(c);
	}
	poly p = multiply(p1, p2);
	vector<ll> ans;
	if (n != 0)ans.push_back(0);
	else ans.push_back(1);
	rep(i, n)ans.push_back(p[i]);
	return ans;
}
void expr() {
	int n; cin >> n;
	int ans = 0;
	vector<int> v(n);
	function<void(int)> dfs = [&](int id) {
		if (id == n) {
			vector<int> cop = v;
			sort(all(cop));
			bool valid = true;
			rep(t, n)if (cop[t] > t)valid = false;
			if (valid&&v[0]==v[1]&&v[1]==v[2])ans++;
			return;
		}
		rep(i, n) {
			v[id] = i;
			dfs(id + 1);
		}
	};
	dfs(0);
	cout << ans << "\n";
}

void solve() {
	int n, k; cin >> n >> k;
	vector<modint> mem(k + 1);
	modint pro = 1;
	for (int i = 1; i <= k; i++) {
		pro *= n - (i - 1);
		mem[i] = pro;
	}
	//rep1(i, k)cout << i << " " << mem[i] << "\n";
	poly p = calc(k);
	modint ans = 0;
	for (int c = 1; c <= k; c++) {
		if (c > n)continue;
		modint num = mod_pow(n + 1, n - c,mod);
		modint num2 = (modint)p[c] * mem[c];
		//cout << c << " " << num * num2 << "\n";
		ans += num * num2;
	}
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	init();
	//expr();
	//int t; cin >> t;rep(i, t)
	solve();
	return 0;
}