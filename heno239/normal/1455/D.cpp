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


int dp[505][501];
void solve() {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	rep(i, n)cin >> a[i];
	bool exi = false;
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			exi = true;
		}
	}
	if (!exi) {
		cout << 0 << "\n"; return;
	}
	rep(i, n+1)rep(j,501)dp[i][j] = mod;
	for (int i = 0; i < n; i++) {
		if (a[i] > x) {
			if (i == 0 || a[i - 1] <= x) {
				dp[i][x] = 1;
			}
		}
		if (i > 0 && a[i - 1] > a[i])break;
	}
	for (int i = 0; i < n; i++) {
		for (int k = 0; k <= 500; k++) {
			if (dp[i][k] == mod)continue;
			for (int j = i + 1; j < n; j++) {
				int preval = a[j - 1];
				if (j - 1 == i)preval = k;
				if (a[i] < a[j]) {
					if (preval <= a[i]) {
						dp[j][a[i]] = min(dp[j][a[i]], dp[i][k] + 1);
					}
				}
				if (preval > a[j])break;
			}
		}
	}
	//cout << dp[1][2] << "\n";
	int ans = mod;
	rep(i, n) {
		rep(k, 501) {
			bool valid = true;
			for (int j = i + 1; j < n; j++) {
				int preval = a[j - 1];
				if (j - 1 == i)preval = k;
				if (preval > a[j]) {
					valid = false; break;
				}
			}
			if (valid)ans = min(ans, dp[i][k]);
		}
	}
	if (ans == mod)ans = -1;
	cout << ans << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}