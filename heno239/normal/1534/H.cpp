
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
const int max_n = 1 << 1;
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

bool comp(P a, P b) {
	if (a.second != b.second)return a.second < b.second;
	return a.first < b.first;
}

struct lcagraph {
private:
	int n;
	vector<vector<int>> G;
	vector<vector<int>> parent;
	vector<int> depth;
	int root;
	int tmp;
public:
	lcagraph(int n_, int _root) {
		n = n_;
		G.resize(n);
		parent.resize(n);
		depth.resize(n);
		tmp = 0;
		int cop = n;
		while (cop) {
			tmp++; cop /= 2;
		}
		rep(i, n)parent[i].resize(tmp);
		root = _root;
	}
	lcagraph() {}
	void init(int n_, int _root) {
		n = n_;
		G.resize(n);
		parent.resize(n);
		depth.resize(n);
		tmp = 0;
		int cop = n;
		while (cop) {
			tmp++; cop /= 2;
		}
		rep(i, n)parent[i].resize(tmp);
		root = _root;
	}
	void add_edge(int a, int b) {
		G[a].push_back(b);
		G[b].push_back(a);
	}
	void dfs(int id, int fr, int d) {
		parent[id][0] = fr;
		depth[id] = d;
		rep(j, G[id].size()) {
			int to = G[id][j];
			if (to == fr)continue;
			dfs(to, id, d + 1);
		}
	}
	void complete(int r = 0) {
		root = r;
		dfs(root, -1, 0);
		rep(j, tmp - 1)rep(i, n) {
			if (parent[i][j] < 0)parent[i][j + 1] = -1;
			else parent[i][j + 1] = parent[parent[i][j]][j];
		}
	}
	int lca(int u, int v) {
		if (depth[u] > depth[v])swap(u, v);
		for (int k = 0; k < tmp; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				v = parent[v][k];
			}
		}
		if (u == v)return u;
		for (int k = tmp - 1; k >= 0; k--) {
			if (parent[u][k] != parent[v][k]) {
				u = parent[u][k];
				v = parent[v][k];
			}
		}
		return parent[u][0];
	}
	int dep(int x) {
		return depth[x];
	}
	int dist(int x, int y) {
		int l = lca(x, y);
		return depth[x] + depth[y] - 2 * depth[l];
	}
};


const int mn = 1 << 17;
struct edge {
	int to;
};
using Data = int;
vector<edge> G[mn];
vector<int> ids[mn];
vector<Data> memo[mn];
int root;


Data dfs(int id, int fr) {
	Data res;
	//
	//initialize
	//
	res = 1;
	for (edge e : G[id]) {
		if (e.to == fr)continue;
		Data nex = dfs(e.to, id);
		//
		//update with edge
		//
		ids[id].push_back(e.to);
		memo[id].push_back(nex);
	}
	//
	//update for return
	vector<int> cop = memo[id];
	sort(all(cop), greater<int>());
	rep(i, cop.size()) {
		res = max(res, i + cop[i]);
	}
	//
	return res;
}

int ma = -1;
void invdfs(int id, int fr, Data pre) {
	vector<Data> v;
	for (Data d : memo[id])v.push_back(d);
	if (fr >= 0)v.push_back(pre);
	int len = v.size();
	//
	//calcurate id's ans
	vector<int> vs = v;
	sort(all(vs), greater<int>());
	if (vs.size() >= 1) {
		ma = max(ma, (int)vs.size() + vs[0] - 1);
	}
	if (vs.size() >= 2) {
		for (int i = 1; i < vs.size(); i++) {
			int val = vs[i] + i + vs[0] - 1;
			ma = max(ma, val);
		}
	}

	vector<P> ps;
	rep(j, memo[id].size()) {
		ps.push_back({ memo[id][j],ids[id][j] });
	}
	ps.push_back({ pre,-1 });
	sort(all(ps), greater<P>());
	vector<int> le(ps.size() + 1, 0);
	vector<int> ri(ps.size() + 1, 0);
	rep(j, ps.size()) {
		le[j + 1] = max(le[j], ps[j].first + j);
	}
	per(j, (int)ps.size()) {
		ri[j] = max(ri[j + 1], ps[j].first + j - 1);
	}
	rep(j, ps.size()) {
		int to = ps[j].second; 
		if (to < 0)continue;
		int val = max(le[j], ri[j + 1]);
		val = max(val, 1);

		invdfs(to, id, val);
	}
}
void yaru() {
	dfs(root, -1);
	invdfs(root, -1, 0);
}

int query(int a) {
	cout << "? ";
	cout << a + 1 << endl;
	int res; cin >> res; res--;
	return res;
}
void ansquery(int a, int b) {
	if (a > b)swap(a, b);
	cout << "! " << a + 1 << " " << b + 1 << endl;
}
void solve() {
	int n; cin >> n;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back({ b });
		G[b].push_back({ a });
	}
	if (n == 1) {
		cout << 0 << endl;
	}
	else if (n == 2) {
		cout << 1 << endl;
	}
	else {
		yaru();
		cout << ma << endl;
	}
	int root; cin >> root; root--;
	if (n == 1) {
		cout << "! 1 1" << endl; return;
	}

	vector<vector<P>> memo(n);
	function<P(int, int)> dfs = [&](int id, int fr)->P {
		for (edge e : G[id])if (e.to != fr) {
			P p = dfs(e.to, id);
			memo[id].push_back(p);
		}
		sort(all(memo[id]), greater<P>());
		if (memo[id].empty()) {
			return { 1,id };
		}
		else {
			int ma = 0;
			rep(i, memo[id].size()) {
				ma = max(ma, i + memo[id][i].first);
			}
			return { ma,memo[id][0].second };
		}
	};
	dfs(root, -1);
	vector<int> ans;
	vector<bool> used(n);
	auto find_ans = [&](int p) {
		while (true) {
			bool fin = false;
			bool exi = false;
			rep(j, memo[p].size()) {
				if (used[memo[p][j].second])continue;
				exi = true;
				used[memo[p][j].second] = true;
				int v = query(memo[p][j].second);
				if (v != p) {
					p = v;
					break;
				}
				else {
					if (j == memo[p].size() - 1)fin = true;
				}
			}
			if (fin)break;
			if (!exi)break;
		}
		ans.push_back(p);
	};
	rep(i, memo[root].size()) {
		int v = query(memo[root][i].second);
		used[memo[root][i].second] = true;
		if (v != root) {
			find_ans(v);
			if (ans.size() == 2)break;
		}
	}
	while (ans.size() < 2)ans.push_back(root);
	ansquery(ans[0], ans[1]);
}


signed main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init(); cout << ps.size() << "\n";
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}