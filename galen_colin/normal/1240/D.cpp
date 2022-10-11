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
const ll template_array_size = 1e6 + 14742;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

ll mn[300005];
ll cnt[300005];
set<ll> pos[300005];
int best[300005][105];
int rev[300005];
lca_lift lca;

void addpar(ll v, ll p) {
	lca.attach(v, p);
	
	for (ll i = 0; i < 101; i++) best[v][i] = max(best[v][i], best[p][i]);
}

void solve(int tc = 0) {
	cin >> n;
	
	ans = 0;
	mn[0] = cnt[0] = 0;
	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < 102; j++) best[i][j] = -1;
	}
	
	for (ll i = 0; i <= n; i++) pos[i].clear();
	for (ll i = 0; i <= n; i++) rev[i] = -1;
	
	map<ll, ll> f;
	for (ll i = 0; i < n; i++) ++f[a[i]];
	
	vector<pair<ll, ll>> fv;
	for (pair<ll, ll> x: f) fv.push_back({x.s, x.f});
	
	vector<ll> big;
	for (ll i = 0; i < min(100LL, (ll)fv.size()); i++) big.push_back(fv[i].s);
	
	for (ll i = 0; i < big.size(); i++) rev[big[i]] = i;
	
	for (ll v = 0; v < n; v++) if (rev[a[v]] != -1) best[v][rev[a[v]]] = v;
		
	lca.init(n);
	
	for (ll i = 1; i < n; i++) {
		cnt[i] = 0;
		mn[i] = 0;
				
		if (a[i] == a[i - 1]) {
			cnt[i] = 1;
			if (i - 2 >= 0) cnt[i] += cnt[i - 2];
			mn[i] = 2;
			
			if (i - 2 >= 0) {
				addpar(i, i - 2);
				pos[a[i - 2]].insert(i - 2);
			}
		} else {
			ll loc = i - mn[i - 1] - 1;
			
			if (loc < 0) continue;
			
			if (a[i] == a[loc]) {
				cnt[i] = 1;
				if (loc - 1 >= 0) cnt[i] += cnt[loc - 1];
				mn[i] = mn[i - 1] + 2;
				
				if (loc - 1 >= 0) {
					addpar(i, loc - 1);
					pos[a[loc - 1]].insert(loc - 1);
				}
			} else {
				if (rev[a[i]] != -1) {
					ll loc = best[i - 1][rev[a[i]]];
					
					// cout << i - 1 << " " << a[i] << " " << rev[a[i]] << " " << loc << endl;
					// for (ll j = 0; j < big.size(); j++) cout << "b " << j << " " << big[j] << " " << best[i - 1][j] << endl;
					
					if (loc != -1) {
						mn[i] = i - loc + 1;
						cnt[i] = 1;
						if (loc - 1 >= 0) cnt[i] += cnt[loc - 1];
						
						if (loc - 1 >= 0) {
							addpar(i, loc - 1);
							pos[a[loc - 1]].insert(loc - 1);
						}
					}
					continue;
				}
				
				auto it = pos[a[i]].end();
				while (it != pos[a[i]].begin()) {
					--it;
					
					ll loc = *it;
					if (lca.get(i - 1, lca.depth[i - 1] - lca.depth[loc]) != loc) continue;
					
					// while (tot[p].size() && tot[p].back() > loc) {
						// vals[p][a[tot[p].back()]].pop_back();
						// tot[p].pop_back();
					// }
					
					mn[i] = i - loc + 1;
					cnt[i] = 1;
					if (loc - 1 >= 0) cnt[i] += cnt[loc - 1];
					
					if (loc - 1 >= 0) {
						addpar(i, loc - 1);
						pos[a[loc - 1]].insert(loc - 1);
					}
					break;
				}
			}
		}
		
		// cout << i << " " << cnt[i] << endl;
	}
	
	cout << accumulate(cnt, cnt + n, 0LL) << '\n';
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
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}