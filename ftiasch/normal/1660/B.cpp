#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    std::ranges::sort(a);
    auto check = [&]() -> bool {
      if (n == 1) {
        return a[0] == 1;
      }
      return a[n - 2] + 1 >= a[n - 1];
    }();
    puts(check ? "YES" : "NO");
  }
}