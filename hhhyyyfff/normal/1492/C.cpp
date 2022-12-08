#include <bits/stdc++.h>

using namespace std;

char s[200010], t[200010];
int n, m, ans, pre[200010][26], suc[200010][26], f[200010], g[200010];

int main() {
  scanf("%d%d%s%s", &n, &m, s + 1, t + 1);
  for (int i = 2; i <= n + 1; ++i) {
    for (int j = 0; j < 26; ++j) pre[i][j] = pre[i - 1][j];
    pre[i][s[i - 1] - 'a'] = i - 1;
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j < 26; ++j) suc[i][j] = suc[i + 1][j];
    suc[i][s[i + 1] - 'a'] = i + 1;
  }
  for (int i = 1; i <= m; ++i) f[i] = suc[f[i - 1]][t[i] - 'a'];
  g[m + 1] = n + 1;
  for (int i = m; i > 0; --i) g[i] = pre[g[i + 1]][t[i] - 'a'];
  for (int i = 1; i < m; ++i) ans = max(ans, g[i + 1] - f[i]);
  printf("%d\n", ans);
  return 0;
}