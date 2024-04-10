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
const ll mod = 1000000007;
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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-4;
const ld pi = acosl(-1.0);

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
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

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct uf {
private:
	vector<int> par, ran;
public:
	uf(int n) {
		par.resize(n, 0);
		ran.resize(n, 0);
		rep(i, n) {
			par[i] = i;
		}
	}
	int find(int x) {
		if (par[x] == x)return x;
		else return par[x] = find(par[x]);
	}
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y)return;
		if (ran[x] < ran[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (ran[x] == ran[y])ran[x]++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

struct edge {
	int to, cost;
};

int par[1 << 18][18];
int cost[1 << 18][18];
int dep[1 << 18];
void solve() {
	int n, m; cin >> n >> m;
	vector<pair<P, P>> vp;
	rep(i, m) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		vp.push_back({ {c,i},{a,b} });
	}
	sort(all(vp));
	ll sum = 0;
	uf u(n);
	vector<vector<edge>> G(n);
	vector<bool> nwuse(vp.size());
	rep(i,vp.size()){
		auto p = vp[i];
		int a = p.second.first;
		int b = p.second.second;
		if (!u.same(a, b)) {
			u.unite(a, b);
			int c = p.first.first;
			G[a].push_back({ b,c });
			G[b].push_back({ a,c });
			sum += c;
			nwuse[i] = true;
		}
	}
	par[0][0] = -1;
	function<void(int, int)> dfs = [&](int id, int fr) {
		for (edge e : G[id])if (e.to != fr) {
			par[e.to][0] = id;
			cost[e.to][0] = e.cost;
			dep[e.to] = dep[id] + 1;
			dfs(e.to, id);
		}
	};
	dfs(0, -1);
	rep(j, 17) {
		rep(i, n) {
			if (par[i][j] < 0)par[i][j + 1] = -1;
			else {
				par[i][j + 1] = par[par[i][j]][j];
				cost[i][j + 1] = max(cost[i][j], cost[par[i][j]][j]);
			}
		}
	}
	auto query = [&](int a, int b) {
		int res = 0;
		if (dep[a] > dep[b])swap(a, b);
		int dif = dep[b] - dep[a];
		rep(j, 18) {
			if (dif & (1 << j)) {
				res = max(res, cost[b][j]);
				b = par[b][j];
			}
		}
		per(j, 18) {
			if (par[a][j] != par[b][j]) {
				res = max(res, cost[a][j]);
				res = max(res, cost[b][j]);
				a = par[a][j];
				b = par[b][j];
			}
		}
		if (a != b) {
			res = max(res, cost[a][0]);
			res = max(res, cost[b][0]);
		}
		return res;
	};
	vector<ll> ans(m);
	rep(i, vp.size()) {
		int a = vp[i].second.first;
		int b = vp[i].second.second;
		int id = vp[i].first.second;
		int cost = vp[i].first.first;
		int z = query(a, b);
		ans[id] = sum;
		if (z < cost)ans[id] += cost - z;
	}
	rep(i, m)cout << ans[i] << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//while(true)
	//expr();
	//int t; cin >> t; rep(i, t)
		solve();
	return 0;
}