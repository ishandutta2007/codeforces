#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char f[3][102];

void solve() {
  int n, k;
  scanf("%d%d\n", &n, &k);
  for (int i = 0; i < 3; ++i)
    gets(f[i]);

  bool dp[2][3] = {0};
  int cur = 0, next = 1;
  for (int i = 0; i < 3; ++i)
    if (f[i][0] == 's') {
      dp[cur][i] = true;
      f[i][0] = '.';
    }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (!dp[cur][j]) continue;
      if (f[j][i + 1] != '.') continue;
      dp[next][j] = true;
      if (j > 0 && f[j - 1][i + 1] == '.') dp[next][j - 1] = true;
      if (j < 2 && f[j + 1][i + 1] == '.') dp[next][j + 1] = true;
    }
    for (int it = 0; it < 2; ++it)
      for (int e = 0; e < 3; ++e) {
        for (int j = 0; j < n; ++j) {
          if (f[e][j] != '.') {
            if (j > 0) {
              f[e][j - 1] = f[e][j];
              if (j - 1 == i + 1) dp[next][e] = false;
            }
            f[e][j] = '.';
          }
        }
      }

    // for (int e = 0; e < 3; ++e)
    //   cout << dp[next][e] << "  ";
    // cout << endl;

    cur ^= 1; next ^= 1;
    memset(dp[next], 0, sizeof(dp[next]));
  }
  puts((dp[cur][0] || dp[cur][1] || dp[cur][2]) ? "YES" : "NO");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--)
    solve();
  return 0;
}