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


const int mn = 1 << 19;
struct edge {
	int to; ll cost1, cost2;
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
	res = min(a, b);
	//
	return res;
}

ll selfc[mn];
Data dfs(int id, int fr) {
	Data res;
	//
	//initialize
	res = selfc[id];
	//
	for (edge e : G[id]) {
		if (e.to == fr)continue;
		Data nex = dfs(e.to, id);
		//
		//update with edge
		nex += (e.cost1 + e.cost2);
		//
		res = merge(res, nex);
		ids[id].push_back(e.to);
		memo[id].push_back(nex);
		costs[id].push_back(e.cost1+e.cost2);
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
	Data nd = selfc[id];
	for (auto d : v)nd = merge(nd, d);
	selfc[id] = nd;
	//
	vector<Data> le(len + 1);
	vector<Data> ri(len + 1);
	//
	Data init_c = INF;
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
		d = merge(d, selfc[id]);
		d += costs[id][i];
		//
		invdfs(to, id, d);
	}
}
void yaru() {
	dfs(root, -1);
	invdfs(root, -1, 0);
}
int par[1 << 19][19];
ll cost[1 << 19][19][2][2];
//ll costinv[1 << 19][19][2][2];
void solve() {
	int n; cin >> n;
	rep(i, n)cin >> selfc[i];
	rep(i, n - 1) {
		int a, b; ll c1, c2;
		cin >> a >> b >> c1 >> c2; a--; b--;
		G[a].push_back({ b,c1,c2 });
		G[b].push_back({ a,c1,c2 });
	}
	yaru();
	vector<int> dep(n);
	function<void(int, int)> initdfs = [&](int id, int fr) {
		par[id][0] = fr;
		for (edge e : G[id])if(e.to!=fr) {
			dep[e.to] = dep[id] + 1;
			initdfs(e.to, id);
			cost[e.to][0][0][0] = e.cost1;
			cost[e.to][0][1][0] = e.cost1 + selfc[id];
			cost[e.to][0][0][1] = e.cost2 + selfc[id];
			cost[e.to][0][1][1] = e.cost2;
			/*costinv[e.to][0][0][0] = e.cost1;
			costinv[e.to][0][1][0] = e.cost1 + selfc[e.to];
			costinv[e.to][0][0][1] = e.cost2 + selfc[e.to];
			costinv[e.to][0][1][1] = e.cost2;*/
		}
	};
	initdfs(0, -1);
	rep(j, 18) {
		rep(i, n) {
			if (par[i][j] < 0)par[i][j + 1] = -1;
			else {
				int p = par[i][j];
				par[i][j + 1] = par[p][j];
				rep(x, 2)rep(y, 2) {
					cost[i][j + 1][x][y] = INF;
					//costinv[i][j+1][x][y] = INF;
				}
				rep(x, 2)rep(z, 2)rep(y, 2) {
					chmin(cost[i][j + 1][x][y], cost[p][j][x][z] + cost[i][j][z][y]);
					//chmin(costinv[i][j+1][x][y],)
				}
			}
		}
	}
	auto query = [&](int a, int b) {
		bool ba = false, bb = false;
		if (a % 2) {
			ba = true;
		}
		a /= 2;
		if (b % 2) {
			bb = true;
		}
		b /= 2;
		if (dep[a] > dep[b]) {
			swap(a, b); swap(ba, bb);
		}
		ll ca[2], cb[2];
		ca[0] = ca[1] = selfc[a];
		cb[0] = cb[1] = selfc[b];
		if (ba)ca[1] = 0;
		else ca[0] = 0;
		if (bb)cb[1] = 0;
		else cb[0] = 0;
		int dif = dep[b] - dep[a];
		rep(j, 19)if (dif & (1 << j)) {
			ll ncb[2] = { INF,INF };
			rep(x, 2)rep(z, 2) {
				chmin(ncb[x], cost[b][j][x][z] + cb[z]);
			}
			rep(x, 2)cb[x] = ncb[x];
			b = par[b][j];
		}
		if (a != b) {
			per(j, 19) {
				if (par[a][j] != par[b][j]) {
					ll ncb[2] = { INF,INF };
					rep(x, 2)rep(z, 2) {
						chmin(ncb[x], cost[b][j][x][z] + cb[z]);
					}
					rep(x, 2)cb[x] = ncb[x];
					b = par[b][j];
					ll nca[2] = { INF,INF };
					rep(x, 2)rep(z, 2) {
						chmin(nca[x], cost[a][j][x][z] + ca[z]);
					}
					rep(x, 2)ca[x] = nca[x];
					a = par[a][j];
				}
			}
			int j = 0;
			ll ncb[2] = { INF,INF };
			rep(x, 2)rep(z, 2) {
				chmin(ncb[x], cost[b][j][x][z] + cb[z]);
			}
			rep(x, 2)cb[x] = ncb[x];
			b = par[b][j];
			ll nca[2] = { INF,INF };
			rep(x, 2)rep(z, 2) {
				chmin(nca[x], cost[a][j][x][z] + ca[z]);
			}
			rep(x, 2)ca[x] = nca[x];
			a = par[a][j];
		}
		assert(a == b);
		ll res = INF;
		rep(i, 2)chmin(res, ca[i] + cb[i]);
		return res;
	};
	int q; cin >> q;
	rep(i, q) {
		int x, y; cin >> x >> y; x--; y--;
		cout << query(x, y) << "\n";
	}
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