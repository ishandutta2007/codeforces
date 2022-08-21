#pragma GCC target("avx2")
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
const ld eps = 1e-6;
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
const int max_n = 1 << 21;
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
	bool can(vector<P> vq) {
		int q = vq.size();
		//rep(i, G.size())cout << trans[i] << "\n";
		rep(i, q) {
			vq[i].first = trans[vq[i].first];
			vq[i].second = trans[vq[i].second];
			//cout << "? " << vq[i].first << " " << vq[i].second << "\n";
		}
		vector<vector<int>> ids;
		int n = fG.size();
		vector<bool> used(n);
		vector<int> loc(n);
		vector<int> tra(n);

		vector<vector<int>> par(n, vector<int>(18));
		vector<int> depth(n);
		rep(i, n) {
			if (used[i])continue;
			queue<int> q;
			q.push(i); used[i] = true;
			par[i][0] = -1;
			vector<int> cur;
			while (!q.empty()) {
				int v = q.front(); q.pop();
				cur.push_back(v);
				for (int to : fG[v]) {
					if (!used[to]) {
						used[to] = true;
						q.push(to);
						par[to][0] = v;
						depth[to] = depth[v] + 1;
					}
				}
			}
			rep(j, cur.size()) {
				tra[cur[j]] = j;
				loc[cur[j]] = ids.size();
			}
			ids.push_back(cur);
		}
		
		rep(j, 17) {
			rep(i, n) {
				if (par[i][j] >= 0) {
					par[i][j + 1] = par[par[i][j]][j];
				}
				else {
					par[i][j + 1] = -1;
				}
			}
		}
		auto lca = [&](int a, int b) {
			if (depth[a] > depth[b])swap(a, b);
			int dif = depth[b] - depth[a];
			rep(j, 18)if (dif & (1 << j)) {
				b = par[b][j];
			}
			if (a == b)return a;
			per(j, 18) {
				if (par[a][j] != par[b][j]) {
					a = par[a][j];
					b = par[b][j];
				}
			}
			return par[a][0];
		};
		vector<int> ad1(n), ad2(n);
		rep(i, q) {
			if (loc[vq[i].first] != loc[vq[i].second])return false;
			int a = vq[i].first, b = vq[i].second;
			int l = lca(a, b);
			ad1[a]++;
			ad1[l]--;
			ad2[b]++;
			ad2[l]--;
		}
		vector<int> c1(n), c2(n);
		rep(i, ids.size()) {
			per(j, ids[i].size()) {
				int id = ids[i][j];
				c1[id] += ad1[id];
				c2[id] += ad2[id];
				if (c1[id] > 0 && c2[id] > 0)return false;
				if (par[id][0] >= 0) {
					c1[par[id][0]] += c1[id];
					c2[par[id][0]] += c2[id];
				}
			}
		}
		return true;
	}
};


void solve() {
	int n, m, q; cin >> n >> m >> q;
	LowLink lt(n);
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		lt.add_edge(a, b);
	}
	lt.complete();
	lt.makegraph_bridge();
	vector<P> vq(q);
	rep(i, q) {
		int s, t; cin >> s >> t; s--; t--;
		vq[i] = { s,t };
	}
	bool ans = lt.can(vq);
	if (ans)cout << "Yes\n";
	else cout << "No\n";
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