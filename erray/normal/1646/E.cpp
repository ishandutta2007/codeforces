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
  int N, M;
  cin >> N >> M;
  const int MAX = __lg(N) + 5;
  vector<long long> dp(MAX);   
  vector<bool> used(M * MAX + 1);
  for (int i = 1; i < MAX; ++i) {
    dp[i] = dp[i - 1];
    int c = 0;
    for (int j = 1; j <= M; ++j) {
      c += i;
      if (!used[c]) {
        used[c] = true;
        dp[i] += 1;
      }
    }
  }
  debug(dp);
  vector<bool> vis(N + 1);
  long long ans = 1;
  for (int i = 2; i <= N; ++i) {
    if (vis[i]) {
      continue;
    }
    int f = i;
    int p = 1;
    for (int j = 2; 1LL * f * i <= N; ++j) {
      f *= i;
      vis[f] = true;
      p = j;
    }    
    debug(p);
    ans += dp[p];
  }
  cout << ans << '\n';
}