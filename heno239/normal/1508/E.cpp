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
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-12;
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
const int max_n = 1 << 2;
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
	vector <int> ori(n);
	rep(i, n) {
		cin >> ori[i]; ori[i]--;
	}
	lcagraph lc(n);
	vector<vector<int>> G(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		lc.add_edge(a, b);
	}
	lc.complete();
	vector<int> rev(n);
	rep(i, n) {
		rev[ori[i]] = i;
	}
	vector<int> depth(n);
	vector<int> par(n, -1);
	{
		queue<int> q; q.push(0);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int to : G[v]) {
				depth[to] = depth[v] + 1;
				q.push(to);
				par[to] = v;
			}
		}
	}
	int chk = n - 1;
	ll sk = 0;
	rep(i, n) {
		int loc = rev[i];
		bool exi = false;
		for (int to : G[loc]) {
			if (ori[to] > ori[loc]) {
				exi = true;
			}
		}
		sk += depth[loc];
		if (exi) {
			chk = i; break;
		}
	}
	int cur = rev[chk];
	while (true) {
		int mi = mod;
		int nex = -1;
		for (int to : G[cur]) {
			if (ori[to] > ori[cur]) {
				if (ori[to] < mi) {
					mi = ori[to];
					nex = to;
				}
			}
		}
		if (nex < 0)break;
		swap(ori[cur], ori[nex]);
		cur = nex;
	}
	rep(i, n)rev[ori[i]] = i;

	bool valid = true;
	cur = 0;
	vector<vector<int>> fG(n);
	for (int i = 0; i <= chk; i++) {
		int to = rev[i];
		if (lc.lca(cur, to) != cur) {
			valid = false; break;
		}
		while (cur != to) {
			fG[par[to]].push_back(to);
			to = par[to];
		}
		cur = par[rev[i]];
	}
	if (!valid) {
		cout << "NO\n"; return;
	}
	vector<int> a = ori;

	int tmp = 0;
	function<void(int)> dfs = [&](int id) {
		a[id] = tmp;
		tmp++;
		for (int to : fG[id]) {
			dfs(to);
		}
	};
	dfs(0);
	
	vector<int> b = a;
	rep(i, chk + 1)b[rev[i]] = i;
	if (cur >= 0) {
		vector<int> lasts;
		while (cur != 0) {
			lasts.push_back(cur);
			cur = par[cur];
		}
		lasts.push_back(0);
		reverse(all(lasts));
		rep(i, lasts.size()) {
			b[lasts[i]] = chk + 1 + i;
		}
		//rep(i, n)cout << b[i] << "\n";
	}
	rep(i, n)if (ori[i] != b[i]) {
		valid = false;
	}

	tmp = 0;
	function<void(int)> checkdfs = [&](int id) {
		if (a[id] != tmp)valid = false;
		tmp++;
		vector<P> tos;
		for (int to : G[id]) {
			tos.push_back({ a[to],to });
		}
		sort(all(tos));
		for (P p : tos) {
			int to = p.second;
			checkdfs(to);
		}
	};
	checkdfs(0);
	if (valid) {
		cout << "YES\n";
		cout << sk << "\n";
		rep(i, n) {
			if (i > 0)cout << " ";
			cout << a[i] + 1;
		}
		cout << "\n";
	}
	else {
		cout << "NO\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init();
	//expr();
	//int t; cin >> t;rep(i,t)
	solve();
	return 0;
}