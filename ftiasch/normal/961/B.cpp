#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  std::vector<int> a(n), t(n), suf0(n + 1), suf1(n + 1);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &t[i]);
  }
  for (int i = n; i--;) {
    suf0[i] = a[i] + suf0[i + 1];
    suf1[i] = (t[i] ? a[i] : 0) + suf1[i + 1];
  }
  int pre1 = 0, result = 0;
  for (int i = 0; i + k <= n; ++i) {
    result = std::max(result, pre1 + suf0[i] - suf0[i + k] + suf1[i + k]);
    pre1 += t[i] ? a[i] : 0;
  }
  printf("%d\n", result);
}