#line 1 "sol.cpp"
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
    std::sort(a.begin(), a.end(), std::greater<int>());
    int target = 2048;
    for (auto x : a) {
      if (x <= target) {
        target -= x;
      }
    }
    puts(target ? "NO" : "YES");
  }
}