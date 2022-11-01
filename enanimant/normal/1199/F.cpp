// July 30, 2019
// https://codeforces.com/contest/1199/problem/F

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 51;


int n;
int psa[N][N];
int dp[N][N][N][N];

int sum(int r1, int c1, int r2, int c2) {
  return psa[r2 + 1][c2 + 1] - psa[r2 + 1][c1] - psa[r1][c2 + 1] + psa[r1][c1];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char c;
      cin >> c;
      psa[i][j] = psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1] + (c == '#');
    }
  }
  for (int h = 1; h <= n; h++) {
    for (int w = 1; w <= n; w++) {
      for (int r1 = 0; r1 + h <= n; r1++) {
        int r2 = r1 + h - 1;
        for (int c1 = 0; c1 + w <= n; c1++) {
          int c2 = c1 + w - 1;
          if (sum(r1, c1, r2, c2) == 0) {
            dp[r1][c1][r2][c2] = 0;
            continue;
          }
          int res = max(h, w);
          for (int k = r1; k < r2; k++) {
            res = min(res, dp[r1][c1][k][c2] + dp[k + 1][c1][r2][c2]);
          }
          for (int k = c1; k < c2; k++) {
            res = min(res, dp[r1][c1][r2][k] + dp[r1][k + 1][r2][c2]);
          }
          dp[r1][c1][r2][c2] = res;
        }
      }
    }
  }
  cout << dp[0][0][n - 1][n - 1] << '\n';


  return 0;
}