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
const ll mod = 998244353;
// ll mod;
 
namespace modop {
	ll madd(ll a, ll b) {
	  return (a + b) % mod;
	}
	ll msub(ll a, ll b) {
	  return (((a - b) % mod) + mod) % mod;
	}
	ll mmul(ll a, ll b) {
	  return ((a % mod) * (b % mod)) % mod;
	}
	ll mpow(ll base, ll exp) {
	  ll res = 1;
	  while (exp) {
		if (exp % 2 == 1){
			res = (res * base) % mod;
		}
		exp >>= 1;
		base = (base * base) % mod;
	  }
	  return res;
	}
	ll minv(ll base) {
	  return mpow(base, mod - 2);
	}
	ll mdiv(ll a, ll b) {
	  return mmul(a, minv(b));
	}
}

using namespace modop;
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 3862;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

vector<int> gadj[500005], oadj[500005];
vector<pair<int, int>> temp_adj[500005];
map<ll, vector<pair<int, int>>> tadj;
// gadj - adj list within group
// oadj - adj list everywhere else
vector<int> groups[500005];
int targ;

int col[500005];
bool vis[500005];
int comp[500005];
int G;

bool dfs(int x, int c) {
	if (vis[x]) return 1;
	vis[x] = 1;
	col[x] = c;
	comp[x] = G;
	
	bool pos = 1;
	int inv = 3 - c;
	for (int y: gadj[x]) {
		if (col[y] == col[x]) {
			return 0;
		}
		pos &= dfs(y, inv);
	}
	return pos;
}

bool color(const vector<int>& g) {
	for (int x: g) {
		col[x] = 0;
		vis[x] = 0;
		comp[x] = 0;
	}
	
	bool pos = 1;
	for (int x: g) {
		if (!vis[x]) {
			pos &= dfs(x, 1);
			++G;
		}
	}
	
	return pos;
}

inline pair<int, int> getp(pair<int, int> x) {
	return make_pair(min(x.f, x.s), max(x.f, x.s));
}

inline pair<int, int> get(int a, int b) {
	return make_pair(min(a, b), max(a, b));
}

bool ok[500005];

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
  
  void kill(int i) {
	  sizes[i] = 0;
	  marks[i] = i;
	  cols[i] = 0;
	  graph[i].clear();
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
 
void solve(int tc = 0) {
	cin >> n >> m >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		--a[i];
		groups[a[i]].push_back(i);
	}
	
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		--x; --y;
		if (a[x] == a[y]) {
			gadj[x].push_back(y);
			gadj[y].push_back(x);
		} else {
			oadj[x].push_back(y);
			oadj[y].push_back(x);
			ll b = min(a[x], a[y]);
			int c = max(a[x], a[y]);
			tadj[b * n + c].push_back(make_pair(x, y));
		}
	}
	
	memset(col, 0, sizeof(col));
	memset(vis, 0, sizeof(vis));
	memset(ok, 0, sizeof(ok));
	
	vector<int> valid;
	for (int i = 0; i < k; i++) {
		targ = i;
		if (color(groups[i])) {
			valid.push_back(i);
			ok[i] = 1;
		}
	}
	
	int ans = 0;
	
	vector<pair<int, int>> p;
	
	for (int x: valid) { // for each valid group
		for (int y: groups[x]) { // for each member of that group
			for (int z: oadj[y]) { // for each edge
				if (ok[a[z]]) {
					p.push_back(get(x, a[z]));
				}
			}
		}
	}
	
	sort(p.begin(), p.end());
	
	vector<pair<int, int>> pairs;
	for (ll i = 0; i < p.size(); i++) {
		if (!i || p[i] != p[i - 1]) pairs.push_back(p[i]);
	}
	
	dsu d;
	d.init(n);
		
	for (pair<int, int> x: pairs) {
		// cout << x << endl;
		G = 0;
		// targ = x.f;
		// color(groups[targ]);
		// targ = x.s;
		// color(groups[targ]);
				
		bool pos = 1;
		
		ll a = min(x.f, x.s);
		int b = max(x.f, x.s);
		const vector<pair<int, int>>& z = tadj[a * n + b];
		for (const pair<int, int>& y: z) {
			pos &= d.merge(comp[y.f], comp[y.s], (col[y.f] - 1) ^ (col[y.s] - 1));
			// cout << x << " " << y << " " << comp[y.f] << " " << comp[y.s] << endl;
		}
		
		ans += !pos;
		
		for (const pair<int, int>& y: z) {
			d.kill(comp[y.f]);
			d.kill(comp[y.s]);
		}
	}
	
	ll s = valid.size();
	cout << s * (s - 1) / 2 - ans << '\n';
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
 	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}