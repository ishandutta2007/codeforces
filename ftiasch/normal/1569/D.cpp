#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, l;
    scanf("%d%d%d", &n, &m, &l);
    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
      scanf("%d", &b[i]);
    }
    std::vector<std::pair<int, int>> c(l);
    for (int i = 0; i < l; ++i) {
      scanf("%d%d", &c[i].first, &c[i].second);
    }
    long long result = 0;
    for (int _ = 0; _ < 2; ++_) {
      std::sort(c.begin(), c.end());
      for (int i = 0, k = 0; i + 1 < n; ++i) {
        while (k < l && c[k].first == a[i]) {
          k++;
        }
        int cnt = 0;
        std::map<int, int> map;
        while (k < l && c[k].first < a[i + 1]) {
          result += cnt;
          int y = c[k].second;
          result -= map[y];
          map[y]++;
          cnt++;
          k++;
        }
      }
      if (!_) {
        std::swap(n, m);
        a.swap(b);
        for (int i = 0; i < l; ++i) {
          std::swap(c[i].first, c[i].second);
        }
      }
    }
    printf("%lld\n", result);
  }
}