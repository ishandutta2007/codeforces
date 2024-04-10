#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int m = *std::min_element(a.begin(), a.end());
  int result = n;
  for (int i = 0, last = -1; i < n; ++i) {
    if (a[i] == m) {
      if (~last) {
        result = std::min(result, i - last);
      }
      last = i;
    }
  }
  printf("%d\n", result);
}