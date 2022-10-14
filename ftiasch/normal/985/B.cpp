#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> sum(m);
  std::vector<std::vector<char>> a(n, std::vector<char>(m + 1));
  for (int i = 0; i < n; ++i) {
    scanf("%s", a[i].data());
    for (int j = 0; j < m; ++j) {
      sum[j] += a[i][j] - '0';
    }
  }
  int i = 0;
  while (i < n) {
    bool ok = true;
    for (int j = 0; j < m; ++ j) {
        ok &= (a[i][j] - '0') < sum[j];
    }
    if (ok) {
        break;
    }
    i++;
  }
  puts(i < n ? "YES" : "NO");
}