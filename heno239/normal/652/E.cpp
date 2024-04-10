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
const ll mod = 998244353;
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

ll gcd(ll a, ll b) {
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


struct LowLink {
private:
	vector<vector<int>> G;
	vector<int> used, ord, low;
	vector<int> art;
	vector<P> bridge;

	//make graph with bridge
	vector<vector<int>> fG;
	vector<vector<int>> ori;
	vector<int> trans;
public:
	LowLink(int n) {
		G.resize(n);
		used.resize(n, 0);
		ord.resize(n, 0);
		low.resize(n, 0);
	}
	void add_edge(int a, int b) {
		if (a == b)return;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int dfs(int id, int k, int par) {
		used[id] = true;
		ord[id] = k++;
		low[id] = ord[id];
		bool is_art = false;
		int cnt = 0;
		for (auto&& to : G[id]) {
			if (!used[to]) {
				++cnt;
				k = dfs(to, k, id);
				low[id] = min(low[id], low[to]);
				if (~par && low[to] >= ord[id])is_art = true;
				if (ord[id] < low[to])bridge.emplace_back(minmax(id, to));
			}
			else if (to != par) {
				low[id] = min(low[id], ord[to]);
			}
		}
		if (par == -1 && cnt > 1)is_art = true;
		if (is_art)art.push_back(id);
		return k;
	}
	void complete() {
		int k = 0;
		rep(i, G.size()) {
			if (!used[i]) {
				k = dfs(i, k, -1);
			}
		}

		//if there is mutiple edge
		map<P, bool> era;
		rep(i, G.size()) {
			sort(all(G[i]));
			rep1(j, (int)G[i].size() - 1) {
				if (G[i][j] == G[i][j - 1]) {
					era[minmax(i, G[i][j])] = true;
				}
			}
		}
		vector<P> cop = bridge; bridge.clear();
		for (P p : cop) {
			if (era[p])continue;
			bridge.push_back(p);
		}
	}
	vector<P> bs() {
		return bridge;
	}

	void makegraph_bridge() {
		map<P, bool> pused;
		for (P p : bridge) {
			pused[minmax(p.first, p.second)] = true;
		}
		fill(all(used), false);
		int tmp = 0;

		int n = G.size();
		trans.resize(n);
		rep(i, n) {
			if (used[i])continue;
			vector<int> ids, tos;
			queue<int> q; q.push(i);
			used[i] = true;
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				ids.push_back(cur);
				for (int to : G[cur]) {
					if (pused[minmax(cur, to)]) {
						tos.push_back(to);
						continue;
					}
					if (used[to])continue;
					used[to] = true;
					q.push(to);
				}
			}
			ori.push_back(ids);
			fG.push_back(tos);
			for (int id : ids) {
				trans[id] = tmp;
			}
			tmp++;
		}
		rep(i, tmp) {
			for (int& to : fG[i]) {
				to = trans[to];
			}
		}
	}
	bool query(int a, int b, vector<P> mks) {
		a = trans[a];
		b = trans[b];
		vector<bool> isroad(fG.size());
		isroad[a] = isroad[b] = true;
		function<bool(int, int)> dfs = [&](int id, int fr) {
			if (id == b)return true;
			for (int to : fG[id])if (to != fr) {
				if (dfs(to, id)) {
					isroad[id] = true;
					return true;
				}
			}
			return false;
		};
		assert(dfs(a, -1));
		for (P p : mks) {
			int x = p.first, y = p.second;
			x = trans[x], y = trans[y];
			if (isroad[x] && isroad[y])return true;
		}
		return false;
	}
};

void solve() {
	int n, m; cin >> n >> m;
	vector<int> x(m), y(m), z(m);
	rep(i, m) {
		cin >> x[i] >> y[i] >> z[i];
		x[i]--; y[i]--;
	}
	int a, b; cin >> a >> b; a--; b--;
	LowLink lt(n);
	rep(i, m) {
		lt.add_edge(x[i], y[i]);
	}
	lt.complete();
	lt.makegraph_bridge();
	vector<P> mks;
	rep(i, m)if (z[i])mks.push_back({ x[i],y[i] });
	bool ans = lt.query(a, b, mks);
	if (ans)cout << "YES\n";
	else cout << "NO\n";
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