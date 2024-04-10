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
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 

 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 1389;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

/* union by size */
struct dsu {
  int n;
  vector<int> sizes, marks, cols;
  vector<vector<pair<int, int>> > graph;

  void init(int rn) {
    n = rn;
    sizes = vector<int>(n);
	cols = vector<int>(n);
    fill(sizes.begin(), sizes.end(), 1);
    marks = vector<int>(n);
    for (int i = 0; i < n; i++) marks[i] = i;
    graph = vector<vector<pair<int, int>> >(n);
  }

  void mark(int m, int node, int c) {
    if (marks[node] == m) return;

    marks[node] = m;
	cols[node] = c;

    for (pair<int, int> i: graph[node]) mark(m, i.f, c ^ i.s);
  }

  bool merge(int a, int b, int c) {
    if (marks[a] == marks[b]) {
		return ((cols[a] ^ cols[b]) == c);
	}
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});

    if (sizes[marks[a]] > sizes[marks[b]]) swap(a, b);

    sizes[marks[b]] += sizes[marks[a]];
    sizes[marks[a]] = 0;
    mark(marks[b], a, cols[b] ^ c);
	
	return 1;
  }

  int find(int n) { return marks[n]; }
};

dsu d;

map<string, ll> mp;
 
void solve(int tc = 0) {
	cin >> n >> m >> q;
	
	d.init(n);
	
	for (ll i = 0; i < n; i++) {
		cin >> s;
		mp[s] = i;
	}
	
	for (ll i = 0; i < m; i++) {
		cin >> z >> s >> t;
		x = mp[s];
		y = mp[t];
		
		bool r = d.merge(x, y, --z);
		if (r) cout << "YES\n";
		else cout << "NO\n";
	}
	
	for (ll i = 0; i < q; i++) {
		cin >> s >> t;
		x = mp[s];
		y = mp[t];
		
		if (d.marks[x] == d.marks[y]) {
			cout << ((d.cols[x] ^ d.cols[y]) + 1) << '\n';
		} else {
			cout << 3 << '\n';
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