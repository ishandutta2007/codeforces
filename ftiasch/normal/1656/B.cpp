#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, target;
    scanf("%d%d", &n, &target);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    std::ranges::sort(a);
    bool found = false;
    for (int i = 0, j = 1; j < n; ++j) {
      while (i < j && a[i] + target < a[j]) {
        i++;
      }
      found |= a[i] + target == a[j];
    }
    puts(found ? "YES" : "NO");
  }
}