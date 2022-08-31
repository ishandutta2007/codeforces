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

ll gcd(ll a, ll b) {
    if (a < b)swap(a, b);
    while (b) {
        ll r = a % b; a = b; b = r;
    }
    return a;
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
	int find_par(int x, int d) {
		rep(i, tmp)if (d & (1 << i))x = parent[x][i];
		return x;
	}
};



struct edge {
	int to;
};
struct Centroid_Decomposition {
private:
	int n;
	vector<vector<edge>> G;

	vector<vector<int>> fG; int root;
	vector<int> par;
	vector<vector<int>> distma;
	vector<vector<P>> dista;

	lcagraph lg;
public:
	Centroid_Decomposition(int n_) {
		n = n_;
		G.resize(n);
		par.resize(n);

		fG.resize(n); root = -1;
		distma.resize(n);
		dista.resize(n);
	}
	void add_edge(int a, int b) {
		G[a].push_back({ b });
		G[b].push_back({ a });
	}

	void complete() {
		vector<int> exi(n, 0);
		vector<int> ori(n); rep(i, n)ori[i] = i;


		int tmp = 0;
		function<int(int, int, int&, int&)> szdfs = [&](int id, int fr, int& g, int& sz)->int {
			int res = 1;
			int ma = 0;
			for (edge e : G[id]) {
				if (tmp != exi[e.to])continue;
				if (e.to == fr)continue;
				int nex = szdfs(e.to, id, g, sz);
				ma = max(ma, nex);
				res += nex;
			}
			if (ma <= sz / 2 && sz - res <= sz / 2)g = id;
			return res;
		};

		function<int(vector<int>)> cdfs = [&](vector<int> v)->int {
			tmp++;
			if (v.empty())return 0;

			for (int id : v) {
				exi[id]++;
			}
			int g;
			int sz = v.size();
			szdfs(v[0], -1, g, sz);

			dista[g].push_back({ g,0 });
			int mad = 0;

			for (edge e : G[g]) {
				if (!exi[e.to])continue;
				if (exi[e.to] != tmp)continue;

				queue<P> vs;
				vs.push({ e.to,g });
				int d = 0;
				vector<int> nex;
				while (!vs.empty()) {
					d++;
					int len = vs.size();
					rep(aa, len) {
						P p = vs.front(); vs.pop();
						int v = p.first, fr = p.second;

						mad = max(mad, d);
						dista[g].push_back({ v,d });

						nex.push_back(v);
						for (edge e : G[v]) {
							if (e.to == fr)continue;
							if (tmp != exi[e.to])continue;
							vs.push({ e.to,v });
						}
					}
				}

				int ng = cdfs(nex);
				fG[g].push_back(ng);
				par[ng] = g;
				//cout << "p " << g << " " << ng << "\n";
			}
			distma[g].resize(mad + 1,0);
			for (int id : v) {
				exi[id]++;
			}
			tmp--;
			return g;
		};
		root = cdfs(ori); par[root] = -1;
		//lca
		lg.init(n);
		rep(i, n) {
			for (edge e : G[i]) {
				if (i < e.to) {
					lg.add_edge(i, e.to);
				}
			}
		}
		lg.complete();
	}
	void add(int c, int d, int val) {
		if (d < 0)return;
		int g = c;
		while (g >= 0) {
			if (g == c) {
				int x = d; if (x >= distma[g].size())x = distma[g].size() - 1;
				distma[g][x] = max(distma[g][x], val);

				//cout << "? " << g << " " << x << " " << val << "\n";
			}
			else {
				int x = d - lg.dist(g, c);
				if (x >= 0) {
					if (x >= distma[g].size())x = distma[g].size() - 1;
					distma[g][x] = max(distma[g][x], val);
					//cout << "? " << g << " " << x << " "<<val<<"\n";
				}
			}
			g = par[g];
		}
	}
	vector<int> query() {
		vector<int> ans(n);
		rep(i, n) {
			per(j, (int)distma[i].size() - 1) {
				distma[i][j] = max(distma[i][j], distma[i][j + 1]);
			}
			for (P p : dista[i]) {
				ans[p.first] = max(ans[p.first], distma[i][p.second]);
			}
		}
		return ans;
	}
};


void solve() {
	int n; cin >> n;
	vector<vector<int>> G(n);
	Centroid_Decomposition cd(n);
	rep(i, n - 1) {
		int a, b; cin >> a >> b; a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
		cd.add_edge(a, b);
	}
	cd.complete();
	int k; cin >> k;
	vector<int> dist(n, mod);
	queue<int> q;
	rep(i, k) {
		int v; cin >> v; v--; dist[v] = 0;
		q.push(v);
	}
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int to : G[v]) {
			if (dist[to] > dist[v] + 1) {
				dist[to] = dist[v] + 1;
				q.push(to);
			}
		}
	}
	rep(i, n) {
		cd.add(i, dist[i] - 1, dist[i]);
	}
	vector<int> ans = cd.query();
	rep(i, ans.size()) {
		if (i > 0)cout << " ";
		cout << ans[i];
	}
	cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << fixed << setprecision(15);
    //init_f();
    //init();
    //expr();
    //int t; cin >> t; rep(i, t)
    solve();
    return 0;
}