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

struct segtree {
  int n, depth;
  vector<pair<ll, ll>> tree;
	vector<ll> lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<pair<ll, ll>>(4 * s, {1e9, 0});
    lazy = vector<ll>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  pair<ll, ll> init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = {arr[l], l};

    int mid = (l + r) / 2;
    pair<ll, ll> a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = min(a, b);
  }

  void update(int l, int r, ll v) {
    update(0, 0, n - 1, l, r, v);
  }

  pair<ll, ll> update(int i, int tl, int tr, int ql, int qr, ll v) {
    eval_lazy(i, tl, tr);

    if (ql <= tl && tr <= qr) {
      lazy[i] += v;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    if (tl > tr || tr < ql || qr < tl) return tree[i];
    if (tl == tr) return tree[i];

    int mid = (tl + tr) / 2;
    pair<ll, ll> a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = min(a, b);
  }

  pair<ll, ll> query(int l, int r) {
    return query(0, 0, n-1, l, r);
  }

  pair<ll, ll> query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return {1e9, -1};

    int mid = (tl + tr) / 2;
    pair<ll, ll> a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return min(a, b);
  }

  /* varies by implementation */
  /* this one is for range additions */
  void eval_lazy(int i, int l, int r) {
    /* special part */
    tree[i].f += lazy[i];
    if (l != r) {
      lazy[i * 2 + 1] += lazy[i];
      lazy[i * 2 + 2] += lazy[i];
    }
    /* end special part */

    lazy[i] = 0;
  }
};
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e5 + 16614;
ll a[template_array_size];
string s, t;

const ll B = 100;
ll res[1005][1005];
segtree st[1005];

void build(ll b) {
	ll lb = B * b, rb = min(n - 1, B * (b + 1) - 1);
		
	st[b].init(rb - lb + 1, a + lb);
	
	ll t = 0;
	for (ll p = 1; p <= B; p++) {
		auto x = st[b].query(0, rb - lb);
		ll c = max(0LL, x.f - t);
		st[b].update(x.s, rb - lb, -1);
		st[b].update(x.s, x.s, 1e6);
		
		t += c;
		res[b][p] = t;
	}
}

ll get(ll b, ll v) {
	ll lv = 0, rv = B + 1;
	
	while (lv < rv) {
		ll mv = (lv + rv) / 2;
		
		if (res[b][mv] > v) {
			rv = mv;
		} else {
			lv = mv + 1;
		}
	}
	return lv - 1;
}

void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> a[i], a[i] = (i + 1) - a[i];
	for (ll i = 0; i < n; i += B) build(i / B);
			
	cin >> q;
	for (ll i = 0; i < q; i++) {
		ll t; 
		cin >> t >> x;
		--x;
		if (t == 1) {
			cin >> y;
			a[x] = (x + 1) - y;
			build(x / B);
		} else {
			ll ans = a[x];
			ll p = x + 1;
			while (p < n) {
				if (p % B != 0) {
					ans += (ans >= a[p]);
					++p;
				} else {
					ans += get(p / B, ans);
					p += B;
				}
			}
			cout << ans << '\n';
		}
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