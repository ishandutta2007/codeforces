#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 500'000;

int n, k, d, a[N];
bool dp[N + 1];

int main() {
  scanf("%d%d%d", &n, &k, &d);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  std::sort(a, a + n);
  dp[0] = true;
  for (int i = k, last = -1; i <= n; ++i) {
    if (dp[i - k]) {
      last = i - k;
    }
    dp[i] = a[i - 1] - a[last] <= d;
  }
  puts(dp[n] ? "YES" : "NO");
}