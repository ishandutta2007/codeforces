#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

int main() {
  int N, K;
  cin >> N >> K;

  vector< vector< int > > dp(N + 1, vector< int >(N + 1));
  dp[1][1] = 1;

  for(int i = 1; i < N; i++) {
    vector< vector< int > > dp2(N + 1, vector< int >(N + 1));
    for(int j = N; j >= 0; j--) {
      for(int k = N; k >= 0; k--) {
        if(dp[j][k] == 0) continue;
        if(k != N) {
          dp2[max(j, k + 1)][k + 1] += dp[j][k];
          if(dp2[max(j, k + 1)][k + 1] >= mod) dp2[max(j, k + 1)][k + 1] -= mod;
        }
        dp2[j][1] += dp[j][k];
        if(dp2[j][1] >= mod) dp2[j][1] -= mod;
      }
    }
    dp.swap(dp2);
  }

  vector< int > sum(N + 1);
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      sum[i] += dp[i][j];
      if(sum[i] >= mod) sum[i] -= mod;
    }
  }
  int64 ret = 0;

  for(int i = 1; i <= N; i++) {
    vector< int > dp2(N+1);
    dp2[0] = 1;
    for(int j = 0; j < N; j++) {
      vector< int > dp3(N+1);
      for(int k = 0; k <= N; k++) {
        if(k != N) {
          if((k + 1) * i < K) {
            dp3[k + 1] += dp2[k];
            if(dp3[k + 1] >= mod) dp3[k + 1] -= mod;
          }
        }
        if(i < K) {
          dp3[1] += dp2[k];
          if(dp3[1] >= mod) dp3[1] -= mod;
        }
      }
      dp2.swap(dp3);
    }
    for(int j = 1; j <= N; j++) {
      (ret += 1LL * dp2[j] * sum[i] % mod) %= mod;
    }
  }
  cout << ret << endl;
}