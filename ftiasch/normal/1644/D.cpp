#line 1 "sol.cpp"
#include <bits/stdc++.h>

int get_min(const std::map<int, int> &m, int n) {
  if (m.size() < n) {
    return -1;
  }
  int result = INT_MAX;
  for (auto [k, v] : m) {
    result = std::min(result, v);
  }
  return result;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m, k, q;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    std::map<int, int> row, col;
    for (int i = 0, x, y; i < q; ++i) {
      scanf("%d%d", &x, &y);
      row[x - 1] = i;
      col[y - 1] = i;
    }
    int min_row = get_min(row, n);
    int min_col = get_min(col, m);
    std::vector<bool> ok(q);
    for (auto [_, v] : row) {
      if (min_col <= v) {
          ok[v] = true;
      }
    }
    for (auto [_, v] : col) {
      if (min_row <= v) {
          ok[v] = true;
      }
    }
    int result = 1;
    for (int i = 0; i < q; ++i) {
      if (ok[i]) {
        result = 1LL * result * k % 998'244'353;
      }
    }
    printf("%d\n", result);
  }
}