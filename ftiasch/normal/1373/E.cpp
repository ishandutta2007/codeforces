#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

void update(Long &x, Long a) { x = ~x ? std::min(x, a) : a; }

int digit_sum(Long x) {
  int result = 0;
  for (; x; x /= 10) {
    result += x % 10;
  }
  return result;
}

const int N = 150;
const int K = 9;

Long with_sum[N + 1], result[N + 1][K + 1];

int main() {
  for (int s = 0; s <= N; ++s) {
    with_sum[s] = s < 10 ? s : with_sum[s - 9] * 10 + 9;
  }
  memset(result, -1, sizeof(result));
  for (int r = 0; r < 10; ++r) {
    for (int k = 0, low_sum = 0; k <= K && r + k < 10; ++k) {
      low_sum += r + k;
      for (int hs = 0, s = low_sum; s <= N; hs++, s += (k + 1)) {
        update(result[s][k], with_sum[hs] * 10 + r);
      }
    }
  }
  Long ten = 10;
  for (int t = 1; t <= 17; ++t, ten *= 10) {
    for (int lead = 1; lead < 10; ++lead) {
      for (int z = 1; z <= K; ++z) {
        Long base = lead * ten - z;
        for (int all = z; all <= K; ++all) {
          int low_sum = 0;
          for (int i = 0; i <= all; ++i) {
            low_sum += digit_sum(base + i);
          }
          for (int hs = 0, s = low_sum; s <= N; hs++, s += (all + 1)) {
            update(result[s][all], with_sum[hs] * ten * 10 + base);
          }
        }
      }
    }
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%lld\n", result[n][k]);
  }
}