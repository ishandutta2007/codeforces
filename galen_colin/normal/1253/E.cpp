#include <bits/stdc++.h>
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
// #pragma optimization_level 3
// #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
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
#define getunique(v) {sort(all(v)); v.erase(unique(all(v)), v.end());}
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
 
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
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
 
const ll mod = 1e9 + 7;
 
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
 
bool isprime(ll n) { 
  if (n <= 1) return false; 
  if (n <= 3) return true; 
  
  if (n % 2 == 0 || n % 3 == 0) return false; 
  
  for (ll i = 5; i * i <= n; i += 6) 
    if (n % i == 0 || n % (i+2) == 0) 
      return false; 
  
  return true; 
} 
 
bool prime[1000006]; 
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
 
vi primelist;
 
void genprimes(int n) {
  sieve(n + 1);
  f1r(i, 2, n + 1) if (prime[i]) primelist.pb(i);
}
 
vi factors(ll n) {
  vi facs;
 
  if (isprime(n)) {
    facs.pb(n);
    return facs;
  }
  for (int i = 0; primelist[i] * primelist[i] <= n; i++) {
    if (n % primelist[i] == 0) {
      while (n % primelist[i] == 0) {
        n /= primelist[i];
        facs.pb(primelist[i]);
      }
      if (isprime(n)) {
        facs.pb(n);
        return facs;
      }
    }
  }
  if (n > 1) {
    facs.pb(n);
  }
  return facs;
}
 
struct segtree {
  int n, depth;
  vector<int> tree;
 
  void init(int s, long long* arr) {
    n = s;
    tree = vector<int>(4 * s, 0);
    init(0, 0, n - 1, arr);
  }
 
  int init(int i, int l, int r, long long* arr) {
    if (l == r) return tree[i] = arr[l];
 
    int mid = (l + r) / 2;
    int a = init(2 * i + 1, l, mid, arr),
        b = init(2 * i + 2, mid + 1, r, arr);
    return tree[i] = min(a, b);
  }
 
  void update(int l, int v) {
    update(0, 0, n - 1, l, v);
  }
 
  int update(int i, int tl, int tr, int q, int v) {
    if (tl > tr || tr < q || q < tl) return tree[i];
    if (tl == tr) {
      return tree[i] = v;
    }
 
    int mid = (tl + tr) / 2;
    int a = update(2 * i + 1, tl, mid, q, v),
        b = update(2 * i + 2, mid + 1, tr, q, v);
    return tree[i] = min(a, b);
  }
 
  int query(int l, int r) {
	  if (l > r) return 0;
    return query(0, 0, n-1, l, r);
  }
 
  int query(int i, int tl, int tr, int ql, int qr) {    
    if (ql <= tl && tr <= qr) return tree[i];
    if (tl > tr || tr < ql || qr < tl) return mod;
 
    int mid = (tl + tr) / 2;
    int a = query(2 * i + 1, tl, mid, ql, qr),
        b = query(2 * i + 2, mid + 1, tr, ql, qr);
    return min(a, b);
  }
};
 
ll n, m, k, q, Q, T, l, r, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;
 
pll x[83];
int values[100005];
 
vpi intervals;
 
segtree dp;
 
int getcst(int i) {
  if (i < 0) return 0;
  return values[i];
}
 
int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");
 
  cin >> n >> m;
  f0r(i, n) cin >> x[i].f >> x[i].s;
  f0r(i, n) intervals.pb(mp(x[i].f - x[i].s - 1, x[i].f + x[i].s - 1));
  sort(all(intervals));
  // int minv = m;
  // f0r(i, n) minv = min(minv, intervals[i].s);
  ans = m;
  f0r(iter, 2) {
    f0r(i, m) c[i] = mod;
    dp.init(m, c);
 
    f0r(i, m) values[i] = mod;
    f0r(i, m) {
      int dpv = min(getcst(i - 1), dp.query(i, m - 1));
      f0r(j, n) {
        int l = intervals[j].f, r = intervals[j].s;
        if (r < i) continue;
 
        int fill = max(0LL, l - i);
        r += fill;
        r = min(m - 1, (ll)r);
 
        // cout << i << " " << j << " " << l << " " << r << endl;
 
        int cst = dpv + fill;
        if (cst < values[r]) {
          values[r] = cst;
          dp.update(r, values[r]);
        }
      }
    }
 
    // f0r(i, m) cout << i << " " << values[i] << " " << dp.query(i, i) << endl;
    
    f0r(i, n) {
      int l = intervals[i].f, r = intervals[i].s;
      ll fill = max(0LL, m - 1 - r);
      l -= fill;
 
      l = max(l, 0);
 
      ll dpv = min(getcst(l - 1), dp.query(l, m - 1));
      // cout << i << " " << dpv << " " << l << " " << r << " " << fill << endl;
 
      ans = min(ans, dpv + fill);
    }
    ans = min(ans, (ll)values[m - 1]);
 
    f0r(i, n) {
      intervals[i].f = m - intervals[i].f - 1;
      intervals[i].s = m - intervals[i].s - 1;
      swap(intervals[i].f, intervals[i].s);
    }
  }
  
 
  cout << ans << endl;
}