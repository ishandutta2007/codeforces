#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

char str[100002];
long long dp[2][3][3][3][27];

int main() {
  // cout << sizeof(dp) / 1024.0 / 1024 << endl;

  int n, m;
  scanf("%d%d\n", &n, &m);
  gets(str);


  int cur = 0, next = 1;
  dp[cur][0][0][0][m] = 1;

  for (int i = 0; i < n; ++i) {
    for (int i1 = 0; i1 < 3; ++i1) {
      int dpij = i - i1;
      for (int i2 = 0; i2 < 3; ++i2) {
        int dpij1 = i - i2;
        for (int i3 = 0; i3 < 3; ++i3) {
          int dpi1j = i - i3;
          for (int last = 0; last <= m; ++last) {
            if (!dp[cur][i1][i2][i3][last]) continue;
            for (int let = 0; let < m; ++let) {
              int ndpi1j = (i - 1 >= 0 && last == str[i] - 'a') ? (dpi1j + 1) : dpij;
              int ndpij1 = (i - 1 >= 0 && let == str[i - 1] - 'a') ? (dpij1 + 1) : dpij;
              int ndpij = (let == str[i] - 'a') ? (dpij + 1) : max(ndpij1, ndpi1j);
              
              ndpij = min(2, (i + 1) - ndpij);
              ndpi1j = min(2, (i + 1) - ndpi1j);
              ndpij1 = min(2, (i + 1) - ndpij1);

              dp[next][ndpij][ndpij1][ndpi1j][let] += dp[cur][i1][i2][i3][last];
            }
          }
        }
      }
    }

    cur ^= 1; next ^= 1;
    memset(dp[next], 0, sizeof(dp[next]));
  }

  long long ans = 0;
  for (int i1 = 0; i1 < 3; ++i1) {
    int dpij = n - i1;
    for (int i2 = 0; i2 < 3; ++i2) {
      for (int i3 = 0; i3 < 3; ++i3) {
        for (int last = 0; last < m; ++last) {
          if (i1 == 1)
            ans += dp[cur][i1][i2][i3][last];
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}