#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n + 1);
  int ones = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ones += a[i];
  }
  int result = 0;
  for (int i = 0, zeros = 0; i <= n; ++i) {
    result = std::max(result, zeros + ones);
    zeros += !a[i];
    ones -= a[i];
  }
  printf("%d\n", result);
}