// author: erray
#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
  #include "/home/eagle/debug.h"
#else
  #define debug(...) void(37)
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<int> next(N + 1, -1);
    for (int i = 0; i < N - 1; ++i) {
      if (A[i + 1] != A[i]) {
        next[i + 1] = i + 1;
      } else {
        next[i + 1] = next[i];
      }
    }
    const int inf = int(1e9);
    vector<array<int, 3>> dp(N + 1, {inf, inf, inf});
    dp[N][2] = 0;
    for (int i = N - 1; i >= 0; --i) {
      for (int j = 1; j + i <= N; j <<= 1) {
        for (int k = 0; k < 2; ++k) {
          int n = next[i + j];
          if (n > i) {
            dp[i][k] = min(dp[i][k], dp[n][k + 1] + (i + j) - n); 
          }
        }
      }
      int need = N - i;
      int l = 1;
      while (l < need) {
        l <<= 1;
      }
      for (int k = 0; k < 3; ++k) {
        dp[i][k] = min(dp[i][k], (l - need) + (2 - k));
      }
      debug(i, dp[i]);
    }
    //debug(dp);
    cout << dp[0][0] << '\n';
  }
}