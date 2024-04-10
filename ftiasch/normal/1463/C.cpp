#include <bits/stdc++.h>

const int N = 100'000;

int signum(int x) { return x == 0 ? 0 : x > 0 ? 1 : -1; }

int t[N], x[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d%d", t + i, x + i);
    }
    int result = 0, src = 0, dst = 0;
    for (int i = 0; i < n; ++i) {
      if (src == dst) {
        dst = x[i];
      }
      int new_src = dst;
      if (i + 1 < n && t[i + 1] - t[i] < std::abs(dst - src)) {
        int elapse = t[i + 1] - t[i];
        new_src = src < dst ? src + elapse : src - elapse;
      }
      result += signum(x[i] - src) * signum(x[i] - new_src) <= 0;
      src = new_src;
    }
    printf("%d\n", result);
  }
}