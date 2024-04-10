#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  long long result = 0;
  std::vector<long long> bucket(m, -1'000'000'000LL * n);
  for (int i = 0, r = 0, a; i < n; ++i) {
    scanf("%d", &a);
    for (int j = 0; j < m; ++j) {
      if (j != r) {
        bucket[j] += a;
      } else {
        bucket[j] = std::max(bucket[j], 0LL) + a - k;
      }
      result = std::max(result, bucket[j]);
    }
    r = r + 1 == m ? 0 : r + 1;
  }
  printf("%lld\n", result);
}