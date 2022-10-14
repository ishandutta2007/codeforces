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
    int i = std::distance(a.begin(), std::ranges::min_element(a));
    int j = std::distance(a.begin(), std::ranges::max_element(a));
    printf("%d %d\n", i + 1, j + 1);
  }
}