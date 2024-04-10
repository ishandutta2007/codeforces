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
char dp[51][51][51][51];
bool mat[51][51];
int pre[52][52];

#define at dp[ax][bx][ay][by]
char get(char ax, char bx, char ay, char by) {
  if (at != -1) return at;
  if (pre[bx+1][by+1] + pre[ax][ay] - pre[bx+1][ay] - pre[ax][by+1] == 0) return at = 0;

  at = max(bx - ax + 1, by - ay + 1);
  for (int x = ax; x < bx; x++) {
    at = min(at, get(ax, x, ay, by) + get(x + 1, bx, ay, by));
  }
  for (int y = ay; y < by; y++) {
    at = min(at, get(ax, bx, ay, y) + get(ax, bx, y + 1, by));
  }
  return at;
}

int main() {
  io;
  // freopen("test.txt", "r", stdin);
 
  cin >> n;
  ms(pre, 0);
  f1r(i, 1, n+1) {
    string s; cin >> s;
    f1r(j, 1, n+1) {
      mat[i][j] = (s[j-1] == '#' ? 1 : 0);
      pre[i][j] = pre[i][j-1] + mat[i][j];
    }
  }
  f1r(i, 1, n+1) {
    f1r(j, 1, n+1) {
      pre[i][j] += pre[i-1][j];
      // cout << pre[i][j] << " ";
    }
    // cout << endl;
  }
  f0r(i, n) f0r(j, n) f0r(k, n) f0r(l, n) dp[i][j][k][l] = -1;

  cout << (int)get(0, n-1, 0, n-1) << endl;
}

/* things for speed 
  do we have fast i/o?
  set and pdbs are slow
*/