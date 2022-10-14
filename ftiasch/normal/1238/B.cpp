#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, r;
    scanf("%d%d", &n, &r);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());
    n = a.size();
    int result = 0;
    for (int i = n; i--;) {
      if (result * r >= a[i]) {
        break;
      }
      result++;
    }
    printf("%d\n", result);
  }
}