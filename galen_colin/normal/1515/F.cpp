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
// typedef int ll;
// #pragma warning("int")
 
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
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
ll mod;

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

  void merge(int a, int b) {
    if (marks[a] == marks[b]) return;
    graph[a].push_back(b);
    graph[b].push_back(a);

    if (sizes[marks[a]] > sizes[marks[b]]) swap(a, b);

    sizes[marks[b]] += sizes[marks[a]];
    sizes[marks[a]] = 0;
    mark(marks[b], a);
  }

  int find(int n) { return marks[n]; }
};
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16318;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

vector<pair<ll, ll>> edges[300005];
vector<ll> dir[300005];
ll iv[300005];
ll id[300005];
ll par[300005];

void dfs(ll v, ll p) {
	par[v] = p;		
	for (pair<ll, ll> x: edges[v]) {
		if (x.f != p) {
			dfs(x.f, v);
			id[x.f] = x.s + 1;
		}
	}
	
	if (p != -1) {
		if (a[v] >= x) {
			dir[v].push_back(p);
			++iv[p];
		} else {
			dir[p].push_back(v);
			++iv[v];
		}
		a[p] = a[v] + a[p] - x;
		a[v] = 0;
	}
}

void solve(int tc = 0) {
	cin >> n >> m >> x;
	
	ll s = 0;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
	}
	if (s < (n - 1) * x) {
		cout << "NO\n";
		return;
	}
	
	dsu d;
	d.init(n);
	
	for (ll i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		--x; --y;
		if (d.marks[x] != d.marks[y]) {
			d.merge(x, y);
			edges[x].push_back({y, i});
			edges[y].push_back({x, i});
		}
	}
	
	dfs(0, -1);
	
	queue<ll> q;
	
	for (ll i = 0; i < n; i++) {
		if (iv[i] == 0) {
			q.push(i);
		}
	}
	
	vector<ll> res;
	while (!q.empty()) {
		ll x = q.front();
		q.pop();
				
		if (x > 0) res.push_back(id[x]);
		
		for (ll y: dir[x]) {
			if (y == par[x]) {
				--iv[y];
				if (iv[y] == 0) q.push(y);
			}
		}
		
		for (ll y: dir[x]) {
			if (y != par[x]) {
				--iv[y];
				if (iv[y] == 0) q.push(y);
			}
		}
	}
	
	cout << "YES\n";
	for (ll x: res) cout << x << endl;
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
	
	// gen_btree();
		
	int tc = 1;
	// cin >> tc; 	
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}