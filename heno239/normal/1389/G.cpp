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
constexpr ll mod = 998244353;
//constexpr ll mod = 1000000007;
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

template<typename T>
void chmin(T& a, T b) {
	a = min(a, b);
}
template<typename T>
void chmax(T& a, T b) {
	a = max(a, b);
}
template<typename T>
void cinarray(vector<T>& v) {
	rep(i, v.size())cin >> v[i];
}
template<typename T>
void coutarray(vector<T>& v) {
	rep(i, v.size()) {
		if (i > 0)cout << " "; cout << v[i];
	}
	cout << "\n";
}
void pout(P& p) {
	cout << p.first << " " << p.second << "\n";
}
void pout(LP& p) {
	cout << p.first << " " << p.second << "\n";
}
ll mod_pow(ll x, ll n, ll m = mod) {
	if (n < 0) {
		ll res = mod_pow(x, -n, m);
		return mod_pow(res, m - 2, m);
	}
	if (abs(x) >= m)x %= m;
	if (x < 0)x += m;
	//if (x == 0)return 0;
	ll res = 1;
	while (n) {
		if (n & 1)res = res * x % m;
		x = x * x % m; n >>= 1;
	}
	return res;
}
struct modint {
	int n;
	modint() :n(0) { ; }
	modint(ll m) {
		if (m < 0 || mod <= m) {
			m %= mod; if (m < 0)m += mod;
		}
		n = m;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
bool operator<(modint a, modint b) { return a.n < b.n; }
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
	a = abs(a); b = abs(b);
	if (a < b)swap(a, b);
	while (b) {
		ll r = a % b; a = b; b = r;
	}
	return a;
}
typedef long double ld;
typedef pair<ld, ld> LDP;
void pout(LDP& p) {
	cout << p.first << " " << p.second << "\n";
}
const ld eps = 1e-8;
const ld pi = acosl(-1.0);
template<typename T>
void addv(vector<T>& v, int loc, T val) {
	if (loc >= v.size())v.resize(loc + 1, 0);
	v[loc] += val;
}
/*const int mn = 100005;
bool isp[mn];
vector<int> ps;
void init() {
	fill(isp + 2, isp + mn, true);
	for (int i = 2; i < mn; i++) {
		if (!isp[i])continue;
		ps.push_back(i);
		for (int j = 2 * i; j < mn; j += i) {
			isp[j] = false;
		}
	}
}*/

//[,val)
template<typename T>
auto prev_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	if (res == st.begin())return st.end();
	res--; return res;
}

//[val,)
template<typename T>
auto next_itr(set<T>& st, T val) {
	auto res = st.lower_bound(val);
	return res;
}
using mP = pair<modint, modint>;

const string drul = "DRUL";
//DRUL
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//-----------------------------------------

struct LowLink {
//private:
	vector<vector<int>> G;
	vector<int> used, ord, low;
	vector<int> art;
	vector<P> bridge;

	//make graph with bridge
	vector<vector<int>> fG;
	vector<vector<int>> ori;
	vector<int> trans;
//public:
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

const int mn = 1 << 19;
struct edge {
	int to; ll cost;
};
using Data = ll;
vector<edge> G[mn];
vector<int> ids[mn];
vector<Data> memo[mn];
vector<ll> costs[mn];
int root;

Data merge(Data a, Data b) {
	Data res;
	//
	res = a + b;
	//
	return res;
}

ll oric[mn];
ll ansc[mn];
Data dfs(int id, int fr) {
	Data res;
	//
	//initialize
	res = oric[id];
	//
	for (edge e : G[id]) {
		if (e.to == fr)continue;
		Data nex = dfs(e.to, id);
		//
		//update with edge
		nex = max(0ll, nex - e.cost);
		//
		res = merge(res, nex);
		ids[id].push_back(e.to);
		memo[id].push_back(nex);
		costs[id].push_back(e.cost);
	}
	//
	//update for return
	//
	return res;
}
void invdfs(int id, int fr, Data pre) {
	vector<Data> v;
	for (Data d : memo[id])v.push_back(d);
	if (fr >= 0)v.push_back(pre);
	int len = v.size();
	//
	//calcurate id's ans
	Data nd = oric[id];
	for (Data d : v)nd = merge(nd, d);
	ansc[id] = nd;
	//
	vector<Data> le(len + 1);
	vector<Data> ri(len + 1);
	//
	Data init_c = 0;
	//
	le[0] = init_c;
	rep(i, len) {
		le[i + 1] = merge(le[i], v[i]);
	}
	ri[len] = init_c;
	per(i, len) {
		ri[i] = merge(ri[i + 1], v[i]);
	}
	rep(i, ids[id].size()) {
		int to = ids[id][i];
		Data d = merge(le[i], ri[i + 1]);

		//
		//update for return
		d += oric[id];
		d = max(0ll, d - costs[id][i]);
		//
		invdfs(to, id, d);
	}
}
void yaru() {
	dfs(root, -1);
	invdfs(root, -1, 0);
}

ll tra(P p) {
	return (ll)p.first * mod + p.second;
}
void solve(){
	int n, m, k; cin >> n >> m >> k;
	vector<int> v(k);
	rep(i, k) {
		cin >> v[i]; v[i]--;
	}
	vector<int> c(n);
	rep(i, n)cin >> c[i];
	vector<int> w(m);
	rep(i, m)cin >> w[i];
	vector<int> ex(m), ey(m);
	rep(i, m) {
		cin >> ex[i] >> ey[i]; ex[i]--; ey[i]--;
		if (ex[i] > ey[i])swap(ex[i], ey[i]);
	}
	unordered_map<ll, int> mpc;
	rep(i, m) {
		mpc[tra({ex[i], ey[i]})] = w[i];
		mpc[tra({ey[i], ex[i]})] = w[i];
	}
	LowLink lt(n);
	rep(i, m) {
		lt.add_edge(ex[i], ey[i]);
	}
	lt.complete();
	lt.makegraph_bridge();
	unordered_map<ll, int> mp;
	rep(i, n) {
		for (int to : lt.G[i]) {
			int cl = lt.trans[i];
			int cr = lt.trans[to];
			if (lt.trans[i] != lt.trans[to]) {
				mp[tra({cl, cr})] = mpc[tra({i, to})];
			}
		}
	}
	vector<int> ori(lt.fG.size());

	rep(i, n)oric[lt.trans[i]] += c[i];
	for (int id : v) {
		ori[lt.trans[id]]++;
	}
	vector<int> sz(lt.fG.size());
	function<void(int, int)> initdfs = [&](int id, int fr) {
		sz[id] = ori[id];
		for (int to : lt.fG[id])if(to!=fr) {
			initdfs(to, id);
			sz[id] += sz[to];

			ll cost = mp[tra({id, to})];
			if (sz[to] == 0 || sz[to] == k)cost = 0;
			G[id].push_back({ to,cost });
			G[to].push_back({ id,cost });
		}
	}; initdfs(0, -1);
	yaru();
	vector<ll> ans(n);
	rep(i, n)ans[i] = ansc[lt.trans[i]];
	coutarray(ans);
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