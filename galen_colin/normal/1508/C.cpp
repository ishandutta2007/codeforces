#include "bits/stdc++.h"
using namespace std;
 
/* 
find my code templates at https://github.com/galencolin/cp-templates
also maybe subscribe please thanks 
*/
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
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
 
mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937_64 rng(61378913);
/* usage - just do rng() */
 
void usaco(string filename) {
  // #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
// #include <atcoder/all>
// using namespace atcoder;
 
// const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;

/* union by size */
struct dsu {
  int n;
  vector<int> sizes, marks;
  vector<vector<int> > graph;

  void init(int rn) {
    n = rn;
    sizes = vector<int>(n);
    fill(sizes.begin(), sizes.end(), 1);
    marks = vector<int>(n);
    for (int i = 0; i < n; i++) marks[i] = i;
    graph = vector<vector<int> >(n);
  }

  void mark(int m, int node) {
    if (marks[node] == m) return;

    marks[node] = m;

    for (int i: graph[node]) mark(m, i);
  }

  bool merge(int a, int b) {
    if (marks[a] == marks[b]) return 0;
    graph[a].push_back(b);
    graph[b].push_back(a);

    if (sizes[marks[a]] > sizes[marks[b]]) swap(a, b);

    sizes[marks[b]] += sizes[marks[a]];
    sizes[marks[a]] = 0;
    mark(marks[b], a);
	return 1;
  }

  int find(int n) { return marks[n]; }
};
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 15075;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

set<pair<ll, pair<ll, ll>>> edges;
set<pair<ll, pair<ll, ll>>> uedges;
set<ll> adj[200005];
bool vis[200005];
ll edge[1005][1005];
set<ll> aedges[200005];
set<ll> uv;
dsu d;
 
bool cmp(pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b) {
	return a.s < b.s;
}
 
ll check(set<pair<ll, pair<ll, ll>>>& edges) {
	uv.clear();
	for (ll i = 0; i < n; i++) uv.insert(i);
	
	ll ans = 0;
	
	for (ll i = 0; i < n; i++) vis[i] = 0;
	d.init(n);
	
	for (ll i = 0; i < n; i++) {
		if (!vis[i]) {
			uv.erase(i);
			queue<ll> q;
			
			q.push(i);
			
			while (!q.empty()) {
				ll x = q.front();
				q.pop();
				
				if (vis[x]) continue;
				vis[x] = 1;
				
				vector<ll> bad;
				for (ll y: uv) {
					if (adj[x].find(y) == adj[x].end()) {
						q.push(y);
						bad.push_back(y);
						d.merge(x, y);
					}
				}
				
				for (ll y: bad) uv.erase(y);
			}
		}
	}
			
	for (pair<ll, pair<ll, ll>> x: edges) {
		if (d.merge(x.s.f, x.s.s)) ans += x.f;
	}
	return ans;
}

ll check2(set<pair<ll, pair<ll, ll>>>& edges) {
	ll ans = 0;
	
	for (ll i = 0; i < n; i++) vis[i] = 0;
	d.init(n);
	
	for (ll i = 0; i < n; i++) {
		if (!vis[i]) {
			queue<ll> q;
			
			q.push(i);
			
			while (!q.empty()) {
				ll x = q.front();
				q.pop();
				
				if (vis[x]) continue;
				vis[x] = 1;
				
				for (ll y: aedges[x]) {
					q.push(y);
					d.merge(x, y);
				}
			}
		}
	}
			
	for (pair<ll, pair<ll, ll>> x: edges) {
		if (d.merge(x.s.f, x.s.s)) ans += x.f;
	}
	return ans;
}

void solve(int tc = 0) {
	cin >> n >> m;
	
	ll xs = 0;
	for (ll i = 0; i < m; i++) {
		ll x, y, z;
		cin >> x >> y >> z;
		--x; --y;
		adj[x].insert(y);
		adj[y].insert(x);
		edges.insert(pair{z, pair{x, y}});
		
		xs ^= z;
	}
	
	d.init(n);
	
	for (pair<ll, pair<ll, ll>> x: edges) {
		if (d.merge(x.s.f, x.s.s)) uedges.insert(x);
	}
	
	ll val = check(uedges);
		
	if (n > 800) {
		cout << val << '\n';
		return;
	}
	
	for (pair<ll, pair<ll, ll>> x: edges) edge[x.s.f][x.s.s] = edge[x.s.s][x.s.f] = x.f;
	
	d.init(n);
	
	for (ll i = 0; i < n; i++) {
		for (ll j = i + 1; j < n; j++) {
			if (!edge[i][j]) {
				if (!d.merge(i, j)) {
					cout << val << '\n';
					return;
				}
				aedges[i].insert(j);
				aedges[j].insert(i);
			}
		}
	}
	
	ll ans = 1e18;
	for (ll i = 0; i < n; i++) {
		for (ll j = i + 1; j < n; j++) {
			if (!edge[i][j] && i != j) {
				uedges.insert(pair{xs, pair{i, j}});
				aedges[i].erase(j);
				aedges[j].erase(i);
				ans = min(ans, check2(uedges));
				aedges[i].insert(j);
				aedges[j].insert(i);
				uedges.erase(pair{xs, pair{i, j}});
			}
		}
	}
	
	cout << ans << '\n';
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("code");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc2.cpp", "w", stdout);
		
	cout << setprecision(15) << fixed;
	
	
		
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}