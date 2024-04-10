#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  std::vector<int> p(k);
  for (int i = 0; i < k; ++i) {
    scanf("%d", &p[i]);
  }
  int result = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int want;
      scanf("%d", &want);
      int last = 0;
      for (int q = 0;; ++q) {
        result++;
        std::swap(p[q], last);
        if (last == want) {
            break;
        }
      }
      p[0] = want;
    }
  }
  printf("%d\n", result);
}