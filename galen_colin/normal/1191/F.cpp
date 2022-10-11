#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 
 
using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define f0r(a, b) for (int a = 0; a < b; a++)
#define f1r(a, b, c) for (int a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) p[0] = a[0]; for (int i = 1; i < n; i++) p[i] = a[i] + p[i-1];
#define all(v) v.begin(), v.end()
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);};
typedef long long ll;
typedef double ld;
typedef long double lld;
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
 
ll gcd(ll x, ll y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}
 
// bool prime[1000001]; 
// void sieve(int n) { 
//   ms(prime, 1);
//   for (int p=2; p*p<=n; p++) { 
//     if (prime[p] == true) { 
//       for (int i=p*p; i<=n; i += p) 
//         prime[i] = false; 
//     } 
//   } 
// } 
 
// ll mpow(ll base, ll exp) {
//   ll res = 1;
//   while (exp) {
//     if (exp % 2 == 1){
//         res = (res * base) % mod;
//     }
//     exp >>= 1;
//     base = (base * base) % mod;
//   }
//   return res;
// }

// long long count(string s) {
//   long long ans = 0, c1 = 0, c2 = 0, c3 = 0;
//   for (int i = 0; i < s.length(); i++) {
//     if (s[i] == '1') c1++;
//     else if (s[i] == '3') {
//       c3 += c2;
//       c2 += c1;
//     }
//     else ans += c3;
//   }
//   return ans;
// }

/*
if (count(qqq) == x) {
      cout << "OK " << cnt++;
    } else {
      cout << "FAIL " << x << endl;
      exit(0);
    }
*/

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

  /* varies by implementation */
  /* this one is for range additions */
  void eval_lazy(int i, int l, int r) {
    /* special part */
    tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
    if (l != r) {
      lazy[i * 2 + 1] = max(lazy[i].val, lazy[i * 2 + 1].val);
      lazy[i * 2 + 2] = max(lazy[i].val, lazy[i * 2 + 2].val);
    }
    /* end special part */

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
  
  sum_t lazy_op(sum_t v, int size) {
    return sum_t(val + v.val * size);
  }
};

ll i, j;
const ll mod = 1e9 + 7;
ll n, q, Q, T, m, k, r, y, z, g;
pii x[200001];
int comp[200001];
ll a[200001];
segtree<sum_t> st;
vi levels[200001];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("case", "w", stdout);
  
  cin >> n;
  f0r(i, n) cin >> x[i].f >> x[i].s;
  sort(x, x+n);
  int cnt = 1;
  comp[0] = 1;
  f1r(i, 1, n) {
    if (x[i].f == x[i-1].f) comp[i] = cnt;
    else comp[i] = ++cnt;
  }
  f0r(i, n) x[i].f = comp[i];

  f0r(i, n) {swap(x[i].f, x[i].s); x[i].f = -x[i].f;}
  sort(x, x+n);
  cnt = 0;
  comp[0] = 0;
  f1r(i, 1, n) {
    if (x[i].f == x[i-1].f) comp[i] = cnt;
    else comp[i] = ++cnt;
  }
  f0r(i, n) x[i].f = comp[i];
  f0r(i, n) swap(x[i].f, x[i].s);

  /* end compression */
  ms(a, 0);
  st.init(n+1, a);
  f0r(i, n) levels[i].pb(0);
  f0r(i, n) levels[x[i].s].pb(x[i].f);
  ll l = x[n-1].s;
  ll ans = 0;
  st.update(0, 0, 1);
  f0r(i, l+1) {
    f1r(j, 1, levels[i].size()) {
      st.update(levels[i][j], levels[i][j], 1 - st.query(levels[i][j], levels[i][j]).val);
    }
    f1r(j, 1, levels[i].size()) {
      ans += (st.query(levels[i][j-1], levels[i][j]).val - 1) * (st.query(levels[i][j], n).val);
    }
  }
  cout << ans << endl;
}