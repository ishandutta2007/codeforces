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
    std::nth_element(a.begin(), a.begin() + (n - 2), a.end());
    printf("%d\n", std::min(a[n - 2] - 1, n - 2));
  }
}