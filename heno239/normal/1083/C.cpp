#pragma GCC optimize("Ofast")
#pragma GCC target ("sse4")

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
const ld eps = 1e-12;
const ld pi = acosl(-1.0);

ll mod_pow(ll x, ll n, ll m = mod) {
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
};

template<typename T>
struct SegT {
private:
	int sz; vector<T> node;
	T init_c;
	function<T(T, T)> f;
public:
	SegT(vector<T> v, T _init_c, function<T(T, T)> _f) {
		init_c = _init_c; f = _f;
		int n = v.size();
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
		rep(i, n) {
			node[i + sz - 1] = v[i];
		}
		per(i, sz - 1) {
			node[i] = f(node[2 * i + 1], node[2 * i + 2]);
		}
	}
	SegT(int n, T _init_c, function<T(T, T)> _f) {
		init_c = _init_c; f = _f;
		sz = 1;
		while (sz < n)sz *= 2;
		node.resize(2 * sz - 1, init_c);
	}
	void update(int k, T a) {
		k += sz - 1;
		node[k] = a;
		while (k > 0) {
			k = (k - 1) / 2;
			node[k] = f(node[k * 2 + 1], node[k * 2 + 2]);
		}
	}
	T query(int a, int b, int k = 0, int l = 0, int r = -1) {
		if (r < 0)r = sz;
		if (r <= a || b <= l)return init_c;
		else if (a <= l && r <= b)return node[k];
		else {
			T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return f(vl, vr);
		}
	}
	int searchloc() {
		T cur = init_c;
		int k = 0;
		while (k < sz - 1) {
			T p = f(cur, node[2 * k + 1]);
			if (p.x == -1) {
				k = 2 * k + 1;
			}
			else {
				cur = p;
				k = 2 * k + 2;
			}
		}
		return k - (sz - 1);
	}
};


struct path {
	//deoth[x]<=depth[y]
	int x, y,l;
};


void solve() {
	int n; cin >> n;
	lcagraph lc(n);
	vector<int> trans(n), ri(n);
	auto add = [&](path a, int v)->path {
		if (a.x == -2)return { v,v,v };
		if (a.x == -1)return { -1,-1,0 };
		if (v == -1)return { -1,-1,0 };
		if (v == -2)return a;
		if (a.x == a.l) {
			if (trans[a.y] <= trans[v] && trans[v] < ri[a.y]) {
				return { a.x,v,a.l };
			}
			if (trans[a.x] <= trans[v] && trans[v] < ri[a.x]) {
				if (trans[v] <= trans[a.y] && trans[a.y] < ri[v])return a;
				else {
					int l2 = lc.lca(a.y, v);
					if (l2 == a.x) {
						int s1 = v;
						int s2 = a.y;
						if (lc.dep(s1) > lc.dep(s2))swap(s1, s2);
						return { s1,s2,a.l };
					}
					else return { -1,-1,0 };
				}
			}
			int s1 = a.y;
			int s2 = v;
			int l = lc.lca(s1, s2);
			if (lc.dep(s1) > lc.dep(s2))swap(s1, s2);
			return { s1,s2,l };
		}
		else {
			if (trans[a.x] <= trans[v] && trans[v] < ri[a.x]) {
				int s1 = v; int s2 = a.y;
				if (lc.dep(s1) > lc.dep(s2))swap(s1, s2);
				return { s1,s2,a.l };
			}
			if (trans[a.y] <= trans[v] && trans[v] < ri[a.y]) {
				int s1 = v; int s2 = a.x;
				if (lc.dep(s1) > lc.dep(s2))swap(s1, s2);
				return { s1,s2,a.l };
			}
			bool bl = false, br = false;
			if (trans[v] <= trans[a.x] && trans[a.x] < ri[v])bl = true;
			if (trans[v] <= trans[a.y] && trans[a.y] < ri[v])br = true;
			if (bl == br) {
				if (bl == true && a.l == v)return a;
				else return { -1,-1,0 };
			}
			else {
				return a;
			}
		}
	};
	auto merge = [&](path a, path b)->path {
		a = add(a, b.x);
		a = add(a, b.y);
		return a;
	};
	vector<int> p(n);
	rep(i, n)cin >> p[i];
	vector<vector<int>> ch(n);
	rep1(i, n - 1) {
		int par; cin >> par; par--;
		lc.add_edge(par, i);
		ch[par].push_back(i);
	}
	int tmp = 0;
	function<void(int)> dfs = [&](int id) {
		trans[id] = tmp; tmp++;
		for (int to : ch[id])dfs(to);
		ri[id] = tmp;
	}; dfs(0);
	lc.complete();

	SegT<path> st(n + 1, { -2,-2,0 }, merge);
	rep(i, n) {
		st.update(p[i], { i,i,i });
	}

	path u = st.query(0, 2);
	//cout << u.x << " " << u.y << " " << u.l << "\n";
	int q; cin >> q;
	rep(i, q) {
		int t; cin >> t;
		if (t == 1) {
			int a, b; cin >> a >> b; a--; b--;
			st.update(p[a], { b,b,b });
			st.update(p[b], { a,a,a });
			swap(p[a], p[b]);
		}
		else {
			int ans = st.searchloc();
			ans = min(ans, n);
			//cout << "ans is ";
			cout << ans << "\n";
		}
	}
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << fixed << setprecision(15);
     //init_f();
     //init();
     //expr();
     //int t; cin >> t; rep(i, t)
    solve();
    return 0;
}