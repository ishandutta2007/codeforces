#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<std::pair<int, int>> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i].first);
      a[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &b[i].first);
      b[i].second = i;
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    puts([&]() {
      std::vector<int> fenwick(n);
      for (int i = 0; i < n; ++i) {
        if (a[i].first != b[i].first) {
          return false;
        }
        for (int k = a[i].second; k >= 0; k -= ~k & k + 1) {
          if (b[i].second < fenwick[k]) {
            return false;
          }
        }
        for (int k = a[i].second; k < n; k += ~k & k + 1) {
            fenwick[k] = std::max(fenwick[k], b[i].second);
        }
      }
      return true;
    }()
             ? "YES"
             : "NO");
  }
}