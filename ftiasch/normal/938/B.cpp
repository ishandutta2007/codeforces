#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n + 2);
  a[0] = 1;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int result = a[n + 1] = 1'000'000;
  for (int i = 0; i <= n; ++i) {
    result = std::min(result, std::max(a[i] - 1, 1'000'000 - a[i + 1]));
  }
  printf("%d\n", result);
}