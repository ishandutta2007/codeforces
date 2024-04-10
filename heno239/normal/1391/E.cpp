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
#include<utility>
#include<cassert>
#include<complex>
#include<numeric>
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
const ld pi = acos(-1.0);

ll mod_pow(ll x, ll n, ll m) {
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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> G(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<bool> used(n, false);
	vector<vector<int>> g(n);
	function<void(int)> dfs = [&](int id) {
		for (int to : G[id]) {
			if (used[to])continue;
			g[id].push_back(to);
			g[to].push_back(id);
			used[to] = true;
			dfs(to);
		}
	};
	used[0] = true;
	dfs(0);

	vector<int> par(n);
	vector<int> dist(n, mod);
	auto mostfar = [&](int r)->int {
		fill(all(dist), mod);
		dist[r] = 0;
		queue<int> q; q.push(r);
		int res;
		while (!q.empty()) {
			int id = q.front(); q.pop();
			res = id;
			for (int to : g[id]) {
				if (dist[id] + 1 < dist[to]) {
					dist[to] = dist[id] + 1;
					q.push(to);
					par[to] = id;
				}
			}
		}
		return res;
	};
	int l = 0;
	int r = mostfar(l);
	l = mostfar(r);
	vector<int> road;
	int cur = l;
	while (cur != r) {
		road.push_back(cur);
		cur = par[cur];
	}
	road.push_back(r);
	if (road.size() >= (n + 1) / 2) {
		cout << "PATH\n";
		cout << road.size() << "\n";
		rep(i, road.size()) {
			if (i > 0)cout << " ";
			cout << road[i] + 1;
		}
		cout << "\n"; return;
	}
	mostfar(0);
	vector<P> vs;
	vector<vector<int>> loc(n);
	rep(i, n) {
		loc[dist[i]].push_back(i);
	}
	rep(i, n) {
		rep(j, loc[i].size() / 2) {
			vs.push_back({ loc[i][2 * j],loc[i][2 * j + 1] });
		}
	}
	assert(vs.size() * 2 >= (n + 1) / 2);
	cout << "PAIRING\n";
	cout << vs.size() << "\n";
	rep(i, vs.size()) {
		cout << vs[i].first+1 << " " << vs[i].second + 1 << "\n";
	}
}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//expr();
	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}