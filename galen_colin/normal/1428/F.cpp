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
// const ll mod = 1000000007;
// const ll mod = 998244353;
// ll mod;
 
struct segtree {
  int n, depth;
  ll tree[2100000], lazy[2100000];

  void init(int s, long long* arr) {
    n = s;
    memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));
    init(0, 0, n - 1, arr);
  }

  ll init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    ll a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = min(a, b);
  }

  void update(int l, int r, ll v) {
	if (l > r) return;
    update(0, 0, n - 1, l, r, v);
  }

  ll update(int i, int tl, int tr, int ql, int qr, ll v) {
    eval_lazy(i, tl, tr);
	
	if (tl > tr || tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] += v;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    if (tl == tr) return tree[i];

    int mid = (tl + tr) / 2;
    ll a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = min(a, b);
  }

  ll query(int l, int r) {
	if (l > r) return 0;
    return query(0, 0, n-1, l, r);
  }

  ll query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
	    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return 0;

    int mid = (tl + tr) / 2;
    ll a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return min(a, b);
  }

  void eval_lazy(int i, int l, int r) {
    tree[i] += lazy[i];
    if (l != r) {
      lazy[i * 2 + 1] += lazy[i];
      lazy[i * 2 + 2] += lazy[i];
    }

    lazy[i] = 0;
  }
  
  ll q(ll i, ll tl, ll tr, ll v) {
	 eval_lazy(i, tl, tr);
	 if (tl == tr) return tl;
	 
	 int mid = (tl + tr) / 2;
	 eval_lazy(2 * i + 1, tl, mid);
	 if (tree[2 * i + 1] < v) return q(2 * i + 1, tl, mid, v);
	 return q(2 * i + 2, mid + 1, tr, v);
  }
};
 
ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 2211;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

segtree st;

void solve(int tc = 0) {
	cin >> n >> s;
	
	memset(a, 0, sizeof(a));
	st.init(n, a);
	
	ll r = 0;
	
	ll pt = 0;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		if (s[i] == '0') {
			pt = i + 1;
		} else {
			ll len = i - pt + 1;
			
			ll v = st.q(0, 0, n - 1, len);
						
			st.update(v, i, 1);
			r += i - v + 1;
		}
		
		ans += r;
				
		// for (ll i = 0; i < n; i++) cout << st.query(i, i) << " ";
		// cout << '\n';
	}
	
	cout << ans << '\n';
}
 
int main() {
	#ifdef galen_colin_local
		auto begin = std::chrono::high_resolution_clock::now();
	#endif
	
	send help
 
	#ifndef galen_colin_local
		// usaco("moop");
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