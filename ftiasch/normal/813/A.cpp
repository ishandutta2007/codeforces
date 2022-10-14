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
  int m;
  scanf("%d", &m);
  std::vector<int> l(m), r(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &l[i], &r[i]);
  }
  int sum = 0, result = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    sum += a[i];
    while (j < m && r[j] < sum) {
      j++;
    }
    if (j == m) {
      result = -1;
      break;
    }
    result = std::max(result, std::max(sum, l[j]));
  }
  printf("%d\n", result);
}