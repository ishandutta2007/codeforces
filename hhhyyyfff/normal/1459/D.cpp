#include <bits/stdc++.h>

using namespace std;

int n, ai, bi, suma, sumb, f[110][110][10010];
double ans;

int main() {
  scanf("%d", &n);
  memset(f, 63, sizeof(f));
  f[0][0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &ai, &bi);
    for (int j = 0; j < i; ++j)
      for (int k = 0; k <= suma; ++k) {
        f[i][j][k] = min(f[i][j][k], f[i - 1][j][k] + bi);
        f[i][j + 1][k + ai] = min(f[i][j + 1][k + ai], f[i - 1][j][k]);
      }
    suma += ai;
    sumb += bi;
  }
  for (int i = 1; i <= n; ++i) {
    ans = 0;
    for (int j = 0; j <= suma; ++j)
      if (f[n][i][j] <= suma)
        ans = max(ans, sumb - f[n][i][j] + min((j - (sumb - f[n][i][j])) * 2,
            f[n][i][j]) / 2.0);
    printf("%.10f ", ans);
  }
  return 0;
}