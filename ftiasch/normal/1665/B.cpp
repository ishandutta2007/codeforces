#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::map<int, int> cmap;
    for (int i = 0, a; i < n; ++i) {
      scanf("%d", &a);
      cmap[a]++;
    }
    int c = 0;
    for (auto [_, v] : cmap) {
      c = std::max(c, v);
    }
    int result = 0;
    while (c < n) {
      result++;
      int swaps = std::min(n - c, c);
      result += swaps;
      c += swaps;
    }
    printf("%d\n", result);
  }
}