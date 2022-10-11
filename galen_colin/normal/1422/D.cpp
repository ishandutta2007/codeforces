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
 
 struct dijkstra {
  int n;
  const ll inf = 4e18;
  vector<ll> dists; /* for a single run */
  vector<int> par;
  vector<bool> vis;
  vector<vector<pair<ll, int> > > edges; /* weight, to */
  
  void init(int s) {
    n = s;
    dists = vector<ll>(n);
	  vis = vector<bool>(n);
    par = vector<int>(n);
    edges = vector<vector<pair<ll, int> > >(n);
  }

  void edge(int a, int b, ll wt) {
    edges[a].push_back(make_pair(wt, b));
  }

  using ptype = pair<ll, int>;
  void run(int src) {
    fill(dists.begin(), dists.end(), inf);
	  fill(vis.begin(), vis.end(), false);
    fill(par.begin(), par.end(), -1);

    priority_queue<ptype, vector<ptype>, greater<ptype>> pq;
    dists[src] = 0;
    pq.push(make_pair(0, src));
    while (!pq.empty()) {
      ptype foc = pq.top();
      pq.pop();
	  
	    if (vis[foc.s]) continue;
	    vis[foc.s] = 1;
	  
      dists[foc.s] = min(dists[foc.s], foc.f);
      for (ptype x: edges[foc.s]) {
        ll d = dists[foc.s] + x.f;
        if (d < dists[x.s]) {
          dists[x.s] = d;
          par[x.s] = foc.s;
          pq.push(make_pair(d, x.s));
        }
      }
    }
  }
};
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 2047;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;
 
pair<pair<ll, ll>, ll> p[100005];
dijkstra d;

void solve(int tc) {
    cin >> n >> m;
	
	ll sx, sy, fx, fy;
	cin >> sx >> sy >> fx >> fy;
	
	for (ll i = 0; i < m; i++) {
		cin >> p[i].f;
		p[i].s = i;
	}
	
	d.init(m + 2); // start has index m, end has m + 1
	
	d.edge(m, m + 1, abs(sx - fx) + abs(sy - fy));
	
	for (ll i = 0; i < m; i++) {
		d.edge(m, i, abs(sx - p[i].f.f));
		d.edge(m, i, abs(sy - p[i].f.s));
		
		d.edge(i, m + 1, abs(fx - p[i].f.f) + abs(fy - p[i].f.s));
	}
	
	sort(p, p + m);
	for (ll i = 0; i < m; i++) {
		if (i > 0) {
			d.edge(p[i].s, p[i - 1].s, abs(p[i].f.f - p[i - 1].f.f));
		}
		if (i < m - 1) {
			d.edge(p[i].s, p[i + 1].s, abs(p[i].f.f - p[i + 1].f.f));
		}
	}
	
	for (ll i = 0; i < m; i++) swap(p[i].f.f, p[i].f.s);
	sort(p, p + m);
	for (ll i = 0; i < m; i++) swap(p[i].f.f, p[i].f.s);
	for (ll i = 0; i < m; i++) {
		if (i > 0) {
			d.edge(p[i].s, p[i - 1].s, abs(p[i].f.s - p[i - 1].f.s));
		}
		if (i < m - 1) {
			d.edge(p[i].s, p[i + 1].s, abs(p[i].f.s - p[i + 1].f.s));
		}
	}
	
	d.run(m);
	
	cout << d.dists[m + 1] << '\n';
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