#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a;
    a.reserve(n);
    bool has[]{false, false, false};
    for (int i = 0, x; i < n; ++i) {
      scanf("%d", &x);
      if (x < 3) {
        has[x] = true;
      } else {
        a.push_back(x);
      }
    }
    auto check = [&]() -> bool {
      if (!has[1]) {
        return true;
      }
      // has[1]
      if (has[0] || has[2]) {
        return false;
      }
      std::ranges::sort(a);
      for (int i = 1; i < a.size(); ++i) {
        if (a[i - 1] + 1 == a[i]) {
          return false;
        }
      }
      return true;
    };
    puts(check() ? "YES" : "NO");
  }
}