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
 
const ll mod = 998244353;
 
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
int val[1 << 10];
vpi c[1 << 10];
int b[100001];

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("case", "w", stdout);
  
  cin >> n >> m;
  f0r(i, n) {
    int x = 0;
    int a; cin >> a;
    f0r(j, a) {
      int y; cin >> y;
      x += 1 << (y - 1);
    }
    b[i] = x;
  }
  f0r(i, m) {
    int w, x, a; cin >> w >> a;
    x = 0;
    f0r(j, a) {
      int y; cin >> y;
      x += 1 << (y - 1);
    }
    c[x].pb(mp(w, (int)(i+1)));
  }
  f0r(i, (1 << 9) + 1) {
    sort(all(c[i]));
    int cnt = 0;
    f0r(j, n) {
      if ((i & b[j]) == b[j]) cnt++;
    }
    val[i] = cnt;
  }
  pii ans = mp(0, 0);
  int best = 2000000002, mx = 0;
  f0r(i, (1 << 9) + 1) {
    f0r(j, (1 << 9) + 1) {
      if (i == j) continue;
      if (!c[i].size() || !c[j].size()) continue;
      int cov = val[i | j];
      if (cov == mx) {
        if (c[i][0].f + c[j][0].f < best) {
          ans = mp(c[i][0].s, c[j][0].s);
          best = c[i][0].f + c[j][0].f;
        }
      } else if (cov > mx) {
        ans = mp(c[i][0].s, c[j][0].s);
        best = c[i][0].f + c[j][0].f;
        mx = cov;
      }
    }
  }
  f0r(i, (1 << 9) + 1) {
    if (c[i].size() > 1) {
      int cov = val[i];
      if (cov == mx) {
        if (c[i][0].f + c[i][1].f < best) {
          ans = mp(c[i][0].s, c[i][1].s);
          best = c[i][0].f + c[i][1].f;
        }
      } else if (cov > mx) {
        ans = mp(c[i][0].s, c[i][1].s);
        best = c[i][0].f + c[i][1].f;
        mx = cov;
      }
    }
  }
  cout << ans.f << " " << ans.s << endl;
}