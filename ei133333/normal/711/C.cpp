#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 58;

int64 N, M, K, C[105], P[105][105];
int64 dp[105][105][105];

inline void chmin(int64& x, int64 y)
{
  x = min(x, y);
}

int main()
{
  cin >> N >> M >> K;
  for(int i = 0; i < N; i++) {
    cin >> C[i];
    --C[i];
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      cin >> P[i][j];
    }
  }
  fill_n(**dp, 105 * 105 * 105, INF);
  if(C[0] == -1) {
    for(int i = 0; i < M; i++) {
      dp[0][1][i] = P[0][i];
    }
  } else {
    dp[0][1][C[0]] = 0;
  }
  for(int i = 1; i < N; i++) {
    for(int j = K; j >= 0; j--) {
      for(int k = 0; k < M; k++) {
        if(dp[i - 1][j][k] < INF) {
          if(C[i] == -1) {
            for(int l = 0; l < M; l++) {
              if(k == l) chmin(dp[i][j][l], dp[i - 1][j][k] + P[i][l]);
              else chmin(dp[i][j + 1][l], dp[i - 1][j][k] + P[i][l]);
            }
          } else {
            if(C[i] == k) chmin(dp[i][j][C[i]], dp[i - 1][j][k]);
            else chmin(dp[i][j + 1][C[i]], dp[i - 1][j][k]);
          }
        }
      }
    }
  }

  int64 ret = INF;
  for(int i = M - 1; i >= 0; i--) {
    ret = min(ret, dp[N - 1][K][i]);
  }

  if(ret >= INF) cout << -1 << endl;
  else cout << ret << endl;
}