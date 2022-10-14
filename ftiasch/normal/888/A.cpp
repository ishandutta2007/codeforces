#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int result = 0;
  for (int i = 1; i + 1 < n; ++i) {
    result += (a[i] - a[i - 1]) * (a[i] - a[i + 1]) > 0;
  }
  printf("%d\n", result);
}