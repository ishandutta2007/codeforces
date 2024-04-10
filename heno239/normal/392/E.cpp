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
constexpr ll mod = 100000008;
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
const int max_n = 100;
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

ll costup[400][400];
ll costdown[400][400];
ll dp[400][400];
ll dp2[400][400];
void solve() {
	int n; cin >> n;
	vector<ll> cost(n + 1);
	rep1(i, n)cin >> cost[i];
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	for (int l = n - 1; l >= 0; l--) {
		costup[l][l] = costdown[l][l] = 0;
		for (int i = l + 1; i < n; i++) {
			//up
			costup[l][i] = -INF;
			for (int j = l; j < i; j++)if (a[j] == a[i] - 1) {
				ll ncost = costup[l][j];
				if (i - j >= 2)ncost += dp[j + 1][i - 1];
				costup[l][i] = max(costup[l][i], ncost);
			}
			//down
			costdown[l][i] = -INF;
			for (int j = l; j < i; j++)if (a[j] == a[i] + 1) {
				ll ncost = costdown[l][j];
				if (i - j >= 2)ncost += dp[j + 1][i - 1];
				costdown[l][i] = max(costdown[l][i], ncost);
			}
		}
		dp[l][l] = cost[1];
		for (int j = l + 1; j < n; j++)dp[l][j] = -INF;
		for (int i = l; i < n; i++)for (int j = i; j < n; j++) {
			ll val = costup[l][i] + costdown[i][j];
			int len = a[i] - a[l] + a[i] - a[j]+1;
			if (len <= 0 || len > n)continue;
			val += cost[len];
			dp[l][j] = max(dp[l][j], val);
		}
		for (int r = l + 1; r < n; r++) {
			for (int c = l; c < r; c++) {
				dp[l][r] = max(dp[l][r], dp[l][c] + dp[c+1][r]);
			}
		}
	}

	for (int l = n - 1; l >= 0; l--) {
		dp2[l][l] = max(0ll,cost[1]);
		for (int j = l + 1; j < n; j++)dp2[l][j] = -INF;
		for (int i = l; i < n; i++)for (int j = i; j < n; j++) {
			ll val = costup[l][i] + costdown[i][j];
			int len = a[i] - a[l] + a[i] - a[j] + 1;
			if (len <= 0 || len > n)continue;
			val += cost[len];
			dp2[l][j] = max(dp2[l][j], val);
		}
		for (int r = l + 1; r < n; r++) {
			for (int c = l; c < r; c++) {
				dp2[l][r] = max(dp2[l][r], dp2[l][c] + dp2[c + 1][r]);
			}
		}
	}
	cout << dp2[0][n - 1] << "\n";
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