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
typedef double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-8;
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
const int max_n = 1 <<1;
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

bool comp(P a, P b) {
	if (a.second != b.second)return a.second < b.second;
	return a.first < b.first;
}
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
	int query(vector<string> &s,vector<int> &a) {
		int h = s.size();
		int w = s[0].size();
		int res = 0; 
		vector<int> idl(mk, w);
		vector<int> idr(mk, -1);
		rep(i, mk) {
			for (int id : ori[i]) {
				int x = id / w;
				int y = id % w;
				idl[i] = min(idl[i], y);
				idr[i] = max(idr[i], y);
			}
			for (int to : fG[i]) {
				idl[to] = min(idl[to], idl[i]);
				idr[to] = max(idr[to], idr[i]);
			}
		}
		vector<P> vp;
		rep(j, w) {
			if (a[j] == 0)continue;
			int rest = a[j];
			per(i, h) {
				if (s[i][j] == '#')rest--;
				if (rest == 0) {
					int loc = trans[i * w + j];
					vp.push_back({ idl[loc],idr[loc] });
					break;
				}
			}
		}
		sort(all(vp), comp);
		//cout << vp.size() << "\n";
		int r = -1;
		rep(i, vp.size()) {
			//cout << vp[i].first << " " << vp[i].second << "\n";
			if (vp[i].first > r) {
				res++; r = vp[i].second;
			}
		}
		return res;
	}
};

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void solve() {
	int h, w; cin >> h >> w;
	vector<string> s(h);
	rep(i, h)cin >> s[i];
	vector<int> a(w); rep(j,w)cin >> a[j];
	vector<vector<int>> nex(h, vector<int>(w));
	rep(j, w) {
		int las = h;
		per(i, h) {
			if (s[i][j] == '#')las = i;
			nex[i][j] = las;
		}
	}
	graph g(h* w);
	rep(i, h)rep(j, w)if (s[i][j] == '#') {
		int id = i * w + j;
		rep(d, 4) {
			int ni = i + dx[d];
			int nj = j + dy[d];
			if (ni < 0 || ni >= h || nj < 0 || nj >= w)continue;
			if (s[ni][nj] == '#') {
				int to = ni * w + nj;
				g.add_edge(id, to);
			}
		}
		for (int nj = j - 1; nj <= j + 1; nj++) {
			if (nj < 0 || nj >= w)continue;
			int ni = i; if (nj == j)ni = i + 1;
			if (ni == h)continue;
			ni = nex[ni][nj];
			if (ni == h)continue;
			int to = ni * w + nj;
			//cout << "? " << i << " " << j << " " << ni << " " << nj << "\n";
			g.add_edge(id, to);
		}
	}
	g.scc();
	int ans = g.query(s,a);
	cout << ans << "\n";
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init_f();
	//init(); cout << ps.size() << "\n";
	//expr();
	//int t; cin >> t; rep(i, t)
	solve();
	return 0;
}