#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 
 
using namespace std;
 
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
 
#define f0r(a, b) for (long long a = 0; a < b; a++)
#define f1r(a, b, c) for (long long a = b; a < c; a++)
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
 
const ll mod = 1e9 + 7;
 
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
 
ll n, q, Q, T, m, k, r, x, y, z, g;
pii songs[16];
ll dp[1 << 16][3];
bool vis[1 << 16][3];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("case", "w", stdout);
  
  cin >> n >> k; 
  ms(dp, 0);
  f0r(i, n) {cin >> songs[i].f >> songs[i].s; --songs[i].s;}
  queue<pii> q;
  f0r(i, n) q.push(mp((1 << i), songs[i].s));
  f0r(i, n) dp[1 << i][songs[i].s] = 1;
  ms(vis, 0);

  while (!q.empty()) {
    pii x = q.front();
    q.pop();
    if (vis[x.f][x.s]) continue;
    vis[x.f][x.s] = 1;
    f0r(i, n) {
      if ((x.f & (1 << i)) == 0 && songs[i].s != x.s) {
        q.push(mp(x.f | (1 << i), songs[i].s));
        dp[x.f | (1 << i)][songs[i].s] = (dp[x.f | (1 << i)][songs[i].s] + dp[x.f][x.s]) % mod;
      }
    }
  }

  ll ans = 0;
  f0r(i, (1 << n)) {
    int sum = 0;
    f0r(j, n) {
      if (i & (1 << j)) sum += songs[j].f;
    }
    if (sum == k) {
      f0r(j, 3) {
        ans = (ans + dp[i][j]) % mod;
      }
    }
    // f0r(j, 3) cout << dp[i][j] << " ";
    // cout << endl;
  }
  cout << ans << endl;
}