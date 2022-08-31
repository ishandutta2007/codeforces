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

int dp[100][1 << 14];

int dist[100][1 << 14];
int sdist[14][1 << 14];

int zmi[105][1 << 14];
void solve() {
	int n, m; cin >> n >> m;
	vector<int> x(n), y(n);
	rep(i, n)cin >> x[i] >> y[i];
	vector<int> xb(m), yb(m), t(m);
	rep(i, m) {
		cin >> xb[i] >> yb[i] >> t[i];
	}
	vector<pair<int, P>> vp;
	rep(i, m)vp.push_back({ t[i],{xb[i],yb[i]} });
	sort(all(vp));
	rep(i, m) {
		xb[i] = vp[i].second.first;
		yb[i] = vp[i].second.second;
		t[i] = vp[i].first;
	}


	rep(i, m + 1)rep(j, (1 << n))zmi[i][j] = mod;
	rep(i, m)rep(j, (1 << n)) {
		dp[i][j] = -mod;
	}
	//init
	rep(i, m) {
		dp[i][0] = 1;
	}
	vector<int> d(1 << n,mod);
	d[0] = 0;
	rep(i, n)d[(1 << i)] = 0;
	rep(i, (1 << n)) {
		rep(j, m) {
			dist[j][i] = mod;
			rep(k, n)if (i & (1 << k)) {
				dist[j][i] = min(dist[j][i], abs(xb[j] - x[k]) + abs(yb[j] - y[k]));
			}
		}
	}
	rep(i, n)rep(j, (1 << n)) {
		sdist[i][j] = mod;
		rep(k, n)if (j & (1 << k)) {
			sdist[i][j] = min(sdist[i][j], abs(x[i] - x[k]) + abs(y[i] - y[k]));
		}
	}
	rep(i, (1 << n)) {
		if (i == 0)continue;
		rep(j, n) {
			if (i & (1 << j))continue;
			int mi = mod;
			rep(k, n)if (i & (1 << k)) {
				mi = min(mi, abs(x[k] - x[j]) + abs(y[k] - y[j]));
			}
			d[i ^ (1 << j)] = min(d[i ^ (1 << j)], d[i] + mi);
		}
		rep(j, m) {
			if (d[i] + dist[j][i] <= t[j]) {
				dp[j][i] = 1;
			}
		}
	}
	vector<int> midp(1 << n);
	rep(j, m) {
		rep(i, j + 2)rep(s, (1 << n)) {
			if (zmi[i][s] + dist[j][s] <= t[j]) {
				dp[j][s] = max(dp[j][s], i);
			}
		}
		vector<P> v;
		rep(i, (1 << n)) {
			if (dp[j][i] < 0)continue;
			v.push_back({ dp[j][i],i });
			//not add
			Rep(k, j + 1, m) {
				int di = dist[k][i];
				di = min(di, abs(xb[j] - xb[k]) + abs(yb[j] - yb[k]));
				if (t[j] + di <= t[k]) {
					dp[k][i] = max(dp[k][i], dp[j][i]+1);
				}
			}
		}
		sort(all(v));
		rep(i, v.size()) {
			int le = i;
			while (i + 1 < v.size() && v[i].first == v[i + 1].first)i++;
			fill(all(midp), mod);
			int z = v[i].first;
			Rep1(k, le, i) {
				int s = v[k].second;
				midp[s] = t[j];
				rep(l, n) {
					if (s & (1 << l))continue;
					midp[s ^ (1 << l)] = min(midp[s ^ (1 << l)], t[j] + dist[j][1 << l]);
				}
			}
			rep(k, (1 << n)) {
				if (midp[k] >= mod)continue;
				rep(l, n) {
					if (k & (1 << l))continue;
					midp[k ^ (1 << l)] = min(midp[k ^ (1 << l)], midp[k] + sdist[l][k]);
				}
				zmi[z + 1][k] = min(zmi[z + 1][k], midp[k]);
			}
		}
	}
	int ans = 0;
	rep(i, m)rep(j, (1 << n))ans = max(ans, dp[i][j]);
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