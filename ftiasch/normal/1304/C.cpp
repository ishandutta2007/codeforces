#include <bits/stdc++.h>

const int N = 101;

int t[N], l[N], r[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    t[0] = 0, l[0] = r[0] = m;
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d%d", t + i, l + i, r + i);
    }
    int cl = l[n], cr = r[n];
    bool ok = true;
    for (int i = n; i-- && ok;) {
      int dt = t[i + 1] - t[i];
      cl = std::max(cl - dt, l[i]), cr = std::min(cr + dt, r[i]);
      ok &= cl <= cr;
    }
    puts(ok ? "YES" : "NO");
  }
}