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
} lca;

template <typename num_t> 
struct segtree_ind {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    lazy = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = num_t(arr[l], l);

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
    return query(0, 0, n-1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return num_t::null_v;

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }
};

struct min_t {
  long long val;
  int ind;
  static const long long null_v = 9223372036854775807LL;

  min_t(): val(0) {}
  min_t(long long v): val(v) {}
  min_t(long long v, int i): val(v), ind(i) {};

  min_t op(min_t& other) {
    if (other.val == val) 
      return (ind > other.ind) ? other : *this;
    return (val > other.val) ? other : *this;
  }
  
  min_t lazy_op(min_t v, int size) {
    return min_t(val + v.val, ind);
  }
};

struct max_t {
  long long val;
  int ind;
  static const long long null_v = -9223372036854775807LL;

  max_t(): val(0) {}
  max_t(long long v): val(v) {}
  max_t(long long v, int i): val(v), ind(i) {};

  max_t op(max_t& other) {
    if (other.val == val) 
      return (ind > other.ind) ? other : *this;
    return (val < other.val) ? other : *this;
  }
  
  max_t lazy_op(max_t v, int size) {
    return max_t(val + v.val, ind);
  }
};

struct lca_t {
  long long val;
  int ind;
  static const long long null_v = -1;

  lca_t(): val(-1) {}
  lca_t(long long v): val(v) {}
  lca_t(long long v, int i): val(v), ind(i) {};

  lca_t op(lca_t& other) {
	  if (val == -1) return other;
	  if (other.val == -1) return *this;
    return lca_t(lca.get_lca(val, other.val), ind);
  }
  
  lca_t lazy_op(lca_t v, int size) {
    return v;
  }
};
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 15075;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

vector<ll> ch[100005];
segtree_ind<max_t> mx;
segtree_ind<min_t> mn;
segtree_ind<lca_t> lc;
ll st[100005], en[100005], tv = -1;

void dfs(ll v) {
	st[v] = ++tv;
	for (ll x: ch[v]) dfs(x);
	en[v] = tv;
}

void solve(int tc = 0) {
	cin >> n >> q;
	
	lca.init(n);
	
	for (ll i = 0; i < n - 1; i++) {
		cin >> x;
		--x;
		ch[x].push_back(i + 1);
		lca.edge(x, i + 1);
	}
	
	lca.init_lift();
	
	dfs(0);
	for (ll i = 0; i < n; i++) a[i] = st[i];
	
	mx.init(n, a);
	mn.init(n, a);
	iota(b, b + n, 0);
	lc.init(n, b);
	
	for (ll i = 0; i < q; i++) {
		cin >> l >> r;
		--l; --r;
		ll mnv = mn.query(l, r).ind;
		ll mxv = mx.query(l, r).ind;
				
		ll curv = -1, curi = -1;
		{
			ll cur = -1;
			if (mnv > l) {
				cur = lc.query(l, mnv - 1).val;
			}
			if (mnv < r) {
				ll v = lc.query(mnv + 1, r).val;
				if (cur == -1) cur = v;
				else cur = lca.get_lca(cur, v);
			}
						
			curv = lca.depth[cur];
			curi = mnv;
		}
		
		{
			ll cur = -1;
			if (mxv > l) {
				cur = lc.query(l, mxv - 1).val;
			}
			if (mxv < r) {
				ll v = lc.query(mxv + 1, r).val;
				if (cur == -1) cur = v;
				else cur = lca.get_lca(cur, v);
			}
			
			if (lca.depth[cur] > curv) {
				curv = lca.depth[cur];
				curi = mxv;
			}
		}
		
		cout << curi + 1 << " " << curv << '\n';
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