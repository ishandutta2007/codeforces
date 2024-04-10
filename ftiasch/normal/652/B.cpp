#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a.begin(), a.end());
  for (int i = 0; i < n; ++i) {
    printf("%d%c", a[(i & 1 ? (n + 1) >> 1 : 0) + (i >> 1)], " \n"[i + 1 == n]);
  }
}