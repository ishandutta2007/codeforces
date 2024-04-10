#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 
 
using namespace std;
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
#define edge(list) int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {edge(list)};
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

template <typename num_t> 
struct segtree {
  int n, depth;
  vector<num_t> tree, lazy;

  void init(int s, int* arr) {
    n = s;
    tree = vector<num_t>(5 * s, 0);
    lazy = vector<num_t>(5 * s, 0);
    init(0, 0, n - 1, arr);
  }

  num_t init(int i, int l, int r, int* arr) {
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

struct max_t {
  int val;
  static const int null_v = -1123372030;

  max_t(): val(0) {}
  max_t(int v): val(v) {}

  max_t op(max_t& other) {
    return max_t(max(val, other.val));
  }
  
  max_t lazy_op(max_t v, int size) {
    return max_t(val + v.val);
  }
};


ll i, j;
const ll mod = 1e9 + 7;
ll n, q, Q, T, m, k, r, x, y, z, g;
lld l, h;

string s1, s2;
int a[200001];
pii chg[200001];
int aall[200001];
vpi all;
segtree<max_t> st;

int bins(int i) {
  int l = 0, r = all.size() - 1;
  while (l <= r) {
    int m = (l + r) / 2;
    if (i < all[m].f) r = m - 1;
    else l = m + 1;
  }
  return l;
}

int main() {
  // freopen("case", "w", stdout);

  cin >> n;
  f0r(i, n) {
    int x; cin >> x;
    chg[i] = mp(x, -1);
  }
  cin >> Q;
  f0r(q, Q) {
    int p; cin >> p;
    if (p == 1) {
      int a, b; cin >> a >> b;
      --a;
      chg[a] = mp(b, q);
    } else {
      int a; cin >> a;
      all.pb(mp(q, a));
    }
  }
  if (all.size() == 0) {
    f0r(i, n) cout << chg[i].f << " ";
    exit(0);
  }
  f0r(i, all.size()) aall[i] = all[i].s;
  st.init(all.size(), aall);
  f0r(i, n) {
    a[i] = chg[i].f;
    int ind = bins(chg[i].s);
    // cout << chg[i].s << " " << ind << " ";
    int v;
    if (ind < all.size()) v = st.query(ind, all.size()-1).val;
    else v = 0;
    a[i] = max(a[i], v);
    cout << a[i] << " ";
    // cout << endl;
  }
}