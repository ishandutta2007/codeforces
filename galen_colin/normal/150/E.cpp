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
 
typedef int ll;
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
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;

struct centroid {
  vector<vector<int> > edges, ch;
  vector<bool> vis;
  vector<int> par;
  vector<int> sz;
  int n;

  void init(int s) {
    n = s;
    edges = vector<vector<int> >(n, vector<int>());
    ch = vector<vector<int> >(n, vector<int>());
    vis = vector<bool>(n, 0);
    par = vector<int>(n);
    sz = vector<int>(n);
  }

  void edge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  int find_size(int v, int p = -1) {
    if (vis[v]) return 0;
    sz[v] = 1;

    for (int x: edges[v]) {
      if (x != p) {
        sz[v] += find_size(x, v);
      }
    }

    return sz[v];
  }

  int find_centroid(int v, int p, int n) {
    for (int x: edges[v]) {
      if (x != p) {
        if (!vis[x] && sz[x] > n / 2) {
          return find_centroid(x, v, n);
        }
      }
    }

    return v;
  }

  ll init_centroid(int v = 0, int p = -1) {
    find_size(v);

    int c = find_centroid(v, -1, sz[v]);
    vis[c] = true;
    par[c] = p;
	
	if (p != -1) ch[p].push_back(c);

    for (int x: edges[c]) {
      if (!vis[x]) {
        init_centroid(x, c);
      }
    }
	
	return c;
  }
};
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16318;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

centroid cd;
bool can;
pair<ll, ll> cur;
vector<pair<ll, ll>> edges[100005];
ll root;
vector<ll> vals[100005];
ll init_dep[100005];
bool vis[100005];
vector<pair<ll, ll>> sub;

ll val(ll e) {
	return (e >= m ? 1 : -1);
}

void add(ll v, ll p, ll d, ll t) {
	if (d == sub.size()) {
		sub.push_back({t, v});
	} else {
		if (t > sub[d].f) {
			sub[d] = {t, v};
		}
	}
	
	for (pair<ll, ll> x: edges[v]) {
		if (!vis[x.f] && x.f != p) {
			add(x.f, v, d + 1, t + val(x.s));
		}
	}
}

using T = pair<ll, ll>;
vector<T> frontv, backv;
vector<T> frontmx, backmx;

void clear() {
	frontv.clear();
	backv.clear();
	frontmx.clear();
	backmx.clear();
}

void push(T v) {
	frontv.push_back(v);
	if (frontmx.size()) frontmx.push_back(max(frontmx.back(), v)); // combine
	else frontmx.push_back(v);
}

void pop() {
	if (!backv.size()) {
		while (frontv.size()) {
			backv.push_back(frontv.back());
			if (backmx.size()) backmx.push_back(max(backmx.back(), frontv.back())); // combine
			else backmx.push_back(frontv.back());
			frontv.pop_back();
		}
		frontmx.clear();
	}
	if (!backv.size()) return; // popping nothing, btw
	backv.pop_back();
	backmx.pop_back();
}

T query() {
	if (frontmx.size() && backmx.size()) return max(frontmx.back(), backmx.back()); // combine
	if (frontmx.size()) return frontmx.back();
	if (backmx.size()) return backmx.back();
	return T{-1e9, -1}; // sentinel
}

vector<pair<ll, ll>> merge(vector<pair<ll, ll>> a, vector<pair<ll, ll>> b) {
	clear();
	
	// cout << a << " " << b << " " << cur << endl;
	
	for (ll i = b.size() - 1; i >= 0; i--) {
		if (l <= i && i <= r) {
			push(b[i]);
		}
	}
	
	for (ll i = 0; i < a.size(); i++) {
		pair<ll, ll> best = query();
		
		if (a[i].f + best.f >= 0) {
			can = 1;
			cur = {a[i].s, best.s};
		}
		
		if (0 <= r - i && r - i < b.size()) {
			pop();
		}
		if (0 <= l - i - 1 && l - i - 1 < b.size()) {
			push(b[l - i - 1]);
		}
	}
	
	// cout << a << " " << b << " " << cur << endl;
	
	assert(a.size() <= b.size());
		
	for (ll i = 0; i < a.size(); i++) {
		b[i] = max(a[i], b[i]);
	}
	return b;
}

void dfs(ll v) {
	vector<pair<ll, ll>> cv = vector<pair<ll, ll>>(1, pair{0, v});
	
	for (pair<ll, ll> x: edges[v]) {
		if (!vis[x.f]) {
			sub = vector<pair<ll, ll>>(1, pair{0, v});
			add(x.f, v, 1, val(x.s));
			cv = merge(cv, sub);
		}
	}
	
	vis[v] = 1;
	for (ll x: cd.ch[v]) dfs(x);
}

bool check() {
	can = 0;
	
	memset(vis, 0, sizeof(vis));
	dfs(root);
	
	return can;
}

ll worst(ll v, ll p, ll d) {
	ll s = d;
	for (pair<ll, ll> x: edges[v]) {
		if (!vis[x.f] && x.f != p) {
			s = max(s, worst(x.f, v, d + 1));
		}
	}
	return s;
}

void init_stuff(ll v) {
	for (pair<ll, ll> x: edges[v]) {
		if (!vis[x.f]) {
			init_dep[x.f] = worst(x.f, v, 1);
		}
	}
	
	sort(edges[v].begin(), edges[v].end(), [](pair<ll, ll> a, pair<ll, ll> b) {
		return init_dep[a.f] < init_dep[b.f];
	});
	
	vis[v] = 1;
	for (ll x: cd.ch[v]) init_stuff(x);
}

void solve(int tc = 0) {
	cin >> n >> l >> r;
		
	cd.init(n);
	
	for (ll i = 0; i < n - 1; i++) {
		cin >> x >> y >> z;
		--x; --y;
		cd.edge(x, y);
		
		edges[x].push_back({y, z});
		edges[y].push_back({x, z});
	}
		
	root = cd.init_centroid();
	
	memset(vis, 0, sizeof(vis));
	init_stuff(root);
	
	pair<ll, ll> ans;
	ll best = -1;
	
	ll lv = 0, rv = 1e9 + 7;
	while (lv < rv) {
		m = (lv + rv) / 2;

		if (check()) {
			if (m > best) {
				best = m;
				ans = cur;
			}
			lv = m + 1;
		} else {
			rv = m;
		}
	}
	
	// cout << cur << " " << ans << endl;
	
	// cout << lv - 1 << '\n';
	cout << ans.f + 1 << " " << ans.s + 1 << '\n';
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
	
	// gen_btree();
		
	int tc = 1;
	// cin >> tc; 	
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}