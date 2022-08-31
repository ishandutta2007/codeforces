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
const ll mod = 998244353;
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
	a %= m;
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
const int max_n = 1 << 18;
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

using Data = pair<ll, vector<int>>;
const int mn = 1 << 18;
struct edge {
	int to;
};
vector<edge> G[mn];
vector<int> ids[mn];
vector<Data> memo[mn];
int root;

Data merge(Data a, Data b) {
	Data res;
	//
	res.first = a.first + b.first;
	rep(i, a.second.size()) {
		res.second.push_back(a.second[i] + b.second[i]);
	}
	//
	return res;
}

int k;
Data dfs(int id, int fr) {
	Data res;
	//
	//initialize
	res.first = 0;
	res.second.resize(k, 0);
	res.second[0] = 1;
	//
	for (edge e : G[id]) {
		if (e.to == fr)continue;
		Data nex = dfs(e.to, id);
		//
		//update with edge
		//
		res = merge(res, nex);
		ids[id].push_back(e.to);
		memo[id].push_back(nex);
	}
	//
	//update for return
	Data cop = res;
	cop.first += res.second[0];
	rep(i, k) {
		cop.second[i] = res.second[(i - 1 + k) % k];
	}
	//
	return cop;
}

ll ans;
void invdfs(int id, int fr, Data pre) {
	vector<Data> v;
	for (Data d : memo[id])v.push_back(d);
	if (fr >= 0)v.push_back(pre);
	int len = v.size();
	//
	//calcurate id's ans
	for (Data d : v) {
		ans += d.first;
	}
	//
	vector<Data> le(len + 1);
	vector<Data> ri(len + 1);
	//
	Data init_c = { 0,vector<int>(k,0) };
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
		d.second[0]++;

		Data cop = d;
		cop.first += d.second[0];
		rep(i, k) {
			cop.second[i] = d.second[(i - 1 + k) % k];
		}
		//
		invdfs(to, id, cop);
	}
}
void yaru() {
	dfs(root, -1);
	invdfs(root, -1, { 0,vector<int>(k,0) });
}
void solve() {
	int n; cin >> n >> k;
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back({ b });
		G[b].push_back({ a });
	}
	yaru();
	cout << ans/2 << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	//experi();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}