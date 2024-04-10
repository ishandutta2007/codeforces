#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%*d%d", &n);
    std::vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    a[n] = 0;
    int result = 0;
    for (int i = 0; i + 2 <= n; ++i) {
      if (a[i + 1] == a[i + 2] + 1) {
        i++;
      } else {
        result++;
      }
    }
    printf("%d\n", result);
  }
}