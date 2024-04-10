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
#include<chrono>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
constexpr ll mod = 998244353;
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

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	if (x == 0)return 0;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
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
const int max_n = 1 << 20;
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

ll gcd(ll a, ll b) {
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}

mt19937 mt(time(0));
uniform_int_distribution<> ud(0, (1 << 20) - 1);
ul ranum() {
	ul res = 0;
	res |= ud(mt);
	res |= (ul)ud(mt) << 20;
	res |= (ul)ud(mt) << 40;
	return res;
}
const int mn = 1 << 20;
bool isp[mn];
int chp[mn];
ul h[mn];
ul hs[mn];
ul hfact[mn];
void init() {
	fill(isp+2, isp + mn, true);
	for (int i = 2; i < mn; i++) {
		if (!isp[i])continue;
		h[i] = ranum();
		chp[i] = i;
		for (int j = 2 * i; j < mn; j += i) {
			isp[j] = false;
			chp[j] = i;
		}
	}
	hs[1] = 0;
	for (int i = 2; i < mn; i++) {
		hs[i] = hs[i / chp[i]] ^ h[chp[i]];
		hfact[i] = hfact[i - 1] ^ hs[i];
	}
}
void solve() {
	int n; cin >> n;
	ul z = 0;
	for (int i = 1; i <= n; i++) {
		z ^= hfact[i];
	}
	vector<int> ans;
	if (z == 0) {
		rep1(i, n)ans.push_back(i);
	}
	else {
		unordered_map<ul, int> mp;
		rep1(i, n)mp[hfact[i]] = i;
		for (int cnt = 1;; cnt++) {
			vector<int> del;
			ul cs = z;
			function<bool(int, int)> dfs = [&](int dep, int loc) {
				if (dep == cnt - 1) {
					if (mp.find(cs) != mp.end()) {
						del.push_back(mp[cs]);
						return true;
					}
					return false;
				}
				if (loc<1)return false;
				del.push_back(loc);
				cs ^= hfact[loc];
				if (dfs(dep + 1, loc - 1))return true;
				del.pop_back();
				cs ^= hfact[loc];
				if (dfs(dep, loc - 1))return true;
				return false;
			};
			if (dfs(0,n)) {
				vector<bool> can(n + 1, true);
				for (int id : del)can[id] = false;
				rep1(i, n)if (can[i])ans.push_back(i);
				break;
			}
		}
	}
	cout << ans.size() << "\n";
	coutarray(ans);
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(8);
	//init_f();
	init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}