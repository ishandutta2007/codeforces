#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int main()
{
  int N, A[100], B[100];
  int dp[20001][101];


  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for(int i = 0; i < N; i++) {
    cin >> B[i];
    B[i] -= A[i];
  }

  fill_n(*dp, 20001 * 101, INF);
  dp[10000 - A[0]][0] = A[0];
  dp[10000 + B[0]][1] = 0;

  for(int i = 1; i < N; i++) {
    for(int k = N - 1; k >= 0; k--) {
      for(int j = 0; j <= 20000; j++) {
        if(dp[j][k] == INF) continue;
        dp[j + B[i]][k + 1] = min(dp[j + B[i]][k + 1], dp[j][k]);
        dp[j - A[i]][k] = dp[j][k] + A[i];
        dp[j][k] = INF;
      }
    }
  }

  for(int j = 0; j <= N; j++) {
    int ret = INF;
    for(int k = 20000; k >= 10000; k--) ret = min(ret, dp[k][j]);
    if(ret != INF) {
      cout << j << " " << ret << endl;
      return (0);
    }
  }
}