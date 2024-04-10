#include <bits/stdc++.h>

int main()
{
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    std::vector<int> min(n, m), max(n, -1);
    for (int i = 0, x; i < m; ++ i) {
      scanf("%d", &x);
      x --;
      if (min[x] == m) {
        min[x] = i;
      }
      max[x] = i;
    }
    int result = 0;
    for (int i = 0; i < n; ++ i) {
      for (int j = std::max(i - 1, 0); j < n && j <= i + 1; ++ j) {
        if (i == j) {
          result += max[i] == -1;
        } else {
          result += max[j] < min[i];
        }
      }
    }
    printf("%d\n", result);
  }
}