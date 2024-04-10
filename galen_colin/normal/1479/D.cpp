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
 
// mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng(61378913);
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

struct lca_lift {
  const int lg = 24;
  int n;
  vector<int> depth;
  vector<vector<int> > edges;
  vector<vector<int> > lift;
  
  void init(int sz) {
    n = sz;
    depth = vector<int>(n);
    edges = vector<vector<int> >(n, vector<int>());
    lift = vector<vector<int> >(n, vector<int>(lg, -1));
  }

  void edge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  void attach(int node_to_attach, int node_to_attach_to) {
    int a = node_to_attach, b = node_to_attach_to;
    edge(a, b);

    lift[a][0] = b;

    for (int i = 1; i < lg; i++) {
      if (lift[a][i - 1] == -1) lift[a][i] = -1;
      else lift[a][i] = lift[lift[a][i - 1]][i - 1];
    }

    depth[a] = depth[b] + 1;
  }

  void init_lift(int v = 0) {
    depth[v] = 0;
    dfs(v, -1);
  }

  void dfs(int v, int par) {
    lift[v][0] = par;

    for (int i = 1; i < lg; i++) {
      if (lift[v][i - 1] == -1) lift[v][i] = -1;
      else lift[v][i] = lift[lift[v][i - 1]][i - 1];
    }

    for (int x: edges[v]) {
      if (x != par) {
        depth[x] = depth[v] + 1;
        dfs(x, v);
      }
    }
  }

  int get(int v, int k) {
    for (int i = lg - 1; i >= 0; i--) {
	  if (v == -1) return v;
      if ((1 << i) <= k) {
        v = lift[v][i];
        k -= (1 << i);
      }
    }
    return v;
  }

  int get_lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    int d = depth[a] - depth[b];
    int v = get(a, d);
    if (v == b) {
      return v;
    } else {
      for (int i = lg - 1; i >= 0; i--) {
        if (lift[v][i] != lift[b][i]) {
          v = lift[v][i];
          b = lift[b][i];
        }
      }
      return lift[b][0];
    }
  }
  
  int get_dist(int a, int b) {
	  int v = get_lca(a, b);
	  return depth[a] + depth[b] - 2 * depth[v];
  }
};
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 8061;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

const ll C = 550;
const ll B = 800;
const ll blocks = 300002 / C + 1;

pair<ll, ll> qr[300005];
pair<pair<ll, ll>, pair<ll, ll>> qv[300005];
ll res[300005];
vector<ll> edges[300005];
lca_lift lca;
ll st[300005], en[300005], T = -1;
ll v[600005];

void dtime(ll v, ll p) {
	st[v] = ++T;
	for (ll x: edges[v]) if (x != p) dtime(x, v);
	en[v] = ++T;
}

void flip(ll p) {
	p = v[p];
	b[p / C] -= a[p];
	a[p] ^= 1;
	b[p / C] += a[p];
}

ll search(ll ql, ll qr) {
	for (ll i = 0; i < blocks; i++) {
		if (b[i] > 0) {
			ll bl = i * C;
			ll br = bl + C - 1;
			
			ll il = max(bl, ql), ir = min(br, qr);
			if (il <= ir) {
				for (ll j = il; j <= ir; j++) {
					if (a[j] > 0) {
						return j;
					}
				}
			}
		}
	}
	
	return -1;
}

void solve(int tc = 0) {
	cin >> n >> q;
	
	lca.init(n);
	for (ll i = 0; i < n; i++) cin >> c[i];
	
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	
	for (ll i = 0; i < n - 1; i++) {
		cin >> x >> y;
		--x; --y;
		lca.edge(x, y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	dtime(0, -1);
	lca.init_lift();
	
	for (ll i = 0; i < n; i++) v[st[i]] = c[i], v[en[i]] = c[i];
	
	for (ll i = 0; i < q; i++) {
		ll u, v;
		cin >> u >> v >> qr[i];
		--u; --v;
				
		if (st[u] > st[v]) swap(u, v);
		ll l = lca.get_lca(u, v);
		if (l == u) { 
			qv[i].f.f = st[u];
			qv[i].f.s = st[v];
			qv[i].s.f = -1;
		} else {
			qv[i].f.f = en[u];
			qv[i].f.s = st[v];
			qv[i].s.f = st[l];
		}
		qv[i].s.s = i;
	}
	
	sort(qv, qv + q, [](pair<pair<ll, ll>, pair<ll, ll>> a, pair<pair<ll, ll>, pair<ll, ll>> b) {
		if (a.f.f / B == b.f.f / B) {
			return ((a.f.f / B) % 2 == 0) ? a.f.s < b.f.s : a.f.s > b.f.s;
		}
		return a.f.f / B < b.f.f / B;
	});
	
	ll lp = 0, rp = -1;
	for (ll i = 0; i < q; i++) {
		pair<ll, ll> l = qv[i].f;
		while (lp < l.f) flip(lp++);
		while (lp > l.f) flip(--lp);
		while (rp < l.s) flip(++rp);
		while (rp > l.s) flip(rp--);
		
		if (qv[i].s.f != -1) flip(qv[i].s.f);
		res[qv[i].s.s] = search(qr[qv[i].s.s].f, qr[qv[i].s.s].s);
		if (qv[i].s.f != -1) flip(qv[i].s.f);
	}
	
	for (ll i = 0; i < q; i++) cout << res[i] << '\n';
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
	// freopen("tc.cpp", "w", stdout);
 		
	cout << setprecision(12) << fixed;
					
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}