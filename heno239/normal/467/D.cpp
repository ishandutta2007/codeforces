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

#define int long long
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

void chmin(int &a, int b) {
	a = min(a, b);
}
void chmax(int &a, int b) {
	a = max(a, b);
}
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
const int max_n = 10001000;
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
	vector<P> query(vector<P> costs) {
		int len = costs.size();
		vector<P> res(len, { mod,mod });
		vector<P> cres(mk, { mod,mod });
		per(i, mk) {
			for (int id : ori[i]) {
				cres[i] = min(cres[i], costs[id]);
			}
			for (int to : fG[i]) {
				cres[i] = min(cres[i], cres[to]);
			}


			for (int id : ori[i])res[id] = cres[i];
		}
		return res;
	}
};

void normalize(string &s) {
	rep(i, s.size()) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			s[i] = (s[i] - 'A') + 'a';
		}
	}
}
void solve() {
	map<string, int> mp;
	vector<P> costs;

	int m; cin >> m;
	vector<string> c(m);
	vector<int> id(m);
	rep(i, m) {
		cin >> c[i];
		normalize(c[i]);
		if (mp.find(c[i]) == mp.end()) {
			mp[c[i]] = mp.size();
		}
		id[i] = mp[c[i]];
	}
	int n; cin >> n;
	vector<P> vs;

	rep(i, n) {
		string a, b; cin >> a >> b;
		normalize(a); normalize(b);
		if (mp.find(a) == mp.end()) {
			mp[a] = mp.size();
		}
		if (mp.find(b) == mp.end()) {
			mp[b] = mp.size();
		}
		vs.push_back({ mp[a],mp[b] });
	}
	
	graph g(mp.size());
	for (P p : vs) {
		g.add_edge(p.first, p.second);
	}
	g.scc();

	costs.resize(mp.size());
	for (pair<string, int> p : mp) {
		string &s = p.first;
		P nex;
		nex.second = s.size();
		nex.first = 0;
		for (char c : s)if (c == 'r')nex.first++;
		costs[p.second]=nex;
	}

	rep(i, mp.size()) {
		//cout << costs[i].first << " " << costs[i].second << "\n";
	}
	vector<P>res = g.query(costs);
	P ans = { 0,0 };
	rep(i, m) {
		ans.first += res[id[i]].first;
		ans.second += res[id[i]].second;
	}
	cout << ans.first << " " << ans.second << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(7);
	//init_f();
	//init();
	
	solve();
	stop
		return 0;
}