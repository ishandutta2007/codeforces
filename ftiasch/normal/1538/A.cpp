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
    int i = std::min_element(a.begin(), a.end()) - a.begin();
    int j = std::max_element(a.begin(), a.end()) - a.begin();
    if (i > j) {
      std::swap(i, j);
    }
    printf("%d\n", std::min({j + 1, n - i, i + 1 + n - j}));
  }
}