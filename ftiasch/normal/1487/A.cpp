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
    int m = *std::min_element(a.begin(), a.end());
    printf("%d\n", static_cast<int>(n - std::count(a.begin(), a.end(), m)));
  }
}