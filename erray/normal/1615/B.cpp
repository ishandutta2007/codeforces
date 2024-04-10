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
  const int MAX = int(2e5) + 1;
  const int LG = __lg(MAX) + 1;
  vector<vector<int>> sum(LG, vector<int>(MAX + 1));
  for (int j = 0; j < LG; ++j) {
    for (int i = 0; i < MAX; ++i) {
      sum[j][i + 1] = sum[j][i] + ((i >> j) & 1);
    }
  }

  int TT;
  cin >> TT;
  while (TT--) {
    int L, R;
    cin >> L >> R;
    int ans = 0;
    for (int i = 0; i < LG; ++i) {
      int x = sum[i][R + 1] - sum[i][L];
      debug(i, x);
      ans = max({ans, x});
    }
    cout << (R - L + 1) - ans << '\n';
  }
}