#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> count(m);
  for (int i = 0, a; i < n; ++i) {
    scanf("%d", &a);
    count[a - 1]++;
  }
  long long result = n * (n - 1LL) / 2;
  for (int i = 0; i < m; ++i) {
    result -= count[i] * (count[i] - 1LL) / 2;
  }
  printf("%lld\n", result);
}