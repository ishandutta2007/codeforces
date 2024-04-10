#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a.begin(), a.end());
  for (int i = 0, b; i < m; ++i) {
    scanf("%d", &b);
    printf(
        "%d%c",
        static_cast<int>(std::upper_bound(a.begin(), a.end(), b) - a.begin()),
        " \n"[i + 1 == m]);
  }
}