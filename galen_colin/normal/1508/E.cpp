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
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 15075;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

vector<ll> edges[300005];
ll cnt[300005];
ll kill[300005], tot[300005];
ll st[300005], en[300005], rev[300005], tval = -1;
ll loc[300005];
ll par[300005];
lca_lift lca;

void dfs(ll v, ll p) {
	par[v] = p;
	st[v] = ++tval;
	rev[st[v]] = v;
	vector<pair<ll, ll>> ch;
	
	for (ll x: edges[v]) {
		if (x != p) {
			ch.push_back({a[x], x});
		}
	}
	
	sort(ch.begin(), ch.end());
	cnt[v] = ch.size();
	
	for (auto [x, y]: ch) {
		dfs(y, v);
	}
	
	en[v] = tval;
}

void swp(ll v, ll nxt, ll targ) {
	for (ll x: edges[v]) {
		// cout << "< " << v << " " << x << " " << nxt << " " << " " << targ << " " << b[x] << endl;
		if (b[x] == nxt) {
			swap(b[v], b[x]);
			if (nxt != targ) swp(x, nxt + 1, targ);
			return;
		}
	}
}

void solve(int tc = 0) {
	cin >> n;
	lca.init(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		--a[i];
		loc[a[i]] = i;
	}
	
	for (ll i = 0; i < n - 1; i++) {
		cin >> x >> y;
		--x; --y;
		edges[x].push_back(y);
		edges[y].push_back(x);
		lca.edge(x, y);
	}
	lca.init_lift();
	
	dfs(0, -1);
	
	set<pair<ll, ll>> vals;
	
	for (ll i = 0; i < n; i++) {
		if (cnt[i] == 0) {
			vals.insert({st[i], i});
		}
	}
	
	memset(b, -1, sizeof(b));
	
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll cur = vals.begin()->s;
		vals.erase(vals.begin());
		
		ans += lca.depth[loc[i]];

		if (loc[i] != cur) {
			if (!(st[loc[i]] <= st[cur] && en[cur] <= en[loc[i]])) {
				cout << "NO\n";
				return;
			} else {
				for (ll j = i; j < n; j++) {
					ll top = j - lca.depth[rev[j]];
					ll anc = max(0LL, i - top);
					
					// cout << j << " " << rev[j] << " " << top << " " << anc << endl;
					
					b[lca.get(rev[j], anc)] = j;
				}
				
				if (loc[i] != 0) swp(0, i + 1, b[loc[i]]);
				
				break;
			}
		}
		
		if (par[cur] > -1) {
			--cnt[par[cur]];
			if (cnt[par[cur]] == 0) vals.insert({a[par[cur]], par[cur]});
		}
		
		b[cur] = i;
	}
	
	bool pos = 1;
	for (ll i = 0; i < n; i++) pos &= (a[i] == b[i]);
		
	if (pos) {
		cout << "YES\n";
		cout << ans << '\n';
		for (ll i = 0; i < n; i++) cout << st[i] + 1 << " ";
		cout << '\n';
	} else {
		cout << "NO\n";
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