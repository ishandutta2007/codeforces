#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  int o = -1, e = 0, half = n >> 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int a =
          std::abs(i - half) + std::abs(j - half) <= half ? (o += 2) : (e += 2);
      printf("%d%c", a, " \n"[j + 1 == n]);
    }
  }
}