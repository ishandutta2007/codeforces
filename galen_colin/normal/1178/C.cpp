#include <bits/stdc++.h>
#include <chrono> 
using namespace std::chrono; 

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
#define io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mp make_pair
#define f first
#define s second
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
ll i, j;
const ll mod = 998244353  ;

ll n, q, Q, T, m, k, r, x, y, z, g, a, b;
ll dp[1001][1001][4]; //white - 0 tl, 1 tr, 2 br, 3 bl
bool tleft[4][4] = {
  {1, 0, 0, 1},
  {0, 1, 1, 0},
  {0, 1, 1, 0},
  {1, 0, 0, 1}
};
bool tup[4][4] = {
  {1, 1, 0, 0},
  {1, 1, 0, 0},
  {0, 0, 1, 1},
  {0, 0, 1, 1}
};

ll mpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp % 2 == 1){
           res = (res * base) % mod;
        }
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return res;
}

int main() {
  io;
  cin >> n >> m;
  cout << mpow(2, n+m) % mod << endl;
  // ms(dp, 0);
  // f0r(i, 4) dp[0][0][i] = 1;
  // f0r(i, n) {
  //   f0r(j, m) {
  //     if (i == 0 && j == 0) continue;
  //     f0r(k, 4) {
  //       if (i == 0) {
  //         f0r(x, 4) dp[i][j][k] += (tleft[x][k] ? dp[i][j-1][x] : 0);
  //       } else if (j == 0) {
  //         f0r(x, 4) dp[i][j][k] += (tup[x][k] ? dp[i-1][j][x] : 0);
  //       } else {
  //         f0r(a, 4) f0r(b, 4) {
  //           if (tleft[a][k] && tup[b][k]) {
  //             dp[i][j][k] = (dp[i][j][k] + (dp[i-1][j][b] * dp[i][j-1][a]) % mod) % mod;
  //           }
  //         }
  //       }
  //     }
  //   }
  // }
  // f0r(i, n) {
  //   f0r(j, m) cout << dp[i][j][1] << " ";
  //   cout << endl;
  // }
  // cout << (dp[n-1][m-1][0] + dp[n-1][m-1][1] + dp[n-1][m-1][2] + dp[n-1][m-1][3]) % mod << endl;
}