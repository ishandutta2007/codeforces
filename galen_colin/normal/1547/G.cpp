#include "bits/stdc++.h"
using namespace std;

// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")
 
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
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;

struct scc {
  vector<vector<int> > edges, redges;
  vector<bool> used;
  vector<int> order, component;
  int n;

  void init(int _n) {
    n = _n;
    edges = vector<vector<int> >(n);
    redges = vector<vector<int> >(n);
    order.clear();
    component.clear();
  }

  void edge(int u, int v) {
    edges[u].push_back(v);
    redges[v].push_back(u);
  }

  void dfs1(int v) {
    used[v] = true;
    for (int i = 0; i < edges[v].size(); i++) {
      if (!used[edges[v][i]]) {
        dfs1(edges[v][i]);
      }
    }
    order.push_back(v);
  }

  void dfs2(int v) {
    used[v] = true;
    component.push_back(v);
    for (int i = 0; i < redges[v].size(); i++) {
      if (!used[redges[v][i]]) {
        dfs2(redges[v][i]);
      }
    }
  }

  vector<vector<int> > run() {
    vector<vector<int> > components;
    used.assign(n, false);
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        dfs1(i);
      }
    }

    used.assign(n, false);
    for (int i = 0; i < n; i++) {
      int v = order[n - 1 - i];
      if (!used[v]) {
        dfs2(v);
        components.push_back(component);
        component.clear();
      }
    }

    return components;
  }
};
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16813;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

vector<ll> g[400005], cg[400005];
bool spec[400005];

void solve(int tc = 0) {
	cin >> n >> m;
	
	for (ll i = 0; i < n; i++) {
		g[i].clear();
		cg[i].clear();
		b[i] = 0;
		spec[i] = 0;
		a[i] = 0;
	}
	
	scc sc;
	sc.init(n);
	
	for (ll i = 0; i < m; i++) {
		cin >> x >> y;
		--x; --y;
		g[x].push_back(y);
		sc.edge(x, y);
	}
	
	vector<vector<int>> comp = sc.run();
		
	for (ll i = 0; i < comp.size(); i++) {
		for (ll x: comp[i]) {
			c[x] = i;
		}
	}
	
	for (ll i = 0; i < n; i++) a[i] = 0;
		
	for (ll i = 0; i < n; i++) {
		for (ll x: g[i]) {
			if (c[i] != c[x]) {
				cg[c[i]].push_back(c[x]);
				++b[c[x]];
			} else {
				spec[c[i]] = 1;
			}
		}
	}
	
	queue<ll> q;
	
	for (ll i = 0; i < comp.size(); i++) {
		if (b[i] == 0) {
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		ll x = q.front();
		q.pop();
		
		if (c[0] == x) {
			a[x] = 1;
		}
				
		if (a[x] > 0) {
			if (comp[x].size() > 1 || spec[x]) {
				a[x] = -1;
			}
		}
		
		for (ll y: cg[x]) {
			--b[y];
							
			if (a[x] == -1 || a[y] == -1) a[y] = -1;
			else a[y] = min(2LL, a[x] + a[y]);
			
			if (b[y] == 0) q.push(y);
		}
	}
	
	for (ll i = 0; i < n; i++) {
		cout << a[c[i]] << " ";
	}
	cout << '\n';
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
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}