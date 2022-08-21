

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
};


int n, m;
void solve() {
	LowLink lt(n);
	rep(i, m) {
		int len; cin >> len;
		vector<int> v(len);
		rep(j, len) {
			cin >> v[j]; v[j]--;
		}
		rep(j, len - 1) {
			lt.add_edge(v[j], v[j + 1]);
		}
	}
	lt.complete();
	vector<P> bs = lt.bs();
	vector<vector<int>> G(n);
	rep(i, bs.size()) {
		G[bs[i].first].push_back(bs[i].second);
		G[bs[i].second].push_back(bs[i].first);
	}
	vector<P> ans;
	vector<bool> used(n);
	function<int(int, int)> dfs = [&](int id, int fr)->int {
		used[id] = true;
		vector<int> v1, v2;
		for (int to : G[id])if (to != fr) {
			int nex = dfs(to, id);
			if (nex == to)v1.push_back(nex);
			else v2.push_back(nex);
		}
		while (v2.size() >= 2) {
			int a = v2.back(); v2.pop_back();
			int b = v2.back(); v2.pop_back();
			ans.push_back({ a,b });
		}
		if (v2.size())v1.push_back(v2[0]);
		while (v1.size() > 2) {
			int a = v1.back(); v1.pop_back();
			int b = v1.back(); v1.pop_back();
			ans.push_back({ a,b });
		}
		if (v1.size() == 1)return v1[0];
		else if (v1.size() == 0)return id;
		else {
			if (fr< 0) {
				ans.push_back({ v1[0],v1[1] });
				return id;
			}
			return v1[1];
		}
	};
	rep(i, n) {
		if (used[i])continue;
		if (G[i].size() == 1)continue;
		int t = dfs(i, -1);
		bool ad = true;
		if (t == i)ad = false;
		for (int to : G[i])if (to == t)ad = false;
		if (ad)ans.push_back({ i,t });
	}
	cout << ans.size() << "\n";
	rep(i, ans.size()) {
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();

	//int t; cin >> t; rep(i, t)
	while (cin >> n >> m, n) {
		solve();
	}
	return 0;
}