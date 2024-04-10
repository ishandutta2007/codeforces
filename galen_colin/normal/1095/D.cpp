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

ll i, j;
const ll mod = 1e9 + 7;
ll n, q, Q, T, m, k, r, x, y, z, g;
vpi a;
int ans[200001];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("case", "w", stdout);
  
  cin >> n;
  f0r(i, n) {
    pii x;
    cin >> x.f >> x.s;
    x.f--;
    x.s--;
    a.pb(x);
  }
  ms(ans, 0);
  f0r(i, n-2) {
    int x = a[ans[i]].f, y = a[ans[i]].s;
    if (a[x].f == y || a[x].s == y) {
      ans[i+1] = x;
      ans[i+2] = y;
    } else {
      ans[i+1] = y;
      ans[i+2] = x;
    }
  }
  /* array length is even - one number left */
  if (n % 2 == 0) {
    int x = a[ans[n-2]].f, y = a[ans[n-2]].s;
    if (x == 0) ans[n-1] = y;
    else ans[n-1] = x;
  }
  f0r(i, n) cout << ans[i]+1 << " ";
}