#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::nth_element(a.begin(), a.begin() + (n - 2), a.end());
  int m0 = a[n - 1];
  int m1 = a[n - 2];
  // min x: x + k * (x + 1) >= m
  // <=> (k + 1) * x >= m - k
  int x = m / (k + 1);
  printf("%lld\n", 1LL * x * m1 + 1LL * (m - x) * m0);
}