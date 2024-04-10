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

struct segtree {
  int n, depth;
  vector<ll> tree, lazy;

  void init(int s, long long* arr) {
    n = s;
    tree = vector<ll>(4 * s, 0);
    lazy = vector<ll>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  ll init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    ll a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a > b ? a : b;
  }

  void update(int l, int r, ll v) {
    update(0, 0, n - 1, l, r, v);
  }

  ll update(int i, int tl, int tr, int ql, int qr, ll v) {
    eval_lazy(i, tl, tr);
	
	if (tr < ql || qr < tl) return tree[i];
    if (ql <= tl && tr <= qr) {
      lazy[i] += v;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    
    int mid = (tl + tr) / 2;
    ll a = update(2 * i + 1, tl, mid, ql, qr, v),
          b = update(2 * i + 2, mid + 1, tr, ql, qr, v);
    return tree[i] = a > b ? a : b;
  }

  ll query(int l, int r) {
    return query(0, 0, n-1, l, r);
  }

  ll query(int i, int tl, int tr, int ql, int qr) {
    eval_lazy(i, tl, tr);
    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tr < ql || qr < tl) return 1e13;

    int mid = (tl + tr) / 2;
    ll a = query(2 * i + 1, tl, mid, ql, qr),
          b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return a > b ? a : b;
  }

  void eval_lazy(int i, int l, int r) {
    tree[i] += lazy[i];
    if (l != r) {
      lazy[i * 2 + 1] += lazy[i];
      lazy[i * 2 + 2] += lazy[i];
    }

    lazy[i] = 0;
  }
};
 
ll n, m, q, k, l, r, x, y, z;
const ll template_array_size = 1e6 + 16318;
ll a[template_array_size];
ll b[template_array_size];
ll c[template_array_size];
string s, t;
ll ans = 0;

vector<ll> edges[500005];
vector<ll> ch[500005];
ll val[500005];
ll val2[500005];
ll vl[500005];
ll dep[500005];
bool can[500005];
segtree st;

bool cval(ll a, ll b) {
	if (val[a] == val[b]) return dep[a] < dep[b]; // was supposed to use this, but passed just by comparing indices?
	return val[a] > val[b];
}

void setv(ll v, ll p, ll va, ll d = 0) {
	val[v] = va;
	dep[v] = d;
	
	for (ll x: edges[v]) {
		if (x != p) {
			ch[v].push_back(x);
			setv(x, v, min(va, a[x]), d + 1);
		}
	}
}

void add(ll val, ll x) {
	ll lv = 0, rv = k;
	while (lv < rv) {
		ll mv = (lv + rv) / 2;
		
		if (b[mv] > val) lv = mv + 1;
		else rv = mv;
	}
		
	if (lv < k) st.update(lv, k - 1, x);
}

vector<ll> cur;
ll tsz = 0;

void checkv(ll v, ll va) {
	val2[v] = va;
	cur.push_back(v);
	
	for (ll x: ch[v]) {
		checkv(x, min(va, a[x]));
	}
}

bool check(ll v, ll t) {
	cur.clear();
	
	checkv(v, t);
	
	tsz += cur.size();
		
	for (ll x: cur) {
		add(val[x], 1);
		add(val2[x], -1);
	}

	bool pos = (st.query(0, k - 1) <= 0);
	
	for (ll x: cur) {
		add(val2[x], 1);
		add(val[x], -1);
	}
	
	return pos;
}

void solve(int tc = 0) {
	cin >> n;
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	for (ll i = 0; i < n - 1; i++) {
		cin >> x >> y;
		--x; --y;
		
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	setv(0, -1, a[0]);
		
	cin >> k;
	for (ll i = 0; i < k; i++) cin >> b[i];
	sort(b, b + k);
	reverse(b, b + k);
	
	iota(c, c + k, 1);
	st.init(k, c);
		
	for (ll i = 0; i < n; i++) add(val[i], -1);
		
	iota(vl, vl + n, 0);
	sort(vl, vl + n, cval);
	
	ll sent = 1e17;
	ll ans = sent;
	
	can[0] = 1;
		
	bool pos = 1;
	for (ll i = 0; i < k; i++) {
		ll x = vl[i];
		if (val[x] >= b[i]) {
			for (ll y: ch[x]) can[y] = 1;
			can[x] = 0;
		} else {
			pos = 0;
			
			for (ll j = 0; j < n; j++) {
				if (can[j]) {
					if (check(j, b[i])) {
						ans = min(ans, b[i] - val[j]);
					}
				}
			}
			
			break;
		}
	}
		
	if (pos) ans = 0;
	if (ans == sent) ans = -1;
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