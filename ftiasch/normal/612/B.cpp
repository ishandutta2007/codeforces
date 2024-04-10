#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> p(n);
  for (int i = 0, f; i < n; ++i) {
    scanf("%d", &f);
    p[f - 1] = i;
  }
  long long result = 0;
  for (int i = 1; i < n; ++i) {
    result += std::abs(p[i] - p[i - 1]);
  }
  printf("%lld\n", result);
}