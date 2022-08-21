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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
const ld pi = acos(-1.0);

ll mod_pow(ll a, ll n, ll m = mod) {
	ll res = 1;
	while (n) {
		if (n & 1)res = res * a%m;
		a = a * a%m; n >>= 1;
	}
	return res;
}

struct modint {
	ll n;
	modint() :n(0) { ; }
	modint(ll m) :n(m) {
		if (n >= mod)n %= mod;
		else if (n < 0)n = (n%mod + mod) % mod;
	}
	operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
modint operator+=(modint &a, modint b) { a.n += b.n; if (a.n >= mod)a.n -= mod; return a; }
modint operator-=(modint &a, modint b) { a.n -= b.n; if (a.n < 0)a.n += mod; return a; }
modint operator*=(modint &a, modint b) { a.n = ((ll)a.n*b.n) % mod; return a; }
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a*a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
const int max_n = 10000;
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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };


using Data = int;
Data merge(Data a, Data b) {
	return max(a, b);
}
int mostfar[1 << 17];
const int mn = 1 << 17;
struct edge {
	int to;
};
vector<edge> G[mn];
vector<int> ids[mn];
vector<Data> memo[mn];
int root;


Data dfs(int id, int fr) {
	Data res;
	//
	//initialize
	res = 0;
	//
	for (edge e : G[id]) {
		if (e.to == fr)continue;
		Data nex = dfs(e.to, id);
		//
		//update with edge
		nex++;
		//
		res = merge(res, nex);
		ids[id].push_back(e.to);
		memo[id].push_back(nex);
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
	rep(i, len) {
		mostfar[id] = max(mostfar[id], v[i]);
	}
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
		d++;
		//
		invdfs(to, id, d);
	}
}
void yaru(int sta) {
	root = sta;
	dfs(root, -1);
	invdfs(root, -1, 0);
}

bool used[1 << 17];
int par[1 << 17];
ll diameter[1 << 17];
vector<ll> dists[1 << 17];
vector<ll> rdists[1 << 17];
bool istree[1 << 17];
void solve() {
	int n, m, q; cin >> n >> m >> q;
	rep(i, m) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back({ b });
		G[b].push_back({ a });
	}
	rep(i, n)if (!used[i]) {
		vector<int> ids;
		queue<int> q;
		q.push(i); used[i] = true;
		while (!q.empty()) {
			int id = q.front(); q.pop();
			ids.push_back(id);
			for (edge e : G[id]) {
				if (!used[e.to]) {
					used[e.to] = true;
					q.push(e.to);
				}
			}
		}
		int c = 0;
		for (int id : ids) {
			c += G[id].size();
			par[id] = i;
		}
		if (c != ids.size() * 2 - 2) {
			istree[i] = false;
		}
		else {
			istree[i] = true;
			yaru(i);
			for (int id : ids) {
				diameter[i] = max(diameter[i], (ll)mostfar[id]);
				dists[i].push_back(mostfar[id]);
			}
			sort(all(dists[i]));
			rdists[i].resize(dists[i].size() + 1);
			rep(j, dists[i].size()) {
				rdists[i][j + 1] = rdists[i][j] + dists[i][j];
			}
		}
	}
	map<P, ld> memoed;
	map<P, bool> chked;
	rep(aa, q) {
		int a, b; cin >> a >> b; a--; b--;
		a = par[a], b = par[b];
		if (a == b) {
			cout << -1 << "\n";
		}
		else if (!istree[a] || !istree[b]) {
			cout << -1 << "\n";
		}
		else {
			if (dists[a].size() > dists[b].size())swap(a, b);
			if (chked[{a, b}]) {
				cout << memoed[{a, b}] << "\n";
				continue;
			}
			chked[{a, b}] = chked[{b, a}] = true;
			ll l1 = dists[a].size();
			ll l2 = dists[b].size();
			ld sum = l1*l2+rdists[a][l1]*l2+l1*rdists[b][l2];
			rep(j, dists[a].size()) {
				//cout << dists[a][j] << endl;
				int rest, id;
				//a
				rest = diameter[a] - dists[a][j] - 1;
				id = lower_bound(all(dists[b]), rest) - dists[b].begin();
				sum -= rdists[b][id];
				sum -= id * (dists[a][j] + 1);
				sum += id * diameter[a];
				//cout << id << endl;
				//b
				rest = diameter[b] - dists[a][j] - 1;
				id = lower_bound(all(dists[b]), rest) - dists[b].begin();
				sum -= rdists[b][id];
				sum -= id * (dists[a][j] + 1);
				sum += id * diameter[b];
				//cout << id << endl;
			}
			ld ans = sum /(ld)(l1*l2);
			cout << ans << "\n";
			memoed[{a, b}] = memoed[{b, a}] = ans;
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}