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
      lazy[i * 2 + 1] = lazy[i].val + lazy[i * 2 + 1].val;
      lazy[i * 2 + 2] = lazy[i].val + lazy[i * 2 + 2].val;
    }
    /* end special part */

    lazy[i] = num_t();
  }
};

struct min_t {
  ll val;
  static const long long null_v = 9223372036854775807LL;

  min_t(): val(0) {}
  min_t(ll v): val(v) {}

  min_t op(min_t& other) {
    return min_t(min(val, other.val));
  }
  
  min_t lazy_op(min_t v, int size) {
    return min_t(val + v.val);
  }
};


ll i, j;
const ll mod = 1e9 + 7;
ll n, q, Q, T, m, k, r, x, y, z, g;
bool a[1000001]; // 0 - left, 1 - right
ll b[1000001];
int ans = 0;
segtree<min_t> st;

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("case", "w", stdout);
  
  cin >> n;
  int cl = 0, cr = 0;
  f0r(i, n) {
    char c; cin >> c;
    if (c == '(') {
      cl++;
      a[i] = 0;
    } else {
      cr++;
      a[i] = 1;
    }
  }

  /* change a left to right */
  if (cl - cr == 2) {
    /* do nothing lol */
  } else if (cr - cl == 2) { /* change a right to left */
    reverse(a, a+n);
    f0r(i, n) a[i] = !a[i];
  } else {
    cout << 0 << endl;
    exit(0);
  }

  /* now we change a left to right */

  /* make sure there aren't too many rights */
  int cnt[2];
  ms(cnt, 0);
  f0r(i, n) {
    cnt[a[i]]++;
    if (cnt[0] < cnt[1]) {
      cout << 0 << endl;
      exit(0);
    }
  }

  ms(cnt, 0);
  for (int i = n-1; i+1; i--) {
    cnt[a[i]]++;
    b[i] = cnt[1] - cnt[0];
  }

  st.init(n, b);

  f0r(i, n) {
    if (!a[i]) {
      st.update(0, i, 2);
      if (st.query(0, n-1).val >= 0) ans++;
      st.update(0, i, -2);
    }
  }

  cout << ans << endl;
}