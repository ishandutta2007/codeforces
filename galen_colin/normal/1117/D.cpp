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
 
const ll mod = 1000000007;
 
namespace modop {
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
}
 
using namespace modop;
 
struct matrix {
  using TYPE = ll;
  int n;
  vector<vector<TYPE>> v;
 
  void init(int s) {
    n = s;
    v = vector<vector<TYPE> >(n, vector<TYPE>(n, 0));
  }
 
  matrix mul(matrix &b) {
    matrix res;
    res.init(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          res.v[i][j] = (res.v[i][j] + v[i][k] * b.v[k][j]) % mod;
        }
      }
    }
    return res;
  }
 
  matrix pow(matrix &a, ll x) {
    matrix res, b = a;
    res.init(n);
    for (int i = 0; i < n; i++) res.v[i][i] = 1;
 
    while (x) {
      if (x & 1) {
        res = res.mul(b);
      }
      x /= 2;
      b = b.mul(b);
    }
    return res;
  }  
  #pragma message("be careful with mod in matrix")
} base;
 
 
ll n, m, k, q, Q, T, l, r, x, y, z;
ll a[1000005];
ll b[1000005];
ll c[1000005];
string s, t;
ll ans = 0;
 
matrix ma;
 
int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  // freopen("file.in", "r", stdin);
 
  // usaco("file");
  
  cin >> n >> m;
 
  if (n < m) {
    cout << 1 << endl;
    exit(0);
  }
 
  ma.init(m);
 
  f1r(i, 1, m) ma.v[i][i - 1] = 1;
  ma.v[0][0] = 1;
  ma.v[0][m - 1] = 1;
 
  ma = ma.pow(ma, n - m + 1);
 
  f0r(i, m) ans = madd(ans, ma.v[0][i]);
  cout << ans << endl;
 
  /* dp sol - dp[i] = dp[i - 1] + dp[i - m]; */
  // ll dp[100];
  // ms(dp, 0);
  // f0r(i, n) {
  //   if (i == 0) dp[i] = 1;
  //   else {
  //     if (i == m - 1) ++dp[i];
  //     dp[i] += dp[i - 1];
  //     if (i > m - 1) dp[i] += dp[i - m];
  //   }
  // }
 
  // ao(dp, n);
}