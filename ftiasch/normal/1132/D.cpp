#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

using Long = long long;

const int N = 200'000;

int n, m, b[N], count[N];
Long a[N];

bool check(Long delta) {
  if (delta == 0) {
    for (int i = 0; i < n; ++i) {
      if (a[i] < 1LL * m * b[i]) {
        return false;
      }
    }
    return true;
  }
  memset(count, 0, sizeof(*count) * m);
  Long total = 0;
  for (int i = 0; i < n; ++i) {
    // a[i] + t * delta >= m * b[i]
    Long need = (std::max(1LL * m * b[i] - a[i], 0LL) + delta - 1) / delta;
    // std::cerr << KV(i) << KV(a[i]) << KV(b[i]) << KV(need) << KV(m)
    //           << std::endl;
    total += need;
    if (total > m) {
      return false;
    }
    for (int j = 0; j < need; ++j) {
      int y = (a[i] + 1LL * j * delta + 1 + (b[i] - 1)) / b[i];
      assert(y <= m);
      count[y - 1]++;
    }
  }
  // 1st >= 0
  // 2st >= 1
  int rank = 0;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < count[i]; ++j) {
      if (rank > i) {
        return false;
      }
      rank++;
    }
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  m--;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a + i);
  }
  Long upper = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", b + i);
    upper = std::max(upper, 1LL * b[i] * m);
  }
  Long low = 0, high = upper + 1;
  while (low < high) {
    Long middle = (low + high) >> 1;
    if (check(middle)) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  printf("%lld\n", high <= upper ? high : -1);
}