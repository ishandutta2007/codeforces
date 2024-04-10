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
template<typename A, typename B> ll max(A x, B y) {
  return x > y ? x : y;
}
template<typename A, typename B> ll min(A x, B y) {
  return x < y ? x : y;
}
 
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
 
ll i, j;
const ll mod = 1e9 + 7;
ll n, q, Q, T, m, k, r, x, y, z, g;
lld l, h;
ll a[200001], dp[2][200001], par[2][200001];
bool inc[200001];

int main() {
  io;
  // freopen("case", "w", stdout);
 
  cin >> n;
  f0r(i, n) cin >> a[i];
  f0r(i, n) dp[0][i] = -mod;
  dp[0][0] = mod;
  f0r(i, n) dp[1][i] = mod;
  dp[1][0] = -mod;
  f1r(i, 1, n) {
    if (a[i] > dp[1][i-1] && a[i-1] > dp[0][i]) {
      dp[0][i] = a[i-1];
      par[0][i] = 1;
    }
    if (a[i] < dp[0][i-1] && a[i-1] < dp[1][i]) {
      dp[1][i] = a[i-1];
      par[1][i] = 0;
    }
    if (a[i] > a[i-1] && dp[0][i] < dp[0][i-1]) {
      dp[0][i] = dp[0][i-1];
      par[0][i] = 0;
    }
    if (a[i] < a[i-1] && dp[1][i] > dp[1][i-1]) {
      dp[1][i] = dp[1][i-1];
      par[1][i] = 1;
    }
  }
  
  ms(inc, 0);
  if (dp[0][n-1] != -mod) {
    int x = 0;
    for (int i = n-1; i >= 0; i--) {
      inc[i] = !x;
      x = par[x][i];
    }
  } else if (dp[1][n-1] != mod) {
    int x = 1;
    for (int i = n-1; i >= 0; i--) {
      inc[i] = !x;
      x = par[x][i];
    }
  } else {
    cout << "NO" << endl;
    exit(0);
  }
  cout << "YES" << endl;
  f0r(i, n) cout << !inc[i] << " ";
}

/* things for speed 
  do we have fast i/o?
  set and pdbs are slow
*/