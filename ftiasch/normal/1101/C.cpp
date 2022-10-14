#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<std::tuple<int, int, int>> seg(n);
    for (int i = 0, l, r; i < n; ++i) {
      scanf("%d%d", &l, &r);
      seg[i] = {l, r, i};
    }
    [&]() {
      std::sort(seg.begin(), seg.end());
      std::vector<int> result(n, 2);
      int maxr = std::get<1>(seg[0]);
      result[std::get<2>(seg[0])] = 1;
      for (int i = 1; i < n; ++i) {
        if (maxr < std::get<0>(seg[i])) {
          for (int i = 0; i < n; ++i) {
            printf("%d%c", result[i], " \n"[i + 1 == n]);
          }
          return 0;
        }
        maxr = std::max(maxr, std::get<1>(seg[i]));
        result[std::get<2>(seg[i])] = 1;
      }
      puts("-1");
      return 0;
    }();
  }
}