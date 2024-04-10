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
typedef double ld;
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
const int max_n = 1 << 10;
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

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool comp(P a, P b) {
	if (a.first != b.first)return a.first < b.first;
	return a.second > b.second;
}
void solve() {
	int n; cin >> n;
	vector<int> x(n), y(n);
	rep(i, n)cin >> x[i] >> y[i];
	vector<pair<int, P>> vs;
	rep(i, n) {
		vs.push_back({ max(x[i],y[i]),{x[i],y[i]} });
	}
	sort(all(vs));
	vector<vector<P>> ps;

	ps.push_back({ { 0,0 } });
	rep(i, vs.size()) {
		vector<P> cur;
		int le = i;
		while (i + 1 < vs.size() && vs[i].first == vs[i + 1].first)i++;
		for (int j = le; j <= i; j++)cur.push_back(vs[j].second);
		ps.push_back(cur);
	}
	rep(i, ps.size()) {
		sort(all(ps[i]), comp);
	}
	vector < array < ll , 2 >> dp(ps.size() + 1);
	rep(i, ps.size() + 1)rep(j, 2)dp[i][j] = INF;
	dp[0][0] = dp[0][1] = 0;
	rep1(i, ps.size()-1) {
		rep(j, 2)rep(k, 2) {
			int cx = ps[i - 1][0].first, cy = ps[i - 1][0].second;
			if (j == 1)cx = ps[i - 1].back().first, cy = ps[i - 1].back().second;
			if (k == 0) {
				ll ad = 0;
				per(t, ps[i].size()) {
					ll tx = ps[i][t].first, ty = ps[i][t].second;
					ad += abs(tx - cx) + abs(ty - cy);
					cx = tx, cy = ty;
				}
				dp[i][k] = min(dp[i][k], dp[i - 1][j] + ad);
			}
			else {
				ll ad = 0;
				rep(t, ps[i].size()) {
					ll tx = ps[i][t].first, ty = ps[i][t].second;
					ad += abs(tx - cx) + abs(ty - cy);
					cx = tx, cy = ty;
				}
				dp[i][k] = min(dp[i][k], dp[i - 1][j] + ad);
			}
		}
	}
	ll ans = min(dp[ps.size()-1][0], dp[ps.size()-1][1]);
	/*rep(i, ps.size()) {
		cout << dp[i][0] << " " << dp[i][1] << "\n";
	}
	rep(i, ps.size()) {
		cout << "start " << i << "\n";
		rep(j, ps[i].size()) {
			cout << ps[i][j].first << " " << ps[i][j].second << "\n";
		}
	}*/
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(15);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}