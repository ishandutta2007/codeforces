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
typedef long double ld;
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
using mP = pair<modint, modint>;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	sort(all(a));
	vector<mP> memo(n);
	memo[0] = { 1,0 };
	for (int c = 0; c <= n - 2; c++) {
		modint A = (ll)n * k - c - (ll)(n - c) * (k - 1);
		modint B = -(ll)c * (k - 1);
		modint x = A * memo[c].first;
		if (c > 0)x += B * memo[c - 1].first;
		modint y = A * memo[c].second;
		if (c > 0)y += B * memo[c - 1].second;
		y -= (ll)n * k;
		x /= n - c;
		y /= n - c;
		memo[c + 1] = { x,y };
	}
	int c = n - 1;
	modint A = (ll)n * k - c - (ll)(n - c) * (k - 1);
	modint B = -(ll)c * (k - 1);
	modint x = A * memo[c].first;
	if (c > 0)x += B * memo[c - 1].first;
	modint y = A * memo[c].second;
	if (c > 0)y += B * memo[c - 1].second;
	y -= (ll)n * k;
	vector<modint> ex(n);
	ex[0] = (modint)-y / x;
	for (int c = 1; c < n; c++) {
		ex[c] = memo[c].first * ex[0] + memo[c].second;
	}
	int ad = 0;
	vector<int> cs;
	int rest = k;
	rep(i, n) {
		int le = i;
		while (i + 1 < n && a[i] == a[i + 1])i++;
		int len = i - le + 1;
		if (a[i] < 0) {
			ad = len;
		}
		else {
			rest--;
			cs.push_back(len);
		}
	}
	sort(all(cs));
	vector<P> ps;
	rep(i, cs.size()) {
		int le = i;
		while (i + 1 < cs.size() && cs[i] == cs[i + 1])i++;
		int cnt = i - le + 1;
		ps.push_back({ cs[i],cnt });
	}
	ps.push_back({ 0,rest });
	modint ans = 0;
	vector<modint> coef(ad + 1);
	rep(i, ad + 1) {
		coef[i] = comb(ad, i) * (modint)mod_pow(k - 1, ad - i);
	}
	ex.push_back(0);
	for (P p : ps) {
		for (int i = 0; i <= ad; i++) {
			modint val = ex[p.first + i];
			val *= p.second;
			ans += val * coef[i];
		}
	}
	ans -= (modint)(k - 1) * ex[0] * (modint)mod_pow(k, ad);
	ans /= k;
	ans /= mod_pow(k, ad);
	cout << ans << "\n";
	//cout << ex[1] << "\n";
	//cout << ex[0] << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(8);
	init_f();
	//init();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}