#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
 
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
#define f0rd(a, b) for (long long a = b; a >= 0; a--)
#define f1rd(a, b, c) for (long long a = b; a >= c; a--)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) p[0] = a[0]; for (int i = 1; i < n; i++) p[i] = a[i] + p[i-1];
#define all(v) v.begin(), v.end()
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);};
#define aout(a, lb, rb) for (int i = lb; i <= rb; i++) { if (i > lb) cout << " "; cout << a[lb]; } cout << endl;
typedef long long ll;
typedef double ld;
typedef long double lld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
 
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
// template<typename A, typename B> ll max(A x, B y) {
//   return x > y ? x : y;
// }
// template<typename A, typename B> ll min(A x, B y) {
//   return x < y ? x : y;
// }
 
mt19937 rng(steady_clock::now().time_since_epoch().count());
/* usage - just do rng() */
 
const ll mod = 998244353;
 
ll madd(ll a, ll b) {
  return (a + b) % mod;
}
ll msub(ll a, ll b) {
  return (((a - b) % mod) + mod) % mod;
}
ll mmul(ll a, ll b) {
  return ((a % mod) * (b % mod)) % mod;
}
ll mpow(ll base, ll exp) {
  ll res = 1;
  while (exp) {
    if (exp % 2 == 1){
        res = (res * base) % mod;
    }
    exp >>= 1;
    base = (base * base) % mod;
  }
  return res;
}
ll minv(ll base) {
  return mpow(base, mod - 1);
}
ll mdiv(ll a, ll b) {
  return mmul(a, minv(b));
}
ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
 
bool prime[10000006]; 
void sieve(int n) { 
  f0r(i, n + 1) prime[i] = 1;
  for (int p = 2; p * p <= n; p++) { 
    if (prime[p] == true) { 
      for (int i = p * p; i <= n; i += p) 
        prime[i] = false; 
    } 
  } 
  prime[1] = prime[0] = 0;
} 

template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, vector<ll>& arr) {
    n = s;
    tree = vector<num_t>(4 * s, 0);
    lazy = vector<num_t>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, vector<ll>& arr) {
    if (l == r) return tree[i] = arr[l];

    int mid = (l + r) / 2;
    num_t a = init(2 * i + 1, l, mid, arr),
          b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = a.op(b);
  }

  void update(int l, int r, num_t v) {
    update(0, 0, n - 1, l, r, v);
  }

  num_t update(int i, int tl, int tr, int ql, int qr, num_t v) {
    eval_lazy(i, tl, tr);

    if (ql <= tl && tr <= qr) {
      lazy[i] = lazy[i].val + v.val;
      eval_lazy(i, tl, tr);
      return tree[i];
    }
    if (tl > tr || tr < ql || qr < tl) return tree[i];
    if (tl == tr) return tree[i];

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
  
  max_t lazy_op(max_t v, int size) {
    return max_t(val + v.val);
  }
};
ll n, q, Q, T, k, l, r, x, y, z, g, w;
vl a[1000001];
ll mx[1000001];
ll ans[1000001];
int pt[1000001];
segtree<max_t> st[1000001];
ll sumx = 0;

bool comp(int x, int y) {
	return a[x].size() < a[y].size();
}

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  
  cin >> n >> w;
  ms(mx, 0);
  f0r(i, n) {
    int sz; cin >> sz;
    f0r(j, sz) {
      ll x; cin >> x;
      mx[i] = max(mx[i], x);
      a[i].pb(x);
    }
	mx[i] = max(mx[i], 0LL);
  }
  f0r(i, n) sumx += mx[i];
  f0r(i, w) ans[i] = sumx;
  f0r(i, n) pt[i] = i;
  sort(pt, pt + n, comp);
  reverse(pt, pt + n);
	f0r(i, n) st[i].init(a[pt[i]].size(), a[pt[i]]);
	f0r(i, w) {
		f0r(j, n) {
			if ((a[pt[j]].size() <= i + 1 && a[pt[j]].size() <= w - i) && !(i <= a[pt[j]].size() - 1 && i >= w - a[pt[j]].size())) break;
			ans[i] -= mx[pt[j]];
			int r = min(i, (ll)a[pt[j]].size() - 1LL);
			int l;
			if (i <= w - a[pt[j]].size()) l = 0;
			else l = i - (w - a[pt[j]].size());
			ll x = st[j].query(l, r).val;
			if (x < 0) {
				ll y = w - a[pt[j]].size();
				if (!(i <= a[pt[j]].size() - 1 && i >= w - a[pt[j]].size())) x = 0;
			}
			ans[i] += x;
			// cout << i << " " << j << " " << l << " " << r << endl;
		}
	}
	f0r(i, w) {
		if (i) cout << " ";
		cout << ans[i];
	} 
	cout << endl;
}