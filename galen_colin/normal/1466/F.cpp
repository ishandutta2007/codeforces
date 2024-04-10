#include <bits/stdc++.h>
using namespace std;
 
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
 
const lld pi = 3.14159265358979323846;
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 
/* union by size */
struct dsu {
  int n;
  vector<int> sizes, marks;
  vector<vector<int> > graph;
  vector<bool> act;

  void init(int rn) {
    n = rn;
    sizes = vector<int>(n);
    fill(sizes.begin(), sizes.end(), 1);
    marks = vector<int>(n);
    for (int i = 0; i < n; i++) marks[i] = i;
    graph = vector<vector<int> >(n);
	act = vector<bool>(n, 0);
  }

  void mark(int m, int node) {
    if (marks[node] == m) return;

    marks[node] = m;

    for (int i: graph[node]) mark(m, i);
  }

  bool merge(int a, int b) {
    if (marks[a] == marks[b] || (act[marks[a]] && act[marks[b]])) return 0;
    graph[a].push_back(b);
    graph[b].push_back(a);

    if (sizes[marks[a]] > sizes[marks[b]]) swap(a, b);

    sizes[marks[b]] += sizes[marks[a]];
	act[marks[b]] = act[marks[b]] | act[marks[a]];
    sizes[marks[a]] = 0;
    mark(marks[b], a);
	return 1;
  }

  int find(int n) { return marks[n]; }
};
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 6884;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

ll v[500005][2];
dsu d;
 
void solve(int tc = 0) {
	cin >> n >> m;
	
	for (ll i = 0; i < n; i++) {
		cin >> k;
		a[i] = k;
		for (ll j = 0; j < k; j++) {
			cin >> v[i][j];
			--v[i][j];
		}
	}
	
	d.init(m);
	
	ll ans = 1;
	vector<ll> s;
	for (ll i = 0; i < n; i++) {
		if (a[i] == 1) {
			if (!d.act[d.marks[v[i][0]]]) {
				ans = (ans * 2) % mod;
				s.push_back(i + 1);
				d.act[d.marks[v[i][0]]] = 1;
			}
		} else {
			if (d.merge(v[i][0], v[i][1])) {
				ans = (ans * 2) % mod;
				s.push_back(i + 1);
			}
		}
	}
	
	cout << ans << " " << s.size() << '\n';
	for (ll x: s) cout << x << " ";
	cout << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowpatibility");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
	// freopen("tc.cpp", "w", stdout);
 		
	// cout << setprecision(12) << fixed;
	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}