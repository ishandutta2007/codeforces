#include <bits/stdc++.h>

const int N = 100'000;
const int M = 20'000'001;

int n, a[N], min_div[M], mul[M];
std::vector<int> primes;
long long dp[M];

void enum_divs(int a, int pd) {
  if (a == 1) {
    mul[pd]++;
  } else {
    int p = min_div[a];
    int e = 0;
    while (a % p == 0) {
      a /= p;
      e++;
    }
    enum_divs(a, pd);
    for (int i = 0; i < e; ++i) {
      enum_divs(a, pd *= p);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  int m = *std::max_element(a, a + n) + 1;
  memset(min_div, -1, sizeof(int) * m);
  for (int d = 2; d < m; ++d) {
    if (min_div[d] == -1) {
      min_div[d] = d;
      primes.push_back(d);
    }
    for (int p : primes) {
      if (d * p >= m) {
        break;
      }
      min_div[p * d] = p;
      if (d % p == 0) {
        break;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    enum_divs(a[i], 1);
  }
  for (int i = m; i-- > 1;) {
    dp[i] = 1LL * i * mul[i];
    for (int p : primes) {
      if (i * p >= m) {
        break;
      }
      dp[i] = std::max(dp[i], dp[i * p] + 1LL * i * (mul[i] - mul[i * p]));
    }
  }
  std::cout << dp[1] << std::endl;
}