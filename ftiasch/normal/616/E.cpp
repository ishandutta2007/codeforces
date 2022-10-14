#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

using Long = long long;

Long sum(Long l, Long r) {
  return ((l + r) % MOD) * ((r - l + 1) % MOD) % MOD * (500'000'004) % MOD;
}

int main() {
  Long n, m;
  std::cin >> n >> m;
  Long result = (n % MOD) * (m % MOD) % MOD;
  for (Long i = 1; i <= m && i <= n;) {
    Long j = std::min(n / (n / i), m);
    result += MOD - (n / i % MOD) * sum(i, j) % MOD;
    if (result >= MOD) {
      result -= MOD;
    }
    i = j + 1;
  }
  std::cout << result << std::endl;
}