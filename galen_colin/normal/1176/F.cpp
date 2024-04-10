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
 
ll n, q, Q, T, m, k, l, r, x, y, z, g;
vl turns[200002][3];
ll dp[200001][11];
ll a[11];
 
int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("test.txt", "r", stdin);
  // freopen("case", "w", stdout);
  
  cin >> n;
  f0r(i, n) {
    cin >> k;
    f0r(j, k) {
      cin >> x >> y;
      turns[i + 1][--x].pb(y);
    }
    f0r(j, 3) { sort(all(turns[i + 1][j])); reverse(all(turns[i + 1][j])); }
  }
  f0r(i, n+1) f0r(j, 10) dp[i][j] = -1;
  f0r(j, 10) dp[0][j] = -1;
  dp[0][0] = 0;
  f1r(i, 1, n+1) {
    f0r(j, 10) a[j] = -1;
    f0r(j, 10) {
      if (dp[i - 1][j] != -1) {
        a[j] = max(a[j], dp[i - 1][j]);
        if (j + 1 > 9) {
          if (turns[i][0].size()) a[(j + 1) % 10] = max(a[(j + 1) % 10], dp[i - 1][j] + 2 * turns[i][0][0]);
          if (turns[i][1].size()) a[(j + 1) % 10] = max(a[(j + 1) % 10], dp[i - 1][j] + 2 * turns[i][1][0]);
          if (turns[i][2].size()) a[(j + 1) % 10] = max(a[(j + 1) % 10], dp[i - 1][j] + 2 * turns[i][2][0]);
        } else {
          if (turns[i][0].size()) a[(j + 1) % 10] = max(a[(j + 1) % 10], dp[i - 1][j] + turns[i][0][0]);
          if (turns[i][1].size()) a[(j + 1) % 10] = max(a[(j + 1) % 10], dp[i - 1][j] + turns[i][1][0]);
          if (turns[i][2].size()) a[(j + 1) % 10] = max(a[(j + 1) % 10], dp[i - 1][j] + turns[i][2][0]);
        }
        if (j + 2 > 9) {
          if (turns[i][0].size() > 1) a[(j + 2) % 10] = max(a[(j + 2) % 10], dp[i - 1][j] + 2 * turns[i][0][0] + turns[i][0][1]);
          if (turns[i][0].size() && turns[i][1].size()) a[(j + 2) % 10] = max(a[(j + 2) % 10], dp[i - 1][j] + 2 * max(turns[i][0][0], turns[i][1][0]) + min(turns[i][0][0], turns[i][1][0]));
        } else {
          if (turns[i][0].size() > 1) a[(j + 2) % 10] = max(a[(j + 2) % 10], dp[i - 1][j] + turns[i][0][0] + turns[i][0][1]);
          if (turns[i][0].size() && turns[i][1].size()) a[(j + 2) % 10] = max(a[(j + 2) % 10], dp[i - 1][j] + turns[i][0][0] + turns[i][1][0]);
        }
        if (j + 3 > 9) {
          if (turns[i][0].size() > 2) a[(j + 3) % 10] = max(a[(j + 3) % 10], dp[i - 1][j] + 2 * turns[i][0][0] + turns[i][0][1] + turns[i][0][2]);
        } else {
          if (turns[i][0].size() > 2) a[(j + 3) % 10] = max(a[(j + 3) % 10], dp[i - 1][j] + turns[i][0][0] + turns[i][0][1] + turns[i][0][2]);
        }
      }
    }
    // f0r(j, 10) cout << a[j] << " ";
    // cout << endl;
    f0r(j, 10) dp[i][j] = a[j];
  }

  ll ans = 0;
  f0r(i, 10) ans = max(dp[n][i], ans);
  cout << ans << endl;
}