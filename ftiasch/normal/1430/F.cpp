#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Long = long long;

const int N = 2001;

void update(Long &x, Long a) { x = ~x ? std::min(x, a) : a; }

int n, m, l[N], r[N], a[N];
Long dp[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", l + i, r + i, a + i);
  }
  for (int i = n; i--;) {
    dp[i] = -1;
    int remains = m;
    Long useds = 0;
    for (int j = i; j < n; ++j) {
      // r + reloads * m >= a[j] - r
      int reloads = (std::max(a[j] - remains, 0) + (m - 1)) / m;
      if (reloads > r[j] - l[j]) {
        break;
      }
      useds += a[j];
      remains = remains + 1LL * reloads * m - a[j];
      if (j + 1 == n) {
        update(dp[i], useds);
      } else {
        bool can_reload = reloads < r[j] - l[j] || r[j] < l[j + 1];
        if (~dp[j + 1] && can_reload) {
          update(dp[i], useds + remains + dp[j + 1]);
        }
      }
    }
  }
  printf("%lld\n", dp[0]);
}