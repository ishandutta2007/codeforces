#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  // hero hC dC
  // monster hM dM
  // (dC + x * W) * ((hC + y * A - 1) / dM + 1) >= hM
  int T;
  scanf("%d", &T);
  while (T--) {
    int dc, dm, k, w;
    long long hc, hm, a;
    scanf("%lld%d%lld%d%d%d%lldd", &hc, &dc, &hm, &dm, &k, &w, &a);
    bool ok = false;
    for (int x = 0; x <= k && !ok; ++x) {
      int y = k - x;
      long long rd = ((hc + 1LL * y * a - 1) / dm + 1);
      ok |= (dc + 1LL * x * w) >= (hm + rd - 1) / rd;
    }
    puts(ok ? "YES" : "NO");
  }
}