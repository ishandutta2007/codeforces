#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int m = *std::max_element(a.begin(), a.end());
  int result = 1;
  for (int i = 0, len = 0; i < n; ++i) {
    if (a[i] == m) {
      len++;
    } else {
      len = 0;
    }
    result = std::max(result, len);
  }
  printf("%d\n", result);
}