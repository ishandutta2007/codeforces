#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int N, A[300000];
int dp[300001][21];

int main()
{
  scanf("%d", &N);
  for(int i = 0; i < N; i++) scanf("%d", &A[i]);

  fill_n(*dp, 21 * 300001, INF);
  dp[0][0] = 0;
  for(int i = 0; i < N; i++) {
    A[i] /= 100;
    for(int k = 20; k >= 0; k--) { // bounus rest
      if(dp[i][k] == INF) continue;
      for(int j = 0; j <= min(A[i], k); j++) { // bounus use
        int latte = min(20, (k - j) + (A[i] - j)/10);
        dp[i + 1][latte] = min(dp[i + 1][latte], dp[i][k] + (A[i] - j) * 100);
      }
    }
  }
  int ret = INF;
  for(int i = 20; i >= 0; i--) ret = min(ret, dp[N][i]);
  printf("%d\n", ret);
}