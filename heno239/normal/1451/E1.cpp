#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
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

int query(string s, int i, int j) {
	cout << s << " " << i + 1 << " " << j + 1 << endl;
	int res; cin >> res; return res;
}
void solve() {
	int n; cin >> n;
	vector<int> x(n - 1);
	rep(i, n - 1) {
		x[i] = query("XOR", i, i + 1);
	}
	int tmp = 0;
	int cop = 1;
	while (2 * cop <= n) {
		cop *= 2; tmp++;
	}
	vector<vector<int>> b(tmp, vector<int>(n));
	rep(j, n - 1)rep(i, tmp) {
		b[i][j + 1] ^= b[i][j];
		if (x[j]&(1<<i)) {
			b[i][j + 1] ^= 1;
		}
	}
	vector<int> v;
	rep(i, n)v.push_back(i);
	for (int i = 1; i < tmp; i++) {
		vector<int> vl, vr;
		for (int id : v) {
			if (b[i][id])vr.push_back(id);
			else vl.push_back(id);
		}
		if (vl.size() < vr.size())swap(vl, vr);
		swap(v, vl);
	}
	//assert(v.size()>=2
	vector<int> ans(n);
	int val = query("AND", v[0], v[1]);
	for (int i = 1; i < tmp; i++) {
		int c = 0;
		if (b[i][v[0]])c ^= 1;
		if (val & (1 << i))c ^= 1;
		rep(j, n) {
			if (c ^ b[i][j]) {
				ans[j] |= (1 << i);
			}
		}
	}
	vector<int> vl, vr;
	rep(j, n) {
		if (b[0][j])vr.push_back(j);
		else vl.push_back(j);
	}
	if (vl.size() < vr.size())swap(vl, vr);
	val = query("AND", vl[0], vl[1]);
	int c = 0;
	if (b[0][vl[0]])c ^= 1;
	if (val & 1)c ^= 1;
	rep(j, n) {
		if (c ^ b[0][j])ans[j] |= 1;
	}
	cout << "!";
	rep(j, n) {
		cout << " " << ans[j];
	}
	cout << endl;
}

signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}