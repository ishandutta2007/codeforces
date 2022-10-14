#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (n * n < k) {
    puts("-1");
    return 0;
  }
  std::vector<std::vector<int>> a(n, std::vector<int>(n));
  for (int i = 0; i < n; ++i) {
    if (k) {
      a[i][i] = 1;
      k--;
    }
    for (int j = i + 1; j < n; ++j) {
      if (k >= 2) {
        a[i][j] = a[j][i] = 1;
        k -= 2;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      printf("%d%c", a[i][j], " \n"[j + 1 == n]);
    }
  }
}