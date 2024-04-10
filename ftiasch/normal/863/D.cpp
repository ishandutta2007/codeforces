#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int n, q, m;
  scanf("%d%d%d", &n, &q, &m);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::vector<std::tuple<int, int, int>> queries(q);
  for (int i = q; i--;) {
    int op, l, r;
    scanf("%d%d%d", &op, &l, &r);
    queries[i] = {op, l, r};
  }
  for (int k = 0; k < m; ++k) {
    int x;
    scanf("%d", &x);
    for (auto [op, l, r] : queries) {
      if (l <= x && x <= r) {
        if (op == 1) {
          if (x == l) {
            x = r;
          } else {
            x--;
          }
        } else {
          x = (l + r) - x;
        }
      }
    }
    printf("%d%c", a[x - 1], " \n"[k + 1 == m]);
  }
}