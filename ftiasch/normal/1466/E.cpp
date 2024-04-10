#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

void add(int &x, int a) {
  x += a;
  if (x >= MOD) {
    x -= MOD;
  }
}

using u64 = uint64_t;

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<u64> x(n);
    int m = 0;
    for (int i = 0; i < n; ++i) {
      std::cin >> x[i];
      while (x[i] >= 1ULL << m) {
        m++;
      }
    }
    std::vector<int> power(m), count(m);
    for (int j = 0; j < m; ++j) {
      power[j] = (1ULL << j) % MOD;
      for (int i = 0; i < n; ++i) {
        if (x[i] >> j & 1) {
          count[j]++;
        }
      }
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
      int as = 0, os = 0;
      for (int j = 0; j < m; ++j) {
        if (x[i] >> j & 1) {
          add(as, 1LL * power[j] * count[j] % MOD);
        }
      }
      for (int j = 0; j < m; ++j) {
        int c = (x[i] >> j & 1) ? n : count[j];
        add(os, 1LL * power[j] * c % MOD);
      }
      add(result, 1LL * as * os % MOD);
    }
    std::cout << result << "\n";
  }
}