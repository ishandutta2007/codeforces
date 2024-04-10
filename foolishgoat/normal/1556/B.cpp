#include <bits/stdc++.h>

using namespace std;

constexpr long long inf = 1e18;

int solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  vector<int> cnt(2, 0);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    a[i] &= 1;
    cnt[a[i]]++;
  }
  long long ans = inf;
  if (abs(cnt[0] - cnt[1]) > 1)
    ans = -1;
  for (int b = 0; b < 2; ++b) {
    if (cnt[b] < cnt[b^1]) continue;
    int p = 0;
    long long cur = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == b) {
        cur += abs(p - i);
        p += 2;
      }
    }
    ans = min(ans, cur);
  }
  if (ans >= inf)
    ans = -1;
  printf("%lld\n", ans);
  return 0;
}

int main() {
  int tc = 1;
  scanf("%d", &tc);
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
  return 0;
}