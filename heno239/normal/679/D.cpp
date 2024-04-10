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
const int max_n = 1 << 16;
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

int dist[400][400];
ld ma[400][400];
ld score[400];

ld rg[401];
void solve() {
	int n, m; cin >> n >> m;
	rep(i, n)rep(j, n) {
		if (i != j)dist[i][j] = mod;
	}
	vector<vector<int>> G(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		dist[a][b] = dist[b][a] = 1;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	rep1(i, n)rg[i] = 1 / (ld)i;
	rep(k, n)rep(i, n)rep(j, n) {
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	}
	ld ans = 0;
	rep(i, n) {
		vector<vector<int>> ids(n);
		rep(j, n) {
			ids[dist[i][j]].push_back(j);
		}
		ld p = rg[n];
		vector<ld> sum(n);
		vector<bool> used(n);
		for (int d = 1; d < n; d++) {
			if (ids[d].empty())continue;
			fill(all(sum), 0);
			fill(all(used), false);
			vector<int> sid;
			for (int id : ids[d]) {
				for (int to : G[id]) {
					used[to] = true;
					sum[to] += rg[n] * rg[G[id].size()];
				}
			}
			rep(j, n)if (used[j]) {
				rep(k, n) {
					int d = dist[j][k];
					if (ma[k][d] < sum[j]) {
						score[k] += sum[j] - ma[k][d];
						ma[k][d] = sum[j];
					}
				}
			}
			ld m =rg[n];
			rep(j, n) {
				m = max(m, score[j]);
			}
			p += m;
			rep(j, n)if (used[j]) {
				rep(k, n) {
					int d = dist[j][k];
					ma[k][d] = 0;
					score[k] = 0;
				}
			}
		}
		ans = max(ans, p);
	}
	cout << ans << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i,t)
	//while(cin>>n,n)
	//solve();
	//expr();
	//init();
	solve();
	return 0;
}