#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int W, H, w, h;
    int x[2], y[2];
    scanf("%d%d%d%d%d%d%d%d", &W, &H, x, y, x + 1, y + 1, &w, &h);
    int result = INT_MAX;
    for (int tx = 0; tx < 2; ++tx) {
      for (int ty = 0; ty < 2; ++ty) {
        int dx = std::max(w - x[0], 0);
        int dy = std::max(h - y[0], 0);
        if (x[1] + dx <= W) {
          result = std::min(result, dx);
        }
        if (y[1] + dy <= H) {
          result = std::min(result, dy);
        }
        y[0] = H - y[0];
        y[1] = H - y[1];
        std::swap(y[0], y[1]);
      }
      x[0] = W - x[0];
      x[1] = W - x[1];
      std::swap(x[0], x[1]);
    }
    if (result < INT_MAX) {
      printf("%.9f\n", 1.0 * result);
    } else {
      puts("-1");
    }
  }
}