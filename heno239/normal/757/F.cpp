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
const int max_n = 1<<1;
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

struct edge {
	int to, cost;
};
void solve() {
	int n, m, s; cin >> n >> m >> s; s--;
	vector<vector<edge>> G(n);
	rep(i, m) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		G[a].push_back({ b,c });
		G[b].push_back({ a,c });
	}
	vector<ll> dist(n, INF);
	dist[s] = 0;
	priority_queue<LP, vector<LP>, greater<LP>> q;
	q.push({ 0,s });
	while (!q.empty()) {
		LP p = q.top(); q.pop();
		int id = p.second;
		if (p.first > dist[id])continue;
		for (edge e : G[id]) {
			ll nd = e.cost + p.first;
			if (nd < dist[e.to]) {
				dist[e.to] = nd;
				q.push({ nd,e.to });
			}
		}
	}
	vector<vector<int>> g(n);
	vector<vector<int>> rg(n);
	rep(i, n)for (edge e : G[i]) {
		if (dist[i] + e.cost == dist[e.to]) {
			g[i].push_back(e.to);
			rg[e.to].push_back(i);
			//cout << "! " << i << " " << e.to << "\n";
		}
	}
	//rep(i, n)cout << dist[i] << "\n";
	vector<int> ord;
	vector<int> cnt(n);
	queue<int> que;
	rep(i, n) {
		for (int to : g[i])cnt[to]++;
	}
	rep(i, n) {
		if (cnt[i] == 0) {
			que.push(i);
		}
	}
	while (!que.empty()) {
		int id = que.front(); que.pop();
		ord.push_back(id);
		for (int to : g[id]) {
			cnt[to]--;
			if (cnt[to] == 0) {
				que.push(to);
			}
		}
	}
	auto merge = [&](int a, int b) {
		if (a == b)return a;
		else return s;
	};
	vector<int> par(n);
	
	for (int id : ord) {
		if (rg[id].empty())continue;
		//cout << "?? " << id << "\n";
		if (id == s) {
			par[id] = s;
			continue;
		}
		if (rg[id].size() == 1) {
			if (rg[id][0] == s) {
				par[id] = id;
			}
			else {
				par[id] = par[rg[id][0]];
			}
		}
		else {
			int p = par[rg[id][0]];
			for (int to : rg[id]) {
				p = merge(p, par[to]);
			}
			if (p == s) {
				par[id] = id;
			}
			else {
				par[id] = p;
			}
		}
	}
	fill(all(cnt), 0);
	rep(i, n) {
		if (dist[i] == INF || s == i)continue;
		cnt[par[i]]++;
	}
	int ans = 0;
	rep(i, n)ans = max(ans, cnt[i]);
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i, t)
	solve();
	return 0;
}