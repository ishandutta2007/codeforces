#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

int main() {
  Long sum, len;
  std::cin >> sum >> len;
  Long low_sum = 0;
  for (int i = 1; i <= len; ++i) {
    low_sum += i;
    if (low_sum > sum) {
      puts("-1");
      return 0;
    }
  }
  Long max_d = sum / low_sum;
  Long d = 1;
  for (Long i = 1; i * i <= sum; ++i) {
    if (sum % i == 0) {
      if (i <= max_d) {
        d = std::max(d, i);
      }
      if (sum / i <= max_d) {
        d = std::max(d, sum / i);
      }
    }
  }
  for (int i = 1; i < len; ++i) {
    printf("%lld ", d * i);
  }
  printf("%lld\n", sum - (low_sum - len) * d);
}