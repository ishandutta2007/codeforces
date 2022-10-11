// variation test #5

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
const ll mod = 1000000007;
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

const ll sent = 1e13;
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 15075;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;	

pair<ll, ll> p[200005];
pair<ll, ll> pb[200005];
segtree<min_t> st[2][2]; // b for (them, us)

void solve(int tc = 0) {
	cin >> n;
	
	for (ll i = 0; i < n; i++) {
		cin >> p[i].f;
	}
	for (ll i = 0; i < n; i++) {
		cin >> p[i].s;
	}
	
	sort(p, p + n);
	
	for (ll i = 0; i < n; i++) {
		pb[i] = {p[i].s, i};
	}
	sort(pb, pb + n);
	
	ll ans = 0;
	
	for (ll i = 0; i < n; i++) c[i] = sent;
	for (ll i = 0; i < 4; i++) st[i / 2][i % 2].init(n, c);
	
	for (ll i = 0; i < n; i++) {
		st[1][0].update(i, i, (-p[i].f + p[i].s) - sent - abs(p[i].f - p[i].s));
		st[1][1].update(i, i, (p[i].f + p[i].s) - sent - abs(p[i].f - p[i].s));
	}
	
	// for (ll i = 0; i < n; i++) cout << p[i] << " " << pb[i] << endl;
	
	ll pt = 0;
	for (ll i = 0; i < n; i++) {
		while (pt < n && pb[pt].f <= p[i].f) {
			ll j = pb[pt].s;
			st[1][0].update(j, j, -((-p[j].f + p[j].s) - sent - abs(p[j].f - p[j].s)));
			st[1][1].update(j, j, -((p[j].f + p[j].s) - sent - abs(p[j].f - p[j].s)));
			st[0][0].update(j, j, ((-p[j].f - p[j].s) - sent - abs(p[j].f - p[j].s)));
			st[0][1].update(j, j, ((p[j].f - p[j].s) - sent - abs(p[j].f - p[j].s)));
			++pt;
		}
		
		ll l = 0, r = n;
		while (l < r) {
			ll m = (l + r) / 2;
			
			if (p[m].f <= p[i].s) l = m + 1;
			else r = m;
		}
		
		
		ll cur = 1e18;
		if (l > 0) {
			cur = min(cur, st[1][0].query(0, l - 1).val - p[i].f + p[i].s);
			cur = min(cur, st[0][0].query(0, l - 1).val + p[i].f + p[i].s);
		}
		
		if (r < n) {
			cur = min(cur, st[1][1].query(r, n - 1).val - p[i].f - p[i].s);
			cur = min(cur, st[0][1].query(r, n - 1).val + p[i].f - p[i].s);
		}
		
		ans = min(ans, cur - abs(p[i].f - p[i].s));
		
		// cout << p[i] << " " << cur - abs(p[i].f - p[i].s) << " " << l << endl;
	}
	
	for (ll i = 0; i < n; i++) ans += abs(p[i].f - p[i].s);
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
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}