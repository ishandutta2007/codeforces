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
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 1600;
int a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;
 
bool rem[500005];
int comp[500005];
pair<int, int> ed[500005];
pair<int, int> qv[500005];
set<pair<int, int>> vals[500005];
pair<int, int> targ[500005];
vector<pair<int, int>> edges[500005];
dsu d;
 
void relabel(int v, int compv) {
	if (a[v] != 0) {
		vals[comp[v]].erase(make_pair(a[v], v));
		comp[v] = compv;
		vals[comp[v]].insert(make_pair(a[v], v));
	}
	comp[v] = compv;
	
	for (pair<int, int> x: edges[v]) {
		if (!rem[x.s] && comp[x.f] != compv) {
			relabel(x.f, compv);
		}
	}
}
 
void solve(int tc = 0) {
	cin >> n >> m >> q;
	
	for (int i = 0; i < n; i++) cin >> a[i];
	
	for (int i = 0; i < m; i++) {
		cin >> ed[i];
		--ed[i].f;
		--ed[i].s;
	}
	
	memset(rem, 0, sizeof(rem));
	
	for (int i = 0; i < q; i++) {
		cin >> qv[i];
		--qv[i].s;
		if (qv[i].f == 2) rem[qv[i].s] = 1;
	}
	
	d.init(n);
		
	for (int i = 0; i < m; i++) {
		if (!rem[i]) d.merge(ed[i].f, ed[i].s);
	}
	
	for (int i = q - 1; i >= 0; i--) {
		if (qv[i].f == 2) {
			pair<ll, ll> e = ed[qv[i].s];
			if (d.marks[e.f] == d.marks[e.s]) targ[i].f = -1;
			else {
				if (d.sizes[d.marks[e.f]] > d.sizes[d.marks[e.s]]) swap(e.f, e.s);
				targ[i] = e;
				d.merge(e.f, e.s);
			}
		}
	}
		
	for (int i = 0; i < n; i++) {
		comp[i] = d.marks[i];
		
		vals[comp[i]].insert(make_pair(a[i], i));
	}
	
	memset(rem, 0, sizeof(rem));
	
	for (int i = 0; i < m; i++) {
		edges[ed[i].f].push_back(make_pair(ed[i].s, i));
		edges[ed[i].s].push_back(make_pair(ed[i].f, i));
	}
	
	int comp_val = n;
		
	for (int i = 0; i < q; i++) {
		if (qv[i].f == 1) {
			if (!vals[comp[qv[i].s]].size()) cout << 0 << '\n';
			else {
				auto it = --vals[comp[qv[i].s]].end();
				cout << it->f << '\n';
				a[it->s] = 0;
				vals[comp[qv[i].s]].erase(it);
			}
			
			// for (ll i = 0; i < n; i++) cout << comp[i] << " ";
			// cout << '\n';
		} else {
			rem[qv[i].s] = 1;
			if (targ[i].f != -1) {			
				relabel(targ[i].f, comp_val);
				++comp_val;
			}
		}
	}
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