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
 
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
// mt19937 rng(61378913);
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
	
	if (tl > tr || tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    if (tl == tr) return tree[i];
 
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
    if (tl > tr || tr < ql || qr < tl) return num_t::null_v;
 
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
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 3280;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;
 
ll lis(vector<ll> a) {
	ll n = a.size();
	
	if (n == 0) return 0;
	
	pair<ll, ll> b[n];
	for (ll i = 0; i < n; i++) b[i] = make_pair(a[i], i);
	sort(b, b + n);
	
	segtree<max_t> st;
	for (ll i = 0; i < n; i++) c[i] = 0;
	st.init(n, c);
	
	// cout << a << endl;
	
	ll x = 0;
	for (ll i = 0; i < n; i++) {
		ll v = st.query(0, b[i].s).val + 1;
		ll ov = st.query(b[i].s, b[i].s).val;
		
		if (v > ov) st.update(b[i].s, b[i].s, v - ov);
		
		x = max(x, v);
	}
	
	return x;
}
 
ll range(vector<ll> a, ll x) { // constraints: elements must be within [1, x + 1]
	ll n = a.size();
	
	if (n == 0) return 0;
	
	if (a.size() >= x) return -1;
				
	ll ans = 0;
	ll mx = 0;
	
	vector<ll> b;
	for (ll i = 0; i < n; i++) {
		a[i] -= i;
		if (a[i] < 1 || a[i] + i > x - (n - i)) {
			++ans;
		} else {
			b.push_back(a[i]);
		}
	}
	
	return n - lis(b);
}
 
void solve(int tc = 0) {
	cin >> n >> k;
	
	a[0] = -1e6;
	a[n + 1] = 1e9 + 1e6;
	
	for (ll i = 1; i <= n; i++) cin >> a[i];
	
	memset(b, 0, sizeof(b));
	b[0] = b[n + 1] = 1;
	
	for (ll i = 0; i < k; i++) {
		cin >> x;
		b[x] = 1;
	}
	
	n += 2;
	
	ll ans = 0;
	vector<ll> cur;
	ll last = -2e6;
	for (ll i = 0; i < n; i++) {
		// cout << i << endl;
		if (b[i]) {
			if (a[i] <= last) {
				cout << -1 << '\n';
				return;
			}
			
			for (ll& x: cur) x -= last;
			
			ll x = range(cur, a[i] - last);
			// cout << i << " " << x << " " << cur << " " << a[i] - last << endl;
			if (x == -1) {
				cout << -1 << '\n';
				return;
			}
			cur.clear();
			ans += x;
			
			last = a[i];
		} else {
			cur.push_back(a[i]);
		}
	}
	
	cout << ans << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("cowpatibility");
	#endif
	
	// usaco("cowland");
	
	// freopen("tc.cpp", "r", stdin);
 
 
	
	int tc = 1;
	// cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}