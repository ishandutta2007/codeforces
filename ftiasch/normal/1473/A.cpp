#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, d;
    scanf("%d%d", &n, &d);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    auto check = [&]() {
      std::sort(a.begin(), a.end());
      return a.back() <= d || a[0] + a[1] <= d;
    };
    puts(check() ? "YES" : "NO");
  }
}