#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &c[i]);
    }
    auto check = [&]() -> bool {
      auto one = std::find(c.begin(), c.end(), 1);
      if (one == c.end()) {
        return false;
      }
      std::rotate(c.begin(), one, c.end());
      for (int i = 1; i < n; ++i) {
        if (c[i] > c[i - 1] + 1 || c[i] == 1) {
          return false;
        }
      }
      return true;
    };
    puts(check() ? "YES" : "NO");
  }
}