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
 
template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s) {
    n = s;
    tree = vector<num_t>(4 * s, num_t(0, -1));
    lazy = vector<num_t>(4 * s, num_t(0, -1));
  }

  void update(int l, int r, num_t v) {
    update(0, 0, n - 1, l, r, v);
  }

  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
    eval_lazy(i, tl, tr);
	
		if (tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].op(v);
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
    return query(0, 0, n-1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tr < ql || qr < tl) return num_t(0, -1);

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }

  void eval_lazy(int i, int l, int r) {
    tree[i] = tree[i].op(lazy[i]);
		
    if (l != r) {
      lazy[i * 2 + 1] = lazy[i].op(lazy[i * 2 + 1]);
      lazy[i * 2 + 2] = lazy[i].op(lazy[i * 2 + 2]);
    }
  }
};

struct max_t {
  long long val, ind;

  max_t(): val(0) {}
  max_t(long long v): val(v) {}
  max_t(long long v, long long i): val(v), ind(i) {}

  max_t op(max_t& other) {
    return val < other.val ? other : *this;
  }
};
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16813;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

pair<ll, ll> p[300005];
pair<ll, ll> dp[300005];
segtree<max_t> st;

vector<pair<ll, ll>> iv[300005];
 
void solve(int tc = 0) {
	cin >> n >> m;
	
	vector<ll> coords;
	
	for (ll i = 0; i < m; i++) {
		cin >> x >> l >> r;
		coords.push_back(l);
		coords.push_back(r);
		p[i] = {l, r};
		a[i] = --x;
	}
	
	getunique(coords);
	
	map<ll, ll> rev;
	for (ll i = 0; i < coords.size(); i++) rev[coords[i]] = i;
		
	for (ll i = 0; i < m; i++) {
		p[i].f = rev[p[i].f];
		p[i].s = rev[p[i].s];
		iv[a[i]].push_back(p[i]);
	}
	
	st.init(coords.size());
	
	pair<ll, ll> ans = {0, -1};
	
	for (ll i = 0; i < n; i++) {
		pair<ll, ll> cur = {0, -1};
		
		for (pair<ll, ll> x: iv[i]) {
			max_t res = st.query(x.f, x.s);
						
			if (res.val > cur.f) {
				cur = {res.val, res.ind};
			}
		}
					
		dp[i] = cur;
		
		++dp[i].f;
		for (pair<ll, ll> x: iv[i]) {
			st.update(x.f, x.s, max_t(dp[i].f, i));
		}
		
		ans = max(ans, pair{dp[i].f, i});
	}
	
	pair<ll, ll> targ = ans;
	while (targ.s != -1) {
		c[targ.s] = 1;
		targ = dp[targ.s];
	}
		
	cout << n - ans.f << '\n';
	
	for (ll i = 0; i < n; i++) {
		if (!c[i]) {
			cout << i + 1 << " ";
		}
	}
	cout << '\n';
}

int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("evacuation");
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