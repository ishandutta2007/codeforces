// #include "debug.h"

#include <bits/stdc++.h>

const int N = 200'000;

int n, limit, a[N];

int main() {
  scanf("%d%d", &n, &limit);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  std::sort(a, a + n, std::greater<int>());
  int m = 1;
  for (int i = 0; i < n; ++i) {
    m = std::max(m, 2 * i + 2 + (a[i] >> 1));
  }
  std::vector<int> pf(m + 1);
  pf[0] = 1;
  pf[1] = -1;
  int hd = 0, hd_val = 1, k = m, k_val = 0, result = m;
  long long k_sum = 1;
  auto add = [&](int i, int dt) {
    pf[i] += dt;
    if (i <= k) {
      k_val += dt;
      k_sum += (k - i + 1LL) * dt;
    }
  };
  for (int i = 0; i < n; ++i) {
    while (hd_val == 0) {
      hd_val += pf[++hd];
    }
    add(hd, -1);
    add(hd + 1, 1);
    hd_val--;
    add(hd + 2, 2);
    add(hd + 2 + (a[i] >> 1), -1);
    add(hd + 2 + ((a[i] - 1) >> 1), -1);
    for (int _ = 0; _ < 2 && k < m; ++_) {
      k++;
      k_val += pf[k];
      k_sum += k_val;
    }
    if (k_sum >= limit) {
      while (k > 0 && k_sum - k_val >= limit) {
        k_sum -= k_val;
        k_val -= pf[k];
        k--;
      }
      result = std::min(result, k);
    }
    // std::cout << KV(pf) << std::endl;
  }
  printf("%d\n", result < m ? result : -1);
}