// July 28, 2019
// https://codeforces.com/contest/1195/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 100001;


int n;
int h[2][N];
long long dp[N][2];

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
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> h[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      dp[i][j] = dp[i - 1][j ^ 1];
      if (i - 2 >= 0) {
        dp[i][j] = max(dp[i][j], dp[i - 2][j ^ 1]);
      }
      dp[i][j] += h[j][i - 1];
    }
  }
  cout << max(dp[n][0], dp[n][1]) << '\n';


  return 0;
}