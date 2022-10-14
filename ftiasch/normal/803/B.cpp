#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n), result(n, n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0, z = -1; i < n; ++i) {
    if (!a[i]) {
      z = i;
    }
    if (~z) {
      result[i] = std::min(result[i], i - z);
    }
  }
  for (int i = n, z = -1; i--;) {
    if (!a[i]) {
      z = i;
    }
    if (~z) {
      result[i] = std::min(result[i], z - i);
    }
  }
  for (int i = 0; i < n; ++i) {
    printf("%d%c", result[i], " \n"[i + 1 == n]);
  }
}