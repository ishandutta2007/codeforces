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

P dist[200][200];
struct edge {
	int to, cost;
};
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<edge>> G(n);
	rep(i, m) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		if (c) {
			G[a].push_back({ b,1 });
			G[b].push_back({ a,-1 });
		}
		else {
			G[a].push_back({ b,0 });
			G[b].push_back({ a,0 });
		}
	}
	vector<int> col(n);
	vector<bool> used(n);
	queue<int> que;
	que.push(0); used[0] = true;
	while (!que.empty()) {
		int v = que.front(); que.pop();
		for (edge e : G[v]) {
			if (used[e.to]) {
				if (col[e.to] != col[v] ^ 1) {
					cout << "NO\n"; return;
				}
			}
			else {
				used[e.to] = true;
				col[e.to] = col[v] ^ 1;
				que.push(e.to);
			}
		}
	}

	rep(i, n)rep(j, n) {
		if (i == j)dist[i][j] = { 0,0 };
		else dist[i][j] = { -mod,mod };
	}
	rep(i, n)for (edge e : G[i]) {
		if (e.cost == 0) {
			dist[i][e.to] = { -1,1 };
		}
		else {
			dist[i][e.to] = { e.cost,e.cost };
		}
	}
	rep(k, n)rep(i, n)rep(j, n) {
		P x = dist[i][k];
		P y = dist[k][j];
		P& z = dist[i][j];
		z.first = max(z.first, x.first + y.first);
		z.second = min(z.second, x.second + y.second);
	}
	int ma = -1;
	int ci = -1, cj = -1, ck = -1;
	rep(i, n)rep(j, n){
		if (dist[i][j].first > dist[i][j].second) {
			cout << "NO\n"; return;
		}
		if (abs(dist[i][j].first) > ma) {
			ma = abs(dist[i][j].first);
			ci = i, cj = j; ck = 0;
		}
		if (abs(dist[i][j].second) > ma) {
			ma = abs(dist[i][j].second);
			ci = i, cj = j; ck = 1;
		}
	}
	vector<int> ans(n);
	int r = -1;
	if (ck==0) {
		if (dist[ci][cj].first < 0) {
			ans[cj] = 0;
			ans[ci] = ma;
			r = cj;
		}
		else {
			ans[ci] = 0;
			ans[cj] = ma;
			r = ci;
		}
	}
	else {
		if (dist[ci][cj].second< 0) {
			ans[cj] = 0;
			ans[ci] = ma;
			r = cj;
		}
		else {
			ans[ci] = 0;
			ans[cj] = ma;
			r = ci;
		}
	}
	if (ck==0) {
		dist[ci][cj].second = dist[ci][cj].first;
		dist[cj][ci].first = dist[cj][ci].second;
	}
	else {
		dist[ci][cj].first = dist[ci][cj].second;
		dist[cj][ci].second = dist[cj][ci].first;
	}
	rep(k, n)rep(i, n)rep(j, n) {
		P x = dist[i][k];
		P y = dist[k][j];
		P& z = dist[i][j];
		z.first = max(z.first, x.first + y.first);
		z.second = min(z.second, x.second + y.second);
	}
	rep(i, n)if (r != i) {
		ans[i] = dist[r][i].first;
	}
	cout << "YES\n";
	cout << ma << "\n";
	rep(i, n) {
		if (i > 0)cout << " "; cout << ans[i];
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(15);
	init_f();
	//init();
	//expr();
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}