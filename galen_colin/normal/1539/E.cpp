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

template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    lazy = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int l, int r, num_t v) {
	if (l > r) return;
    update(0, 0, n - 1, l, r, v);
  }

  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
    eval_lazy(i, tl, tr);
	
	if (tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
	if (l > r) return num_t::null_v;
    return query(0, 0, n-1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tr < ql || qr < tl) return num_t::null_v;

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }

  void eval_lazy(int i, int l, int r) {
    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
    }

    lazy[i] = num_t();
  }
  
  ll find_less(ll start, ll v) {
	  return find_lessr(0, 0, n - 1, start, v);
  }
  
  ll find_lessr(ll i, ll tl, ll tr, ll s, ll v) {
	  ll mid = (tl + tr) / 2;
	  
	  if (tl == tr) {
		  return (tree[i].val < v ? tl : -1);
	  }
	  
	  if (s <= tl) {
		  if (tree[2 * i + 1].val < v) return find_lessr(2 * i + 1, tl, mid, s, v);
		  else return find_lessr(2 * i + 2, mid + 1, tr, s, v);
	  } else if (s <= mid) {
		  ll p = find_lessr(2 * i + 1, tl, mid, s, v);
		  if (p != -1) return p;
		  else return find_lessr(2 * i + 2, mid + 1, tr, s, v);
	  } else {
		  return find_lessr(2 * i + 2, mid + 1, tr, s, v);
	  }
	  return -1;
  }
  
  ll find_more(ll start, ll v) {
	  return find_morer(0, 0, n - 1, start, v);
  }
  
  ll find_morer(ll i, ll tl, ll tr, ll s, ll v) {
	  ll mid = (tl + tr) / 2;
	  
	  if (tl == tr) {
		  return (tree[i].val > v ? tl : -1);
	  }
	  
	  if (s <= tl) {
		  if (tree[2 * i + 1].val > v) return find_morer(2 * i + 1, tl, mid, s, v);
		  else return find_morer(2 * i + 2, mid + 1, tr, s, v);
	  } else if (s <= mid) {
		  ll p = find_morer(2 * i + 1, tl, mid, s, v);
		  if (p != -1) return p;
		  else return find_morer(2 * i + 2, mid + 1, tr, s, v);
	  } else {
		  return find_morer(2 * i + 2, mid + 1, tr, s, v);
	  }
	  return -1;
  }
};

struct min_t {
  long long val;
  static const long long null_v = 9223372036854775807LL;

  min_t(): val(0) {}
  min_t(long long v): val(v) {}

  min_t op(min_t& other) {
    return min_t(min(val, other.val));
  }
  
  min_t lazy_op(min_t& v, int size) {
    return min_t(val + v.val);
  }
};

struct max_t {
  long long val;
  static const long long null_v = -9223372036854775807LL;

  max_t(): val(0) {}
  max_t(long long v): val(v) {}

  max_t op(max_t& other) {
    return max_t(max(val, other.val));
  }
  
  max_t lazy_op(max_t& v, int size) {
    return max_t(val + v.val);
  }
};
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16318;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

pair<ll, ll> v[100005][2];
ll par[100005][2];
ll dp[100005][2];
set<ll> can[2];
vector<ll> del[100005][2];
segtree<min_t> rt[2];
segtree<max_t> lt[2];

ll live(ll i, ll t) {
	ll w = dp[i + 1][!t];
	
	ll lv = rt[t].find_less(i, a[i]);
	if (lv == -1) lv = n;
	ll rv = lt[t].find_more(i, a[i]);
	if (rv == -1) rv = n;
	
	// cout << i << " " << t << " " << lv << " " << rv << endl;
	
	return min({w, lv, rv});
}

void push(ll i, ll t) {
	ll d = live(i, t);
	
	// cout << i << " " << t << " " << d << endl;
	
	can[!t].insert(i);
	del[d][!t].push_back(i);
}

// think about edge cases... you know who these setters are
void solve(int tc = 0) {
	cin >> n >> m;
	n += 2;
	
	a[0] = 0;
	v[0][0] = {0, 0};
	v[0][1] = {0, 0};
	a[1] = 0;
	v[1][0] = {0, 0};
	v[1][1] = {0, 0};
	
	for (ll i = 2; i < n; i++) {
		cin >> a[i] >> v[i][0] >> v[i][1];
	}
	
	dp[n][0] = dp[n][1] = n;
	
	for (ll i = n - 1; i >= 0; i--) {
		for (ll j = 0; j < 2; j++) {
			if (v[i][j].f <= a[i] && a[i] <= v[i][j].s) {
				dp[i][j] = dp[i + 1][j];
			} else {
				dp[i][j] = i;
			}
		}
	}
	
	// for (ll i = 0; i < n; i++) {
		// cout << i << " | ";
		// for (ll j = 0; j < 2; j++) {
			// cout << dp[i][j] << " ";
		// }
		// cout << '\n';
	// }
	
	for (ll j = 0; j < 2; j++) {
		for (ll i = 0; i < n; i++) {
			c[i] = v[i][j].f;
		}
		lt[j].init(n, c);
		for (ll i = 0; i < n; i++) {
			c[i] = v[i][j].s;
		}
		rt[j].init(n, c);
	}
	
	memset(par, -1, sizeof(par));
	
	push(0, 0);
	par[1][1] = 0;
	push(1, 1);
	
	for (ll i = 2; i < n; i++) {
		for (ll j = 0; j < 2; j++) {
			for (ll x: del[i][j]) {
				can[j].erase(x);
			}
			
			// cout << "can " << i << " " << j << " |";
			// for (ll x: can[j]) cout << " " << x;
			// cout << " " << del[i][j] << '\n';
			
			if (can[j].size() > 0) {
				par[i][j] = *can[j].begin();
				if (par[i][j] == i) par[i][j] = -1;
				else push(i, j);
			}
		}
		
		for (ll j = 0; j < 2; j++) {
			for (ll x: del[i][j]) {
				can[j].erase(x);
			}
		}
	}
	
	// for (ll i = 0; i < n; i++) {
		// cout << i << " | ";
		// for (ll j = 0; j < 2; j++) {
			// cout << par[i][j] << " ";
		// }
		// cout << '\n';
	// }
	
	ll t = -1;
	if (par[n - 1][0] != -1) t = 0;
	if (par[n - 1][1] != -1) t = 1;
	
	if (t == -1) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		
		vector<ll> res;
		ll p = par[n - 1][t];
		for (ll i = n - 1; i >= 2; i--) {
			if (i == p) {
				t ^= 1;
				p = par[i][t];
			}
			res.push_back(t);
		}
		reverse(res.begin(), res.end());
		for (ll x: res) cout << x << " ";
		cout << '\n';
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