#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a.begin(), a.end(), std::greater<int>());
  int result = 0;
  while (m > 0) {
    m -= a[result++];
  }
  printf("%d\n", result);
}