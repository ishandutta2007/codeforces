#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &b[j]);
    }
    a[i] = *std::min_element(b.begin(), b.end());
  }
  printf("%d\n", *std::max_element(a.begin(), a.end()));
}