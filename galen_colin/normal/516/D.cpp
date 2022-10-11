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
 
const lld pi = 3.14159265358979323846;
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;

struct bit {
  ll n;
  ll a[100005];
 
  void init(ll s) {
    memset(a, 0, sizeof(a));
    n = s;
  }
 
  void add(ll loc, long long x) {
    if (loc <= 0) return;
    while (loc <= n) {
      a[loc] += x;
      loc += loc & (-loc);
    }
  }
 
  long long query(ll loc) {
    long long sum = 0;
    while (loc > 0) {
      sum += a[loc];
      loc -= loc & (-loc);
    }
    return sum;
  }
  
  ll rq(ll l, ll r) {
	  return query(r + 1) - query(l);
  }
};

ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 14742;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

vector<pair<ll, ll>> edges[100005];
vector<ll> best[100005];
ll dep[100005];
ll dist[100005];
ll sz[100005];
bool on[100005];
ll st[100005], en[100005], tt = -1;
ll par[100005];
bit ft;

vector<ll> merge(vector<ll> a, vector<ll> b, ll off) {
	for (ll x: b) a.push_back(x + off);
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	while (a.size() > 2) a.pop_back();
	return a;
}

void dfsinit(ll v, ll p, ll d) {
	par[v] = p;
	st[v] = ++tt;
	dep[v] = d;
	sz[v] = 1;
	
	for (pair<ll, ll> x: edges[v]) {
		if (x.f != p) {
			dfsinit(x.f, v, d + x.s);
			sz[v] += sz[x.f];
		}
	}
	en[v] = tt;
}

void dfs1(ll v, ll p) {
	bool leaf = 1;
	for (pair<ll, ll> x: edges[v]) {
		if (x.f != p) {
			leaf = 0;
			dfs1(x.f, v);
			
			best[v] = merge(best[v], vector<ll>(1, best[x.f][0]), x.s);
		}
	}
	
	if (leaf) {
		best[v].push_back(0);
	}
	
	dist[v] = max(dist[v], best[v][0]);
}

void dfs2(ll v, ll p, ll pv) {
	// cout << v << " " << pv << " " << best[v] << endl;
	dist[v] = max({dist[v], best[v][0], pv});
	
	for (pair<ll, ll> x: edges[v]) {
		if (x.f != p) {
			ll val = best[v][0];
			if (best[x.f][0] + x.s == val) {
				if (best[v].size() > 1) val = best[v][1];
				else val = 0;
			}
			
			dfs2(x.f, v, max(pv, val) + x.s);
		}
	}
}

void upd(ll v, ll val) {
	v = par[v];
	if (v != -1) {
		ft.add(st[v], val);
	}
}

ll qv[1500005];

/* union by size */
struct dsu {
  ll n;
  ll sizes[200005], marks[100005], head[200005];
  vector<ll> graph[100005];
  ll nval, cnt = 0;

  void init(int rn) {
    n = rn;
    for (ll i = 0; i < n; i++) sizes[i] = 1;
    for (ll i = 0; i < n; i++) sizes[i + n] = 0;
    for (ll i = 0; i < n; i++) marks[i] = i;
	for (ll i = 0; i < n; i++) head[i] = head[i + n] = i;
    for (ll i = 0; i < n; i++) graph[i].clear();
	nval = n;
  }

  void mark(ll m, ll targ, ll node, ll bad) {
	  if (marks[node] != targ || node == bad) return;
	  ll qp = 0, qe = 0;
	  
	  qv[qe++] = node;
	  
	  while (qp < qe) {
		  ll node = qv[qp++];
		  
		  // if (marks[node] != targ || node == bad) continue;
		  
		  marks[node] = m;
		  ++cnt;
		  
		  for (ll i: graph[node]) if (i != bad && marks[i] == targ) qv[qe++] = i;
	  }
  }

  void merge(int a, int b) {
    if (marks[a] == marks[b]) return;
    graph[a].push_back(b);
    graph[b].push_back(a);

    if (sizes[marks[a]] > sizes[marks[b]]) swap(a, b);
	
	ll low = a, high = b;
	if (dep[low] < dep[high]) swap(low, high);
	upd(head[marks[low]], sizes[marks[low]]);
	upd(head[marks[high]], -sizes[marks[low]]);

    sizes[marks[b]] += sizes[marks[a]];
    sizes[marks[a]] = 0;
	
	if (dep[head[marks[a]]] < dep[head[marks[b]]]) head[marks[b]] = head[marks[a]];
	
    mark(marks[b], marks[a], a, -1);
	
	ans = max(ans, sizes[marks[b]]);
  }
  
  void split(int a, int b) {
	  if (marks[a] != marks[b]) return;
	  
	  ll h = head[marks[b]];
	  
	  if (dep[a] < dep[b]) swap(a, b);
	  ll v = ft.rq(st[a], en[a]);
	  if (v * 2 > sizes[marks[a]]) swap(a, b);
	  
	  cnt = 0;
	  // cout << a << " " << b << " " << marks[a] << " " << sizes[marks[a]] << " " << st[a] << " " << en[a] << " | ";
	  mark(nval, marks[a], a, b);
	  // cout << cnt << " " << v << " " << endl;
	  
	  ll low = a, high = b;
	  if (dep[low] < dep[high]) swap(low, high);
	  // cout << low << " " << high << endl;
	  head[marks[low]] = low;
	  head[marks[high]] = h;
	  
	  sizes[nval] = cnt;
	  sizes[marks[b]] -= cnt;
	  
	  upd(head[marks[low]], -sizes[marks[low]]);
	  upd(head[marks[high]], sizes[marks[low]]);
	  
	  // cout << nval << " " << b << " " << marks[b] << " " << sizes[nval] << " " << sizes[marks[b]] << endl;
	  
	  ++nval;
  }

  int find(int n) { return marks[n]; }
};

vector<pair<ll, ll>> vals;
dsu d;

void add(ll v) {
	on[v] = 1;
	for (pair<ll, ll> x: edges[v]) {
		if (on[x.f]) d.merge(x.f, v);
	}
}

void del(ll v) {
	// on[v] = 0;
	for (pair<ll, ll> x: edges[v]) {
		if (on[x.f]) d.split(x.f, v);
	}
	on[v] = 0;
}

void solve(int tc = 0) {
	cin >> n;
	// n = 100000;
	for (ll i = 0; i < n - 1; i++) {
		cin >> x >> y >> z;
		--x; --y;
		// x = i, y = i + 1, z = 1;
		edges[x].push_back({y, z});
		edges[y].push_back({x, z});
	}
	
	cin >> q;
	// q = 50;
	
	if (n == 2) {
		for (ll i = 0; i < q; i++) {
			cout << "2\n";
		}
		return;
	}
	
	ll root = 0;
	while (edges[root].size() == 1) ++root;
	
	assert(root < n);
	
	dfsinit(root, -1, 0);
	dfs1(root, -1);
	dfs2(root, -1, 0);
	
	for (ll i = 0; i < n; i++) vals.push_back({dist[i], i});
	sort(vals.begin(), vals.end());
	
	for (ll it = 0; it < q; it++) {
		cin >> k;
		// k = 10000000000LL;
				
		ft.init(n + 3);
		d.init(n);
		memset(on, 0, sizeof(on));
				
		ll pt = 0;
		ans = 1;
		for (ll i = 0; i < n; i++) {
			while (pt < n && vals[pt].f <= vals[i].f + k) {
				add(vals[pt].s);
				++pt;
			}
									
			del(vals[i].s);
			
			if (pt == n) break;
		}
		cout << ans << '\n';
		// cout << endl;
	}
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