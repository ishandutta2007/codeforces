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
 
ll i, j;
const ll mod = 1e9 + 7;
ll n, q, Q, T, m, k, r, x, y, z, g;
ll a[400001], b[400001];
string s;
ll bd[4]; //l, r, d, u
bool f[4];
vi loc[4];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("case", "w", stdout);
  
  cin >> Q;
  f0r(q, Q) {
    cin >> s;
    pll pos = {0, 0};
    n = s.length();
    bd[0] = 0;
    bd[1] = 0;
    bd[2] = 0;
    bd[3] = 0;
    f0r(i, n) {
      if (s[i] == 'W') pos.s++;
      else if (s[i] == 'A') pos.f--;
      else if (s[i] == 'D') pos.f++;
      else pos.s--;
      bd[0] = min(bd[0], pos.f);
      bd[1] = max(bd[1], pos.f);
      bd[2] = min(bd[2], pos.s);
      bd[3] = max(bd[3], pos.s);
    }
    pos = {0, 0};
    f0r(i, 4) loc[i].clear();
    if (pos.f == bd[0]) {
      loc[0].pb(i);
    }
    if (pos.f == bd[1]) {
      loc[1].pb(i);
    }
    if (pos.s == bd[2]) {
      loc[2].pb(i);
    }
    if (pos.s == bd[3]) {
      loc[3].pb(i);
    }
    f0r(i, n) {
      if (s[i] == 'W') pos.s++;
      else if (s[i] == 'A') pos.f--;
      else if (s[i] == 'D') pos.f++;
      else pos.s--;
      if (pos.f == bd[0]) {
        loc[0].pb(i);
      }
      if (pos.f == bd[1]) {
        loc[1].pb(i);
      }
      if (pos.s == bd[2]) {
        loc[2].pb(i);
      }
      if (pos.s == bd[3]) {
        loc[3].pb(i);
      }
    }
    ms(f, 0);
    if (loc[0][0] > loc[1][loc[1].size() - 1]) f[0] = 1;
    if (loc[1][0] > loc[0][loc[0].size() - 1]) f[1] = 1;
    if (loc[2][0] > loc[3][loc[3].size() - 1]) f[2] = 1;
    if (loc[3][0] > loc[2][loc[2].size() - 1]) f[3] = 1;

    // f0r(i, 4) cout << bd[i] << " " << loc[i].size() << " " << f[i] << endl;

    x = (bd[1] - bd[0] + 1);
    y = (bd[3] - bd[2] + 1);
    ll ans = x*y;
    if (x > 2 && (f[0] || f[1])) ans = min(ans, (x-1)*y);
    if (y > 2 && (f[2] || f[3])) ans = min(ans, x*(y-1));
    cout << ans << endl;
  }
}