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
#define io {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define mp make_pair
#define f first
#define s second
#define presum(p, a, n) {p[0] = a[0]; for (int i = 1; i < n; i++) p[i] = a[i] + p[i-1];}
#define all(v) v.begin(), v.end()
#define readgraph(list, edges) for (int i = 0; i < edges; i++) {int a, b; cin >> a >> b; a--; b--; list[a].pb(b); list[b].pb(a);}
#define ai(a, n) for (int ele = 0; ele < n; ele++) cin >> a[ele];
#define ain(a, lb, rb) for (int ele = lb; ele <= rb; ele++) cin >> a[ele];
#define ao(a, n) {for (int ele = 0; ele < n; ele++) { if (ele) cout << " "; cout << a[ele]; } cout << '\n';}
#define aout(a, lb, rb) {for (int ele = lb; ele <= rb; ele++) { if (ele > lb) cout << " "; cout << a[ele]; } cout << '\n';}
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
 
void usaco(string filename) {
  #pragma message("be careful, freopen may be wrong")
	freopen((filename + ".in").c_str(), "r", stdin);
	freopen((filename + ".out").c_str(), "w", stdout);
}
 
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
  return mpow(base, mod - 2);
}
ll mdiv(ll a, ll b) {
  return mmul(a, minv(b));
}
ll gcd(ll x, ll y) {
  if (x == 0) return y;
  if (y == 0) return x;
  return gcd(y, x % y);
}
 
// bool prime[1000006]; 
// void sieve(int n) { 
//   f0r(i, n + 1) prime[i] = 1;
//   for (int p = 2; p * p <= n; p++) { 
//     if (prime[p] == true) { 
//       for (int i = p * p; i <= n; i += p) 
//         prime[i] = false; 
//     } 
//   } 
//   prime[1] = prime[0] = 0;
// } 
 
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
	if (l > r) return 0;
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
 
struct min_t {
  long long val;
  static const long long null_v = 9223372036854775807LL;
 
  min_t(): val(0) {}
  min_t(long long v): val(v) {}
 
  min_t op(min_t& other) {
    return min_t(min(val, other.val));
  }
  
  min_t lazy_op(min_t v, int size) {
    return min_t(val + v.val);
  }
};
 
ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[500005];
ll b[500005];
ll c[500005];
string s, t;
ll ans = 0;
 
set<int> se, th;
segtree<sum_t> sst, tst;
segtree<min_t> part;
ll blank[500005];
 
int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");
  
  cin >> x >> y >> z;
  ai(a, x);
  ai(b, y);
  ai(c, z);
  f0r(i, x) a[i]--;
  f0r(i, y) b[i]--;
  f0r(i, z) c[i]--;
  sort(a, a+x);
  sort(b, b+y);
  sort(c, c+z);
  se = set<int>(b, b+y);
  th = set<int>(c, c+z);
 
  n = x + y + z;
  ans = n;
  ms(blank, 0);
  sst.init(n, blank);
  tst.init(n, blank);
  part.init(n + 1, blank);
  f0r(i, y) sst.update(b[i], b[i], 1);
  f0r(i, z) tst.update(c[i], c[i], 1);
  f0r(i, n + 1) {
    ll c1 = tst.query(0, i - 1).val;
    ll c2 = sst.query(i, n - 1).val;
 
    part.update(i, i, c1 + c2);
  }
 
  ll pt = 0;
  ll cnt = x;
 
  ll ub, lb;
  if (se.size()) ub = *(se.rbegin());
  else ub = -1;
  if (th.size()) lb = *(th.begin());
  else lb = n;
  // cout << ub << " " << lb << endl;
 
  if (ub < lb) {
  ans = min(ans, cnt);
} else {
  ans = min(ans, cnt + part.query(0, n).val);
}
 
 
  f0r(i, n) {
    // cout << i << " " << cnt << " " << ans << endl;
    if (pt < x && a[pt] == i) {
      pt++;
      cnt--;
    } else if (se.find(i) != se.end()) {
      cnt++;
      se.erase(i);
      part.update(0, i, -1);
    } else {
      cnt++;
      th.erase(i);
      part.update(i + 1, n, -1);
    }
 
    if (se.size()) ub = *(se.rbegin());
    else ub = -1;
    if (th.size()) lb = *(th.begin());
    else lb = n;
    // cout << ub << " " << lb << endl;
 
    if (ub < lb) {
      ans = min(ans, cnt);
    } else {
      ans = min(ans, cnt + part.query(0, n).val);
    }
  }
 
  cout << ans << endl;
}