// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
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
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
      cin >> P[i];
    }
    
    vector<vector<array<int, 3>>> dp(N + 1);
    const int inf = int(1e7);
    dp[0].push_back({-inf, -inf - 1, -1});
    for (int i = 0; i < N; ++i) {
      for (auto m : {1, -1}) {
        int x = P[i] * m;
        for (int id = 0; id < int(dp[i].size()); ++id) {
          auto from = dp[i][id];
          if (from[1] < x) {
            from[from[0] > x] = x;
            from[2] = id;
            bool ok = true;
            for (auto e : dp[i + 1]) {
              ok &= (e[0] > from[0] || e[1] > from[1]);
            }
            if (ok) {
              dp[i + 1].push_back(from);
            }
          }    
        }  
      }
    }
    debug(dp);
    
    if (dp[N].empty()) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      int v = 0;
      vector<int> ans(N);
      for (int i = N - 1; i >= 0; --i) {
        debug(dp[i + 1][v]);
        if (dp[i + 1][v][0] == P[i] || dp[i + 1][v][1] == P[i]) {
          ans[i] = P[i];
        } else {
          ans[i] = -P[i];
        }
        v = dp[i + 1][v][2];
      }
      for (auto e : ans) {
        cout << e << ' ';
      }
      cout << '\n';
    }
  }
}