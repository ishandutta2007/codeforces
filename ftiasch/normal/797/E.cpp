#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  int b = 0;
  while (b * b < n) {
    b++;
  }
  std::vector<std::vector<int>> pre(b, std::vector<int>(n));
  for (int k = 1; k < b; ++k) {
    for (int i = n; i--;) {
      pre[k][i] = i + a[i] + k < n ? pre[k][i + a[i] + k] + 1 : 1;
    }
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int p, k;
    scanf("%d%d", &p, &k);
    p--;
    if (k < b) {
      printf("%d\n", pre[k][p]);
    } else {
      int result = 0;
      while (p < n) {
        result++;
        p += a[p] + k;
      }
      printf("%d\n", result);
    }
  }
}