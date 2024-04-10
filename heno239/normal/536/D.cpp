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
constexpr ll mod = 1000000009;
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
const int max_n = 1 << 15;
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

ll dp[2005][2005][2];
ll rdp[2005][2005][2];

using ar = array<ll, 2>;
ar operator+=(ar& a, ar b) {
	rep(i, 2)a[i] += b[i]; return a;
}
ar operator-=(ar& a, ar b) {
	rep(i, 2)a[i] -= b[i]; return a;
}

ar sum[2005][2005];
void solve() {
	int n, m; cin >> n >> m;
	int s, t; cin >> s >> t; s--; t--;
	vector<ll> p(n);
	rep(i, n)cin >> p[i];
	vector<ll> dists(n, INF), distt(n, INF);
	struct edge {
		int to; ll cost;
	};
	vector<vector<edge>> G(n);
	rep(i, m) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
	}
	priority_queue<LP, vector<LP>, greater<LP>> q;
	dists[s] = 0; q.push({ 0,s });
	while (!q.empty()) {
		LP p = q.top(); q.pop();
		int id = p.second;
		if (dists[id] < p.first)continue;
		for (edge e : G[id]) {
			ll nd = e.cost + p.first;
			if (nd < dists[e.to]) {
				dists[e.to] = nd;
				q.push({ nd,e.to });
			}
		}
	}
	distt[t] = 0; q.push({ 0,t });
	while (!q.empty()) {
		LP p = q.top(); q.pop();
		int id = p.second;
		if (distt[id] < p.first)continue;
		for (edge e : G[id]) {
			ll nd = e.cost + p.first;
			if (nd < distt[e.to]) {
				distt[e.to] = nd;
				q.push({ nd,e.to });
			}
		}
	}
	vector<ll> vx, vy;
	rep(i, n) {
		vx.push_back(dists[i]);
		vy.push_back(distt[i]);
	}
	sort(all(vx)); vx.erase(unique(all(vx)), vx.end());
	sort(all(vy)); vy.erase(unique(all(vy)), vy.end());
	rep(i, n) {
		int idx = lower_bound(all(vx), dists[i]) - vx.begin();
		int idy = lower_bound(all(vy), distt[i]) - vy.begin();
		sum[idx][idy] += {1, p[i]};
	}
	rep(i, vx.size() + 1)rep(j, vy.size() + 1) {
		if (i > 0)sum[i][j] += sum[i - 1][j];
		if (j > 0)sum[i][j] += sum[i][j - 1];
		if (i > 0 && j > 0)sum[i][j] -= sum[i - 1][j - 1];
	}
	auto calc = [&](int lx, int ly, int rx, int ry) {
		ar res = sum[rx][ry];
		if (lx > 0)res -= sum[lx - 1][ry];
		if (ly > 0)res -= sum[rx][ly - 1];
		if (lx > 0 && ly > 0)res += sum[lx - 1][ly - 1];
		return res;
	};
	//cout << vx.size() << " " << vy.size() << "\n";
	rep(j, vy.size())rdp[vx.size()][j][1] = -INF;
	rep(i, vx.size())rdp[i][vy.size()][0] = INF;
	per(i, vx.size())per(j, vy.size()) {
		//update dp
		ar a = calc(i, j, vx.size(), vy.size());
		if (a[0] == 0) {
			dp[i][j][0] = dp[i][j][1] = 0;
			rdp[i][j][0] = INF;
			rdp[i][j][1] = -INF;
		}
		else {
			//0
			a = calc(i, j, i, vy.size());
			if (a[0] == 0) {
				dp[i][j][0] = dp[i + 1][j][0];
			}
			else {
				dp[i][j][0] = max(rdp[i + 1][j][1], dp[i + 1][j][1]) + a[1];
			}
			//1
			a = calc(i, j, vx.size(), j);
			if (a[0] == 0) {
				dp[i][j][1] = dp[i][j + 1][1];
			}
			else {
				dp[i][j][1] = min(rdp[i][j + 1][0], dp[i][j + 1][0]) - a[1];
			}
		}
		//update rdp
		//0
		a = calc(i, j, vx.size(), j);
		if (a[0] == 0) {
			rdp[i][j][0] = rdp[i][j + 1][0];
		}
		else {
			rdp[i][j][0] = min(rdp[i][j + 1][0], dp[i][j + 1][0]) - a[1];
		}
		//1
		a = calc(i, j, i, vy.size());
		if (a[0] == 0) {
			rdp[i][j][1] = rdp[i + 1][j][1];
		}
		else {
			rdp[i][j][1] = max(rdp[i + 1][j][1], dp[i + 1][j][1]) + a[1];
		}
	}
	//cout << rdp[1][0][1] << "\n";
	ll val = dp[0][0][0];
	//cout << val << "\n";
	if (val > 0) {
		cout << "Break a heart" << "\n";
	}
	else if (val < 0) {
		cout << "Cry" << "\n";
	}
	else {
		cout << "Flowers" << "\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(12);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}