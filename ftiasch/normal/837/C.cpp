#line 1 "sol.cpp"
#include <bits/stdc++.h>

bool check(int x0, int y0, int x1, int y1, int a, int b) {
  for (int _ = 0; _ < 2; ++_) {
    for (int __ = 0; __ < 2; ++__) {
      if (x0 + x1 <= a && std::max(y0, y1) <= b) {
          return true;
      }
      if (y0 + y1 <= b && std::max(x0, x1) <= a) {
          return true;
      }
      std::swap(x1, y1);
    }
    std::swap(x0, y0);
  }
  return false;
}

int main() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);
  std::vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &x[i], &y[i]);
  }
  int result = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (check(x[i], y[i], x[j], y[j], a, b)) {
        result = std::max(result, x[i] * y[i] + x[j] * y[j]);
      }
    }
  }
  printf("%d\n", result);
}