#include <bits/stdc++.h>
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
const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;

#define madd(a, b) (a + b >= mod ? a + b - mod : a + b)

namespace modop {
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
}

using namespace modop;

const ll modrt = 110000LL * 1000000007;

struct segtree {
  int n, depth;
  ll tree[400005], lazy[400005];

  void init(int s, long long* arr) {
    n = s;
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));
  }

  ll ql, qr;

  void update(int l, int r, ll v) {
	ql = l; qr = r;
    update(0, 0, n - 1, v);
  }

  ll update(int i, int tl, int tr, ll v) {
    eval_lazy(i, tl, tr);
	if (tr < ql || qr < tl) return tree[i];
	
    if (ql <= tl && tr <= qr) {
      lazy[i] = madd(lazy[i], v);
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    int mid = (tl + tr) / 2;
    ll a = update(2 * i + 1, tl, mid, v),
       b = update(2 * i + 2, mid + 1, tr, v);
    return tree[i] = madd(a, b);
  }

  ll query(int l, int r) {
	ql = l; qr = r;
    return query(0, 0, n-1);
  }

  ll query(int i, int tl, int tr) {
    if (tr < ql || qr < tl) return 0;
    
    eval_lazy(i, tl, tr);
	
    if (ql <= tl && tr <= qr) return tree[i];

    int mid = (tl + tr) / 2;
    ll a = query(2 * i + 1, tl, mid),
       b = query(2 * i + 2, mid + 1, tr);
    return madd(a, b);
  }

  void eval_lazy(int i, int l, int r) {
	if (lazy[i] == 0) return;
    tree[i] = tree[i] + lazy[i] * (r - l + 1);
	tree[i] = (tree[i] >= modrt ? tree[i] - modrt : tree[i]);
    if (l != r) {
      lazy[i * 2 + 1] = madd(lazy[i * 2 + 1], lazy[i]);
      lazy[i * 2 + 2] = madd(lazy[i * 2 + 2], lazy[i]);
    }

    lazy[i] = 0;
  }
};

ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 14742;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

vector<ll> edges[100005];
bool vis[100005];
ll sz[100005];
pair<ll, ll> p[100005];
ll dep[100005];
segtree inv, dinv;
vector<ll> at;
ll vinv[100005];

void dfs(ll v, ll p, ll d) {
	at.push_back(v);
	dep[v] = d;
		
	for (ll x: edges[v]) {
		if (x != p && !vis[x]) {
			dfs(x, v, d + 1);
		}
	}
}

void ins(ll v, ll fac) {
	ll cnt = (p[v].s - p[v].f + 1);
	inv.update(p[v].f, p[v].s, fac * vinv[cnt]);
	dinv.update(p[v].f, p[v].s, fac * ((dep[v] * vinv[cnt]) % mod));
}

void query(ll v) {
	ll cnt = (p[v].s - p[v].f + 1);
	
	ll val = (dep[v] * (inv.query(p[v].f, p[v].s) % mod)) % mod;
	val = (val + dinv.query(p[v].f, p[v].s)) % mod;
	val = (val * vinv[cnt]) % mod;
		
	ans = madd(ans, val);
}

bool cmp(ll a, ll b) {
	return sz[a] < sz[b];
}

void add(ll v) {
	if (sz[v] <= 250) {
		at.clear();
		dfs(v, -1, 0);
		
		vector<ll> stor = at;
		
		for (ll i = 0; i < stor.size(); i++) {
			dfs(stor[i], -1, 0);
			for (ll j = i + 1; j < stor.size(); j++) {
				ll v = stor[i], x = stor[j];
				
				ll val = (vinv[p[v].s - p[v].f + 1] * vinv[p[x].s - p[x].f + 1]) % mod;
				val = (val * dep[x]) % mod;
				
				ll isect = max(0LL, min(p[v].s, p[x].s) - max(p[v].f, p[x].f) + 1);
				val = (val * isect) % mod;
								
				ans += val;
			}
		}
		return;
	}
	dep[v] = 0;
	
	ll cv = 0;
	for (ll x: edges[v]) cv += !vis[x];
	sort(edges[v].begin(), edges[v].end(), cmp);
	
	vector<ll> y;
	
	for (ll x: edges[v]) if (!vis[x]) y.push_back(x);
	
	if (y.size() > 1) swap(y[0], y[y.size() - 2]);
		
	for (ll i = 0; i < y.size(); i++) {
		ll x = y[i];
		if (!vis[x]) {
			at.clear();
			dfs(x, v, 1);
			
			for (ll x: at) {
				ll val = (vinv[p[v].s - p[v].f + 1] * vinv[p[x].s - p[x].f + 1]) % mod;
				val = (val * dep[x]) % mod;
				
				ll isect = max(0LL, min(p[v].s, p[x].s) - max(p[v].f, p[x].f) + 1);
				val = (val * isect) % mod;
				ans += val;
			}
			
			if (i > 0) for (ll x: at) query(x);
			if (i + 1 < y.size()) for (ll x: at) ins(x, 1);
		}
	}
		
	for (ll i = 0; i < y.size(); i++) {
		ll x = y[i];
		if (!vis[x]) {
			at.clear();
			dfs(x, v, 1);
			
			if (i + 1 < y.size()) for (ll x: at) ins(x, -1);
		}
	}
	
	ans %= mod;
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

void init_centroid(int v = 0, int p = -1) {
    find_size(v);

    int c = find_centroid(v, -1, sz[v]);
    
	find_size(c);
	
	add(c);
	
	vis[c] = true;
	
	if (sz[c] <= 250) return;
	
    for (int x: edges[c]) {
      if (!vis[x]) {
        init_centroid(x, c);
      }
    }
}

void solve(int tc = 0) {	
	cin >> n;
	for (ll i = 0; i < n; i++) {
		cin >> p[i];
		--p[i].f;
		--p[i].s;
	}
	
	for (ll i = 1; i <= 100000; i++) vinv[i] = minv(i);
	
	memset(a, 0, sizeof(a));
	inv.init(100000, a);
	dinv.init(100000, a);
	
	for (ll i = 0; i < n - 1; i++) {
		cin >> x >> y;
		--x; --y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	init_centroid();
	
	ll prod = 1;
	for (ll i = 0; i < n; i++) prod = (prod * (p[i].s - p[i].f + 1)) % mod;
	
	ans %= mod;
	ans = (ans * prod) % mod;
	if (ans < 0) ans += mod;
	cout << ans << '\n';
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
		// cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}