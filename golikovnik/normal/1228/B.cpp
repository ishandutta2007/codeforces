#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int h, w;
  std::cin >> h >> w;
  std::vector<int> r(h), c(w);
  for (auto& x : r) {
    std::cin >> x;
  }
  for (auto& x : c) {
    std::cin >> x;
  }
  std::vector<std::vector<int>> color(h, std::vector<int>(w, -1));
  for (int row = 0; row != h; ++row) {
    for (int col = 0; col < r[row]; ++col) {
      color[row][col] = 0;
    }
    if (r[row] != w) {
      color[row][r[row]] = 1;
    }
  }
  uint32_t ways = 1;
  uint32_t constexpr MOD = 1e9 + 7;
  for (int col = 0; col != w; ++col) {
    for (int row = 0; row < c[col]; ++row) {
      if (color[row][col] == 1) {
        ways = 0;
        break;
      }
      color[row][col] = 0;
    }
    if (c[col] != h) {
      if (color[c[col]][col] == 0) {
        ways = 0;
        break;
      }
      color[c[col]][col] = 1;
    }
  }
  for (int row = 0; row < h; ++row) {
    for (int col = 0; col < w; ++col) {
      if (color[row][col] < 0) {
        ways *= 2;
        ways %= MOD;
      }
    }
  }
  std::cout << ways << '\n';
  return 0;
}