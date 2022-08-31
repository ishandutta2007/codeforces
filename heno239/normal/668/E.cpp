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
modint combP(int a, int b) {
	if (a < 0 || b < 0 || a < b)return 0;
	return fact[a] * factinv[a - b];
}

using bt = bitset<2000>;
struct graph {
private:
	int n;
	vector<vector<int>> G, rG;
	vector<bool> used;
	vector<int> vs;

	int mk;
	vector<vector<int>> fG;
	vector<vector<int>> ori;
	vector<int> trans;
public:
	graph(int sz) {
		n = sz;
		G.resize(n);
		rG.resize(n);
		used.resize(n);

		fG.resize(n);
		trans.resize(n, -1);
		ori.resize(n);
	}
	void add_edge(int a, int b) {
		G[a].push_back(b);
		rG[b].push_back(a);
	}
	void dfs(int v) {
		used[v] = true;
		rep(i, G[v].size()) {
			if (!used[G[v][i]])dfs(G[v][i]);
		}
		vs.push_back(v);
	}
	void rdfs(int v, int k) {
		used[v] = true;
		queue<int> q; q.push(v);
		vector<int> c;
		while (!q.empty()) {
			int id = q.front(); q.pop();
			ori[k].push_back(id);
			rep(j, rG[id].size()) {
				int to = rG[id][j];
				if (used[to]) {
					if (trans[to] >= 0)c.push_back(trans[to]);
					continue;
				}
				used[to] = true; q.push(to);
			}
		}
		sort(c.begin(), c.end());
		int len = unique(c.begin(), c.end()) - c.begin();
		rep(i, len) {
			fG[c[i]].push_back(k);
		}
		rep(i, ori[k].size()) {
			trans[ori[k][i]] = k;
		}
	}
	void scc() {
		fill(used.begin(), used.end(), false);
		rep(i, n) {
			if (!used[i])dfs(i);
		}
		fill(used.begin(), used.end(), false);
		int k = 0;
		per(i, (int)vs.size()) {
			if (!used[vs[i]]) {
				rdfs(vs[i], k); k++;
			}
		}
		mk = k;
	}
	bool can(int sz) {
		rep(i, sz) {
			if (trans[i] == trans[i + sz])return false;
		}
		return true;
	}
	vector<int> make_ans(int sz) {
		vector<int> res(sz, -1);
		per(i, mk) {
			bool exi = false;
			for (int t : ori[i]) {
				int id = t % sz;
				if (res[id] >= 0)exi = true;
			}
			if (exi)continue;
			for (int t : ori[i]) {
				res[t % sz] = t / sz;
			}
		}
		rep(i, sz)assert(res[i] >= 0);
		return res;
	}
	vector<bt> cango(int sz) {
		vector<bt> res(2 * sz);
		vector<bt> sub(mk);
		per(i, mk) {
			for (int t : ori[i])sub[i][t] = 1;
			for (int to : fG[i])sub[i] |= sub[to];
			for (int t : ori[i])res[t] = sub[i];
		}
		return res;
	}
};


void solve() {
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	auto rev = [&](int x) {
		if (x >= n)return x - n;
		else return x + n;
	};
	graph g1(2 * n), g2(2 * n);
	rep(i, m1) {
		int a, b; cin >> a >> b;
		if (a < 0)a = -a - 1;
		else a += n - 1;
		if (b < 0)b = -b - 1;
		else b += n - 1;
		g1.add_edge(rev(a), b);
		g1.add_edge(rev(b), a);
	}
	rep(i, m2) {
		int a, b; cin >> a >> b;
		if (a < 0)a = -a - 1;
		else a += n - 1;
		if (b < 0)b = -b - 1;
		else b += n - 1;
		g2.add_edge(rev(a), b);
		g2.add_edge(rev(b), a);
	}
	g1.scc();
	g2.scc();
	bool b1 = g1.can(n);
	bool b2 = g2.can(n);
	if (!b1 && !b2) {
		cout << "SIMILAR\n"; return;
	}
	else if (b1 && !b2) {
		vector<int> r = g1.make_ans(n);
		rep(i, r.size()) {
			if (i > 0)cout << " ";
			cout << r[i];
		}
		cout << "\n";
	}
	else if (!b1 && b2) {
		vector<int> r = g2.make_ans(n);
		rep(i, r.size()) {
			if (i > 0)cout << " ";
			cout << r[i];
		}
		cout << "\n";
	}
	else {
		vector<bt> to1 = g1.cango(n);
		vector<bt> to2 = g2.cango(n);
		int chki = -1, chkj = -1;
		rep(i, 2 * n) {
			if (to2[i][rev(i)])continue;
			rep(j, 2 * n) {
				if (to2[rev(j)][j])continue;
				if (to2[i][j])continue;
				if (to1[i][j]) {
					chki = i, chkj = j;
				}
			}
		}
		rep(i, 2 * n) {
			if (to1[i][rev(i)])continue;
			rep(j, 2 * n) {
				if (to1[rev(j)][j])continue;
				if (to1[i][j])continue;
				if (to2[i][j]) {
					chki = i, chkj = j;
				}
			}
		}
		if (chki < 0) {
			cout << "SIMILAR\n"; return;
		}
		else {
			graph g(2 * n);
			if (to1[chki][chkj])swap(to1, to2);
			rep(i, 2 * n)rep(j, 2 * n) {
				if (to1[i][j])g.add_edge(i, j);
			}
			g.add_edge(rev(chki), chki);
			g.add_edge(chkj, rev(chkj));
			g.scc();
			assert(g.can(n));
			vector<int> r = g.make_ans(n);
			rep(i, r.size()) {
				if (i > 0)cout << " ";
				cout << r[i];
			}
			cout << "\n";
		}
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