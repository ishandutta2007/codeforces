#line 1 "sol.cpp"
#include <bits/stdc++.h>

using Grid = std::vector<std::vector<char>>;

bool check(int n, int m, const Grid &s) {
  if (n % 3 != 0) {
    return false;
  }
  int h = n / 3;
  char c[3];
  for (int offset = 0; offset < n; offset += h) {
    c[offset / h] = s[offset][0];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[offset][0] != s[offset + i][j]) {
          return false;
        }
      }
    }
  }
  return c[0] != c[1] && c[0] != c[2] && c[1] != c[2];
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  Grid s(n, std::vector<char>(m + 1)), ts(m, std::vector<char>(n + 1));
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i].data());
    for (int j = 0; j < m; ++j) {
      ts[j][i] = s[i][j];
    }
  }
  puts(check(n, m, s) || check(m, n, ts) ? "YES" : "NO");
}