#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n), count(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      a[i]--;
    }
    int result = n + 1;
    for (int i = 0, j = 0; i < n; ++i) {
      count[a[i]]++;
      while (count[a[i]] > 1) {
        count[a[j]]--;
        j++;
      }
      if (j) {
        result = std::min(result, i - j + 2);
      }
    }
    printf("%d\n", result <= n ? result : -1);
  }
}