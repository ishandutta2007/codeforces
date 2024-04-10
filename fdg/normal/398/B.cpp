#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

bool w1[2002], w2[2002];
long double dp1[2][2002];
long double dp2[2][2002];

int main() {
  int n, m, x, y;
  scanf("%d%d", &n, &m);
  int r = n, c = n;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x, &y); --x; --y;
    if (!w1[x]) {
      w1[x] = true;
      --r;
    }
    if (!w2[y]) {
      w2[y] = true;
      --c;
    }
  }
  // cout << r << "  " << c << endl;
  long double ans = 0;
  int N = max(r, c);
  dp1[0][0] = 1.0;
  dp2[0][0] = 1.0;
  int cur = 0, nx = 1;
  for (int st = 0; st < 100000; ++st) {
    for (int k = 0; k <= r; ++k) {
      if (dp1[cur][k] > 1e-20) {
        dp1[nx][k] += 1.0 * (n - (r - k)) / n * dp1[cur][k];
        if (k + 1 <= r)
          dp1[nx][k + 1] += 1.0 * (r - k) / n * dp1[cur][k];
      }
    }
    for (int k = 0; k <= c; ++k) {
      if (dp2[cur][k] > 1e-20) {
        dp2[nx][k] += 1.0 * (n - (c - k)) / n * dp2[cur][k];
        if (k + 1 <= c)
          dp2[nx][k + 1] += 1.0 * (c - k) / n * dp2[cur][k];
      }
    }
    // cout << st << " " << dp1[st][r] << "  " << dp2[st][c] << endl;
    ans += (st + 1) * ((dp1[nx][r]) * (dp2[nx][c]) - dp1[cur][r] * dp2[cur][c]);
    cur ^= 1; nx ^= 1;
    memset(dp1[nx], 0, sizeof(dp1[nx]));
    memset(dp2[nx], 0, sizeof(dp2[nx]));
  }
  printf("%.5lf\n", (double)ans);
  return 0;
}