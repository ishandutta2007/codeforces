#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n >> 1);
  for (int i = 0; i < (n >> 1); ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a.begin(), a.end());
  int result = INT_MAX;
  for (int t = 1; t <= 2; ++t) {
    int cost = 0;
    for (int i = 0; i < (n >> 1); ++i) {
      cost += std::abs(a[i] - ((i << 1) + t));
    }
    result = std::min(result, cost);
  }
  printf("%d\n", result);
}