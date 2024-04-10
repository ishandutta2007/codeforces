#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a.begin(), a.end());
  std::vector<int> d(n - 1);
  for (int i = 0; i + 1 < n; ++i) {
    d[i] = a[i + 1] - a[i];
  }
  int m = *std::min_element(d.begin(), d.end());
  int f = std::count(d.begin(), d.end(), m);
  printf("%d %d\n", m, f);
}