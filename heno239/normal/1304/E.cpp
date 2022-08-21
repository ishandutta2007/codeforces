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
const ll mod = 1000000007;
const ll INF = (1e+18) + 7;
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
//typedef vector<vector<ll>> mat;
typedef vector<int> vec;

ll mod_pow(ll a, ll n, ll m) {
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
using mP = pair<modint, modint>;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

struct lcagraph {
private:
	int n;
	vector<vector<int>> G;
	vector<vector<int>> parent;
	vector<int> depth;
	int root;
	int tmp;
public:
	lcagraph(int n_) {
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
		root = 0;
	}
	lcagraph() {}
	void init(int n_) {
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
		root = 0;
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

void solve() {
	int n; cin >> n;
	lcagraph l(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		l.add_edge(a, b);
	}
	l.complete();
	int q; cin >> q;
	rep(aa, q) {
		int x, y, a, b, k; cin >> x >> y >> a >> b >> k;
		x--; y--; a--; b--;
		int d = l.dist(a,b);
		//cout << "!? " << d << endl;
		bool valid = false;
		if (d <= k && (d + k) % 2 == 0)valid = true;
		d = l.dist(a, x) + 1 + l.dist(y, b);
		//cout << "!? " << d << endl;
		if (d <= k && (d + k) % 2 == 0)valid = true;
		d += l.dist(x, y) + 1;
		//cout << "!? " << d << endl;
		if (d <= k && (d + k) % 2 == 0)valid = true;
		d = l.dist(a, y) + 1 + l.dist(x, b);
		//cout << "!? " << d << endl;
		if (d <= k && (d + k) % 2 == 0)valid = true;
		d += l.dist(x, y) + 1;
		//cout << "!? " << d << endl;
		if (d <= k && (d + k) % 2 == 0)valid = true;
		if (valid) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//int t; cin >> t; rep(i, t)solve();
	solve();
	stop
		return 0;
}