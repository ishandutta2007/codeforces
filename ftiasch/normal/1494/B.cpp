#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, lim[4];
    scanf("%d", &n);
    for (int i = 0; i < 4; ++ i) {
        scanf("%d", lim + i);
    }
    bool found = false;
    for (int mask = 0; mask < 1 << 4 && !found; ++mask) {
      // 0 1 U
      // 1 2 R
      // 2 3 D
      // 3 0 L
      int cnt[4];
      for (int i = 0; i < 4; ++i) {
        cnt[i] = mask >> i & 1;
      }
      bool ok = true;
      for (int i = 0; i < 4; ++ i) {
          ok &= cnt[i] + cnt[(i + 1) & 3] <= lim[i] && lim[i] - cnt[i] - cnt[(i + 1) & 3] <= (n - 2);
      }
      found |= ok;
    }
    puts(found ? "YES" : "NO");
  }
}