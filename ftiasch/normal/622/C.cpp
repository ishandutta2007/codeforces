#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::vector<int> next(n);
  next[n - 1] = n;
  for (int i = n - 2; i >= 0; --i) {
    next[i] = a[i] != a[i + 1] ? i + 1 : next[i + 1];
  }
  while (q--) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    l --;
    if (a[l] != x) {
      printf("%d\n", l + 1);
    } else if (next[l] < r) {
      printf("%d\n", next[l] + 1);
    } else {
      puts("-1");
    }
  }
}