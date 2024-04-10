#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int k = (n - 1) >> 1;
  std::nth_element(a.begin(), a.begin() + k, a.end());
  printf("%d\n", a[k]);
}