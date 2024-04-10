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
 
struct segtree {
  int n, depth;
  vector<ll> tree;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<ll>(4 * s, -1);
    init(0, 0, n - 1, arr);
  }

  ll init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    ll a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = min(a, b);
  }

  void update(int p, ll v) {
    update(0, 0, n - 1, p, v);
  }

  ll update(int i, int tl, int tr, int q, ll v) {
  if (tr < q || q < tl || tl > tr) return tree[i];
    if (tl == tr) {
      return tree[i] = v;
    }
    
    int mid = (tl + tr) / 2;
    ll a = update(2 * i + 1, tl, mid, q, v),
          b = update(2 * i + 2, mid + 1, tr, q, v);
    return tree[i] = min(a, b);
  }

  ll query(int l, int r) {
    return query(0, 0, n-1, l, r);
  }

  ll query(int i, int tl, int tr, int ql, int qr) {
    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return 1e9;

    int mid = (tl + tr) / 2;
    ll a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return min(a, b);
  }
  
  ll bs(int i, int tl, int tr, int v) {
	  if (tree[i] >= v) return tr + 1;
	  if (tl == tr) return tl;
	  
	  int mid = (tl + tr) / 2;
	  if (tree[2 * i + 1] < v) return bs(2 * i + 1, tl, mid, v);
	  else return bs(2 * i + 2, mid + 1, tr, v);
  }
};

ll n, m, k, q, l, r, x, y, z;
const ll template_array_size = 1e6 + 3280;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;
 
vector<ll> vals[100005];
bool pos[100005];
ll last[100005];
segtree st;

void solve(int tc = 0) {
	cin >> n;
	
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	bool all_one = 1;
	for (ll i = 0; i < n; i++) {
		if (a[i] != 1) all_one = 0;
	}
	
	if (all_one) {
		cout << 1 << '\n';
		return;
	}
		
	for (ll i = 0; i < n; i++) {
		vals[a[i]].push_back(i);
	}
	for (ll i = 0; i <= n + 1; i++) vals[i].push_back(n);
	
	memset(pos, 0, sizeof(pos));
	
	vector<pair<pair<ll, ll>, ll>> qv;
	for (ll i = 2; i <= n + 2; i++) {
		ll last = 0;
		for (ll x: vals[i - 1]) {
			if (last <= x - 1) {
				qv.push_back(make_pair(make_pair(x - 1, last), i));
			}
			last = x + 1;
		}
	}
			
	sort(qv.begin(), qv.end());
	
	for (ll i = 0; i < n; i++) last[i] = -1;
	st.init(n, last);
	
	// for (ll j = 0; j < n; j++) cout << st.query(j, j) << " ";
		// cout << endl;
	
	ll qp = 0;
	for (ll i = 0; i < n; i++) {
		st.update(a[i] - 1, i);
		
		// for (ll j = 0; j < n; j++) cout << st.query(j, j) << " ";
		// cout << endl;
		
		while (qp < qv.size() && qv[qp].f.f == i) {
			ll x = st.bs(0, 0, n - 1, qv[qp].f.s);
			// cout << i << " " << qv[qp] << " " << x << endl;
			
			pos[x + 1] = 1;
			
			++qp;
		}
	}
	
	ll ans = 2;
	while (pos[ans]) ++ans;
	
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