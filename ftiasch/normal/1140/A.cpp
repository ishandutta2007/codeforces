#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  int result = 0;
  for (int i = 1, a, m = 0; i <= n; ++i) {
    scanf("%d", &a);
    m = std::max(m, a);
    if (m == i) {
      result++;
      m = 0;
    }
  }
  printf("%d\n", result);
}