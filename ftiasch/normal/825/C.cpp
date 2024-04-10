#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a.begin(), a.end());
  int result = 0;
  for (int d : a) {
    while (2 * k < d) {
      result++;
      k *= 2;
    }
    k = std::max(k, d);
  }
  printf("%d\n", result);
}