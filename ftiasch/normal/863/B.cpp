#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  n <<= 1;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a.begin(), a.end());
  int result = INT_MAX;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int sum = 0, pair = -1;
      for (int k = 0; k < n; ++k) {
        if (k != i && k != j) {
          if (~pair) {
            sum += a[k] - pair;
            pair = -1;
          } else {
            pair = a[k];
          }
        }
      }
      result = std::min(result, sum);
    }
  }
  printf("%d\n", result);
}