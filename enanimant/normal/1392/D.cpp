// August 16, 2020
// 

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 200010;

int dp[N][2][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      char c;
      cin >> c;
      a[i] = (c == 'R');
    }
    int ans = n;
    for (int rot = 0; rot < 2; rot++) {
      for (int b0 = 0; b0 < 2; b0++) {
        int b1 = (b0 ^ 1);
        int x = 0;
        auto b = a;
        if (b[0] != b0) {
          b[0] ^= 1;
          x++;
        }
        if (b[1] != b1) {
          b[1] ^= 1;
          x++;
        }
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
              dp[i][j][k] = n;
            }
          }
        }
        dp[1][b0][b1] = x;
        for (int i = 2; i < n; i++) {
          for (int c1 = 0; c1 < 2; c1++) {
            for (int c2 = 0; c2 < 2; c2++) {
              for (int c0 = 0; c0 < 2; c0++) {
                if (c0 == c1 && c1 == c2) {
                  continue;
                }
                dp[i][c1][c2] = min(dp[i][c1][c2], dp[i - 1][c0][c1] + (b[i] != c2));
              }
            }
          }
        }
        int res = min({dp[n - 1][b0][b1], dp[n - 1][b1][b0], dp[n - 1][b1][b1]});
        ans = min(ans, res);
      }
      rotate(a.begin(), a.begin() + 1, a.end());
    }
    cout << ans << '\n';
  }
  
  
  return 0;
}