#include <bits/stdc++.h>
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
#define f first
#define s second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}
 
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 
/* from benq's template, fitted to not compile error */
template<int SZ> struct Dinic {
	#define sz(x) ((int)x.size())
	int N,s,t;
	typedef ll F;
	struct Edge { int to, rev; F flo, cap; };
	vector<Edge> adj[SZ];
	void ae(int u, int v, F cap, F rcap = 0) { 
		assert(min(cap,rcap) >= 0); 
		Edge a{v,sz(adj[v]),0,cap}, b{u,sz(adj[u]),0,rcap};
		adj[u].push_back(a), adj[v].push_back(b); } 
	int lev[SZ]; typename vector<Edge>::iterator cur[SZ]; 
	bool bfs() {
		for (ll i = 0; i < N; i++) lev[i] = -1, cur[i] = begin(adj[i]);
		queue<int> q({s}); lev[s] = 0; 
		while (sz(q)) {
			int u = q.front(); q.pop();
			for(auto e: adj[u]) if (lev[e.to] < 0 && e.flo < e.cap) 
				q.push(e.to), lev[e.to] = lev[u]+1;
		}
		return lev[t] >= 0;
	}
	F dfs(int v, F flo) {
		if (v == t) return flo;
		for (; cur[v] != end(adj[v]); cur[v]++) {
			Edge& e = *cur[v];
			if (lev[e.to]!=lev[v]+1||e.flo==e.cap) continue;
			F df = dfs(e.to,min(flo,e.cap-e.flo));
			if (df) { e.flo += df; adj[e.to][e.rev].flo -= df;
				return df; }
		}
		return 0;
	}
	F maxFlow(int NN, int ss, int tt) {
		N = NN, s = ss, t = tt; assert(s != t);
		F tot = 0; while (bfs()) while (F df = 
			dfs(s,numeric_limits<F>::max())) tot += df;
		return tot;
	}
};
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 2047;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;
 
vector<pair<ll, ll>> edges[10005];

void solve(int tc) {
    cin >> n >> m;
	
	for (ll i = 0; i < m; i++) {
		ll x, y, z; cin >> x >> y >> z;
		--x; --y;
		
		edges[x].push_back(make_pair(n + y, z));
	}
	
	ll inf = 1e9 + 7;
	ll l = 1, r = inf;
	while (l < r) {
		ll m = (l + r) / 2;
				
		Dinic<20002> d;
		
		for (ll i = 0; i < n; i++) {
			d.ae(0, i + 1, 1);
			d.ae(n + 1 + i, 2 * n + 1, 1);
		}
		
		for (ll i = 0; i < n; i++) {
			for (pair<ll, ll> y: edges[i]) {
				if (y.s <= m) {
					d.ae(1 + i, y.f + 1, 1);
				}
			}
		}
		
		if (d.maxFlow(2 * n + 2, 0, 2 * n + 1) == n) r = m;
		else l = m + 1;
	}
	
	if (l == inf) l = -1;
	cout << l << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("moop");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 
	
	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}