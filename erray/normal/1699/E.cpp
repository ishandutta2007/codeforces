// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

using int128 = __int128_t;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N, M;
    cin >> N >> M;
    vector<bool> in(M + 1);
    for (int i = 0; i < N; ++i) {
      int X;
      cin >> X;
      in[X] = true;
    }
    int total = accumulate(in.begin(), in.end(), 0);
    int r = M;
    int ans = M - 1;
    int good_c = 0;
    vector<int128> dp(M + 1); //just in case 
    dp[1] = 1;
    bool one = in[1];
    for (int l = M; l >= 1; --l) {    
      if (one && l == 1) {
        good_c += 1;
      }
      for (int i = l; i <= M; i += l) {
        if (dp[i] == 0 && dp[i / l] > 0 && in[i]) {
          good_c += 1;
        }
        dp[i] += dp[i / l];
      }
      while (r > l) {
        bool bad = false;
        for (int j = M / r * r; j > 0; j -= r) {
          dp[j] -= dp[j / r];
          if (dp[j] == 0 && in[j]) {
            bad = true;
          }
        } 
        if (!bad) {
          --r;
        } else {
          for (int j = r; j <= M; j += r) {
            dp[j] += dp[j / r];
          }
          break;
        }
      }
      debug(l, r, good_c);
      if (good_c == total) {
        ans = min(ans, r - l);
      }
    }
    cout << ans << '\n';
  }
}