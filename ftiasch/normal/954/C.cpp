#line 1 "sol.cpp"
#include <bits/stdc++.h>

const std::pair<int, int> NO_SOL = {0, 0};

std::pair<int, int> check(int n, const std::vector<int> &a) {
  int m = 0;
  for (int i = 1; i < n; ++i) {
    int d = std::abs(a[i] - a[i - 1]);
    if (d == 0) {
      return NO_SOL;
    }
    if (d != 1) {
      m = d;
    }
  }
  if (!m) {
    return {1, 1e9};
  }
  for (int i = 1; i < n; ++i) {
    int d = a[i] - a[i - 1];
    if (std::abs(d) == 1) {
      if (d == 1) {
        if (a[i] % m == 0) {
          return NO_SOL;
        }
      } else {
        if (a[i] % m == m - 1) {
            return NO_SOL;
        }
      }
    } else if (std::abs(d) != m) {
      return NO_SOL;
    }
  }
  return {1e9, m};
}

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  auto [x, y] = check(n, a);
  if (y) {
    printf("YES\n%d %d\n", x, y);
  } else {
    puts("NO");
  }
}