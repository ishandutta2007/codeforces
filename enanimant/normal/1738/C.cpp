/*
 * author:  ADMathNoob
 * created: 09/30/22 10:35:12
 * problem: https://codeforces.com/contest/1738/problem/C
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../.cp/algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

const int N = 105;

bool dp[N][N][2][2]; // # 0s, # 1s, Alice's sum, turn -> can Alice force a win?

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int p : {0, 1}) {
        if (i == 0 && j == 0) {
          for (int t : {0, 1}) {
            dp[i][j][p][t] = (p == 0);
          }
          continue;
        }
        if (i == 0) {
          dp[i][j][p][0] = dp[i][j - 1][p ^ 1][1];
          dp[i][j][p][1] = dp[i][j - 1][p][0];
          continue;
        }
        if (j == 0) {
          for (int t : {0, 1}) {
            dp[i][j][p][t] = (p == 0);
          }
          continue;
        }
        {
          // t == 0 (Alice's turn)
          dp[i][j][p][0] = dp[i - 1][j][p][1] || dp[i][j - 1][p ^ 1][1];
        }
        {
          // t == 1 (Bob's turn)
          dp[i][j][p][1] = dp[i - 1][j][p][0] && dp[i][j - 1][p][0];
        }
      }
    }
  }
  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int k0 = 0, k1 = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a % 2 == 0) k0 += 1;
      else k1 += 1;
    }
    cout << (dp[k0][k1][0][0] ? "Alice" : "Bob") << '\n';
  }
  return 0;
}