#pragma GCC optimize("Ofast")
//#pragma GCC target ("sse4")

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
const int max_n = 2;
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

int trans[1 << 18];
vector<int> f;
void init() {
	f.push_back(1);
	f.push_back(1);
	while (f.back()<300000) {
		f.push_back(f[f.size() - 2] + f[f.size() - 1]);
	}
	fill(trans, trans + (1 << 18), -1);
	rep(i, f.size())if (f[i] < (1 << 18))trans[f[i]] = i;
}
void solve() {
	int n; cin >> n;
	vector<vector<int>> G(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if (trans[n] < 0) {
		cout << "NO\n"; return;
	}
	vector<vector<int>> ids;
	vector<int> ori;
	rep(i, n)ori.push_back(i);
	ids.push_back(ori);
	vector<bool> exi(n);
	while (!ids.empty()) {
		vector<int> v = ids.back(); ids.pop_back();
		int sz = v.size();
		//cout << sz << "\n";
		if (sz == 1)continue;
		int loc = trans[sz];
		//assert(loc >1);
		for (int id : v)exi[id] = true;

		int root = v[0];
		int nexr = -1, nexpar = -1;
		function<int(int, int)> dfs = [&](int id, int fr)->int {
			int ret = 1;
			for (int to : G[id])if (to != fr)if (exi[to]) {
				ret += dfs(to, id);
			}
			if (ret == f[loc - 1] || ret == f[loc - 2]) {
				nexr = id; nexpar = fr;
			}
			return ret;
		}; dfs(root, -1);
		if(nexr < 0) {
			cout << "NO\n"; return;
		}
		vector<int> ad;
		function<void(int, int)> chs = [&](int id, int fr) {
			ad.push_back(id);
			for (int to : G[id])if (to != fr)if (exi[to]) {
				chs(to, id);
			}
		};
		chs(nexr,nexpar);
		for (int id : ad)exi[id] = false;
		vector<int> ad2;
		for (int id : v)if (exi[id])ad2.push_back(id);

		ids.push_back(ad);
		ids.push_back(ad2);
		//cout << "? " << ad.size() << " " << ad2.size() << "\n";

		for (int id : v)exi[id] = false;
	}
	cout << "YES\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	init();
	//expr();
	//int t; cin >> t; rep(i,t)
	solve();
	return 0;
}