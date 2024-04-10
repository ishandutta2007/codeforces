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
const ld pi = acos(-1.0);

ll mod_pow(ll x, ll n, ll m) {
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
modint operator^(modint a, int n) {
	if (n == 0)return modint(1);
	modint res = (a * a) ^ (n / 2);
	if (n % 2)res = res * a;
	return res;
}

ll inv(ll a, ll p) {
	return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }

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
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

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
	int par(int x) { return parent[x][0]; }
};


struct Node {
	Node* lch, * rch; int l, r, val; int lazy;
	Node() {};
	Node(int l, int r,int val) :lch(NULL), rch(NULL), l(l), r(r), val(val),lazy(0) {};
};
void eval(Node*& nd) {
	nd->val += nd->lazy;
	if (nd->lch != NULL)nd->lch->lazy += nd->lazy;
	if (nd->rch != NULL)nd->rch->lazy += nd->lazy;
	nd->lazy = 0;
}

void add(Node* nd, int le, int ri) {
	eval(nd);
	if (nd->r <= le || ri <= nd->l)return;
	if (le <= nd->l && nd->r <= ri) {
		nd->lazy++; eval(nd);
	}
	else {
		int m = (nd->l + nd->r) / 2;
		if (le < m) {
			if (nd->lch == NULL) {
				nd->lch = new Node(nd->l, m,nd->val);
			}
			add(nd->lch, le, ri);
		}
		if (m < ri) {
			if (nd->rch == NULL) {
				nd->rch = new Node(m,nd->r,nd->val);
			}
			add(nd->rch, le, ri);
		}
		/*nd->val = 0;
		if (nd->lch != NULL)nd->val += nd->lch->val;
		if (nd->rch != NULL)nd->val += nd->rch->val;*/
	}
}
int query(Node* nd, int loc) {
	while (nd->r-nd->l>1) {
		eval(nd);
		int m = (nd->l + nd->r)/2;
		if (loc < m) {
			if (nd->lch == NULL)return nd->val;
			nd = nd->lch;
		}
		else {
			if (nd->rch == NULL)return nd->val;
			nd = nd->rch;
		}
	}
	eval(nd);
	return nd->val;
}
const int mn = 10000000;
bool isp[3200];
vector<int> ps;
void init() {
	fill(isp + 2, isp + 3200, true);
	for (int i = 2; i * i <= mn; i++) {
		if (!isp[i])continue;
		ps.push_back(i);
		for (int j = 2 * i; j < 3200; j += i)isp[j] = false;
	}
}
void p_resol(int x, vector<P>& p) {
	int cop = x;
	rep(i, ps.size())if (cop % ps[i] == 0) {
		int cnt = 0;
		while (cop % ps[i] == 0) {
			cop /= ps[i]; cnt++;
		}
		p.push_back({ ps[i],cnt });
	}
	if (cop > 1)p.push_back({ cop,1 });
}

int trans[1 << 17];
int ri[1 << 17];
vector<int> G[1 << 17];
int tmp = 0;


void dfs(int id, int fr) {
	trans[id] = tmp; tmp++;
	for (int to : G[id])if (to != fr) {
		dfs(to, id);
	}
	ri[id] = tmp;
}

int ts[mn + 1];
vector<Node*> nds(1);
void solve() {
	init();
	int n; cin >> n;



	lcagraph lt(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
		lt.add_edge(a, b);
	}
	lt.complete();
	dfs(0, -1);
	rep(i, n) {
		vector<P> ps;
		int c; cin >> c;
		p_resol(c, ps);
		int l = trans[i], r = ri[i];
		rep(j, ps.size()) {
			int z = 1;
			rep(k, ps[j].second) {
				z *= ps[j].first;
				if (ts[z] == 0) {
					ts[z] = nds.size();
					nds.push_back(new Node(0,n,0));
				}
				add(nds[ts[z]], l, r);
			}
		}
	}
	function<int(int, int)> calc = [&](int v, int s)->int {
		v = trans[v];
		return query(nds[ts[s]], v);
	};
	function<int(int, int,int,int)> calc2 = [&](int a,int b,int l, int s)->int {
		if (ts[s] == 0)return 0;
		int res = calc(a, s) + calc(b, s) - calc(l, s);
		if (l != 0)res -= calc(lt.par(l), s);
		return res;
	};

	int q; cin >> q;
	rep(i, q) {
		int a, b; cin >> a >> b; a--; b--;
		int l = lt.lca(a, b);

		int c; cin >> c;
		vector<P> ps; p_resol(c, ps);

		modint ans = 1;
		for (P p : ps) {
			int num = p.second;
			int z = 1;
			int sum = 0;
			rep(i, num) {
				z *= p.first;
				sum += calc2(a, b, l, z);
			}
			ans *= mod_pow(p.first, sum,mod);
		}
		cout << ans << "\n";
	}
}






signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
//	int t; cin >> t; rep(i, t)
	solve();
	return 0;
}