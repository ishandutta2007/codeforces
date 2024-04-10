#include <bits/stdc++.h>
using namespace std;
 
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL); cout.tie(NULL);}
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
const ll mod = 998244353;
// ll mod;
 
template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<num_t>(4 * s, -1e16);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int p, num_t v) {
    update(0, 0, n - 1, p, v);
  }

  num_t update(int i, int tl, int tr, int q, num_t v) {
	if (tl > tr || tr < q || q < tl) return tree[i];
    if (tl == tr) {
      return tree[i] = v;
    }
    
    int mid = (tl + tr) / 2;
    num_t a = update(2 * i + 1, tl, mid, q, v),
          b = update(2 * i + 2, mid + 1, tr, q, v);
    return tree[i] = a.op(b);
  }

  num_t query(int l, int r) {
    return query(0, 0, n-1, l, r);
  }

  num_t query(int i, int tl, int tr, int ql, int qr) {
    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return num_t();

    int mid = (tl + tr) / 2;
    num_t a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a.op(b);
  }
};

const ll inf = 1e16;

struct weird_t {
  long long best[2];
  long long worst[2];

  weird_t() {
	  best[0] = 0;
	  best[1] = -inf;
	  worst[0] = 0;
	  worst[1] = inf;
  }
  weird_t(long long v) {
	  best[0] = 0;
	  best[1] = v;
	  worst[0] = 0;
	  worst[1] = v;
  }

  weird_t op(weird_t& other) {
    weird_t next;
	
	next.best[0] = max(best[0], other.best[0]);
	next.best[0] = max(next.best[0], best[0] + other.best[0]);
	next.best[0] = max(next.best[0], best[1] - other.worst[1]);
	
	next.best[1] = max(best[1], other.best[1]);
	next.best[1] = max(next.best[1], best[0] + other.best[1]);
	next.best[1] = max(next.best[1], best[1] - other.worst[0]);
	
	next.worst[0] = min(worst[0], other.worst[0]);
	next.worst[0] = min(next.worst[0], worst[0] + other.worst[0]);
	next.worst[0] = min(next.worst[0], worst[1] - other.best[1]);
	
	next.worst[1] = min(worst[1], other.worst[1]);
	next.worst[1] = min(next.worst[1], worst[0] + other.worst[1]);
	next.worst[1] = min(next.worst[1], worst[1] - other.best[0]);
	
	return next;
  }
};

ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 1600;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

segtree<weird_t> st;

void answer() {
	weird_t res = st.query(0, n - 1);
	cout << max(res.best[0], res.best[1]) << '\n';
}

void solve(int tc = 0) {
	// in school, go away
	
	cin >> n >> q;
	
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	st.init(n, a);
	
	answer();
	
	for (ll i = 0; i < q; i++) {
		cin >> l >> r;
		--l; --r;
		swap(a[l], a[r]);
		st.update(l, a[l]);
		st.update(r, a[r]);
		answer();
	}
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
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);
	
	#ifdef galen_colin_local
		auto end = std::chrono::high_resolution_clock::now();
		cout << setprecision(4) << fixed;
		// cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
	#endif
}