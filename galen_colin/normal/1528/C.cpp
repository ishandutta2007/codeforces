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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds; 
 
template <typename num_t>
using ordered_set = tree<num_t, null_type, less<num_t>, rb_tree_tag, tree_order_statistics_node_update>;
 
// benq - print any container + pair
template<typename T, typename = void> struct is_iterable : false_type {};
template<typename T> struct is_iterable<T, void_t<decltype(begin(declval<T>())),decltype(end(declval<T>()))>> : true_type {};
template<typename T> typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type operator<<(ostream &cout, T const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename T> typename enable_if<is_iterable<T>::value&&!is_same<T, string>::value,ostream&>::type operator<<(ostream &cout, T const &v) {
	cout << "["; 
	for (auto it = v.begin(); it != v.end();) {
		cout << *it;
		if (++it != v.end()) cout << ", ";
	}
	return cout << "]";
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
const ll mod = 998244353;
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

struct sum_t {
  long long val;
  static const long long null_v = 0;

  sum_t(): val(0) {}
  sum_t(long long v): val(v) {}

  sum_t op(sum_t& other) {
    return sum_t(val + other.val);
  }
  
  sum_t lazy_op(sum_t& v, int size) {
    return sum_t(val + v.val * size);
  }
};

ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 53197;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;

segtree<sum_t> ch, par;

ll st[300005], en[300005];
vector<ll> ch1[300005], ch2[300005];
ll T;
ll ans, cur;
vector<pair<ll, ll>> ops;

void dfs2(ll v) {
	st[v] = ++T;

	for (ll x: ch2[v]) {
		dfs2(x);
	}

	en[v] = T;
}

void add(ll v, ll s) {
	ch.update(st[v], st[v], (v + 1) * s);
	par.update(st[v], en[v], (v + 1) * s);
}

void push(ll v) {
	// are we above

	pair<ll, ll> x = {-1, -1};

	ll val = ch.query(st[v], en[v]).val;

	// cout << "push " << v << " " << val << endl;

	if (val == 0) {
		val = par.query(st[v], st[v]).val;

	// 	for (ll i = 0; i < n; i++) cout << ch.query(i, i).val << " ";
	// cout << '\n';
	// for (ll i = 0; i < n; i++) cout << par.query(i, i).val << " ";
	// cout << '\n';

		if (val > 0) {
			--cur;
			x.s = val - 1;

			add(val - 1, -1);
		}

	// 	for (ll i = 0; i < n; i++) cout << ch.query(i, i).val << " ";
	// cout << '\n';
	// for (ll i = 0; i < n; i++) cout << par.query(i, i).val << " ";
	// cout << '\n';

		++cur;
		x.f = v;

		add(v, 1);

		// for (ll i = 0; i < n; i++) cout << ch.query(i, i).val << " ";
	// cout << '\n';
	// for (ll i = 0; i < n; i++) cout << par.query(i, i).val << " ";
	// cout << '\n';
	}

	ops.push_back(x);
}

void pop(ll v) {
	pair<ll, ll> x = ops.back();

	if (x.s != -1) {
		add(x.s, 1);
		++cur;
	}

	if (x.f != -1) {
		add(x.f, -1);
		--cur;
	}

	ops.pop_back();
}

void dfs1(ll v) {
	push(v);

	ans = max(ans, cur);
	// cout << v << " " << cur << endl;
	// for (ll i = 0; i < n; i++) cout << ch.query(i, i).val << " ";
	// cout << '\n';
	// for (ll i = 0; i < n; i++) cout << par.query(i, i).val << " ";
	// cout << '\n';
	// cout << "--------\n";

	for (ll x: ch1[v]) {
		dfs1(x);
	}

	pop(v);
}

void solve(int tc = 0) {
	cin >> n;

	ops.clear();
	
	for (ll i = 0; i < n; i++) a[i] = 0;
	ch.init(n, a);
	par.init(n, a);

	for (ll i = 0; i < n; i++) {
		ch1[i].clear();
		ch2[i].clear();
	}

	for (ll i = 1; i < n; i++) {
		cin >> x;
		--x;
		ch1[x].push_back(i);
	}

	for (ll i = 1; i < n; i++) {
		cin >> x;
		--x;
		ch2[x].push_back(i);
	}

	T = -1;
	dfs2(0);

	ans = 0;
	cur = 0;
	dfs1(0);

	cout << ans << '\n';
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
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
		
	cout << setprecision(15) << fixed;
 
	
		
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		solve(t);
	}
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cerr << setprecision(4) << fixed;
		cerr << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}