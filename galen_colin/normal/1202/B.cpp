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
ll mat[11][11];
bool vis[11];
char dp[11][11][11][11];

void fill(int a, int b, int c, int d) {
  // cout << a << " " << b << " " << c << " " << d << endl;
  queue<pii> q;
  q.push(mp(d, 1));
  while(!q.empty()) {
    pii x = q.front();
    q.pop();
    if (vis[x.f]) continue;
    vis[x.f] = 1;
    dp[a][b][c][x.f] = min(dp[a][b][c][x.f], (char)x.s);

    q.push(mp((x.f+a)%10, dp[a][b][c][x.f]+1));
    q.push(mp((x.f+b)%10, dp[a][b][c][x.f]+1));
  }
}

int main() {
  io;
  // freopen("case", "r", stdin);
  // freopen("case", "w", stdout);
  f0r(a, 10) {
    f0r(b, 10) {
      f0r(c, 10) {
        f0r(d, 10) dp[a][b][c][d] = 100;
      }
      f0r(c, 10) {
        ms(vis, 0);
        fill(a, b, c, (c+a)%10);
        ms(vis, 0);
        fill(a, b, c, (c+b)%10);
      }
      // x = 0;
      // f0r(c, 10) {
      //   dp[a][b][x][(x + a)%10] = 1;
      //   x = (x+a)%10;
      // }
      // x = 0;
      // f0r(c, 10) {
      //   dp[a][b][x][(x + b)%10] = 1;
      //   x = (x+b)%10;
      // }
      // f0r(c, 10) {
      //   x = c;
      //   int lv;
      //   f0r(d, 10) {
      //     lv = dp[a][b][x][(x + a)%10] = min(dp[a][b][x][(x + a)%10], lv + 1);
      //     x = (x+a)%10;
      //   }
      //   x = c;
      //   f0r(d, 10) {
      //     lv = dp[a][b][x][(x + b)%10] = min(dp[a][b][x][(x + b)%10], lv + 1);
      //     x = (x+b)%10;
      //   }
      // }
      // f0r(c, 10) {
      //   f0r(d, 10) fill(a, b, c, d);
      // }
    }
  }

  // f0r(i, 10) {
  //   f0r(j, 10) {
  //     cout << (int)dp[2][3][i][j] << " ";
  //   }
  //   cout << endl;
  // }
  
  cin >> s;
  n = s.length();
  ms(mat, 0);
  f0r(i, 10) {
    f1r(j, i, 10) {
      ll cnt = 0;
      bool f = 1;
      f0r(k, n-1) {
        x = s[k] - '0';
        y = s[k+1] - '0';
        cnt += (int)dp[i][j][x][y] - 1;
        if (dp[i][j][x][y] == 100) {
          f = 0;
          break;
        }
      }
      mat[i][j] = (f ? cnt : -1);
    }
  }

  f0r(i, 10) {
    f0r(j, i) mat[i][j] = mat[j][i];
  }
  f0r(i, 10) {
    f0r(j, 10) cout << mat[i][j] << " ";
    cout << endl;
  }
}