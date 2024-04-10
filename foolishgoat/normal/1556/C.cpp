#include <bits/stdc++.h>

using namespace std;

constexpr long long inf = 1e18;

int solve() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if ((i & 1)) continue;
    long long cur = a[i], lef = cur;
    for (int j = i+1; cur >= 0 && j < n; ++j) {
      if ((j & 1)) {
        if (a[j] >= cur - lef) {
          long long add = min((long long)a[j], cur) - (cur - lef) + (j > i + 1);
          ans += add;
        }
        cur -= a[j];
      } else {
        cur += a[j];
      }
      lef = min(lef, cur);
    }
  }
  printf("%lld\n", ans);
  return 0;
}

int main() {
  int tc = 1;
  // scanf("%d", &tc);
  for (int t = 1; t <= tc; ++t) {
    solve();
  }
  return 0;
}