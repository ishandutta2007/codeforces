// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
      cin >> H[i];
    }
    const long long inf = (long long) 1e18;
    vector<vector<long long>> dp(N, vector<long long>(2, 0));
    dp[1][0] = inf;
    for (int i = 1; i < N - 1; ++i) {
      int cost = max(0, max(H[i + 1], H[i - 1]) + 1 - H[i]);
      dp[i + 1][0] = dp[i - 1][0];
      dp[i + 1][1] = dp[i - 1][1];
      if (i > 1) {
        dp[i + 1][1] = min(dp[i + 1][1], dp[i - 2][0]); 
      }
      dp[i + 1][0] += cost;
      dp[i + 1][1] += cost;
    }
    cout << (N % 2 == 1 ? dp[N - 1][0] : min(dp[N - 1][1], dp[N - 2][0])) << '\n';
  }
}