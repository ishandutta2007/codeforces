#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream& in, std::ostream& out) {
  int n, m, a, b, c;
  in >> n >> m >> a >> b >> c;
  if (n % 2 != 0 && m % 2 != 0) {
    out << "IMPOSSIBLE" << std::endl;
    return;
  }
  std::vector<std::vector<char>> res(n, std::vector<char>(m));
  if (m % 2 != 0) {
    if (b < n / 2) {
      out << "IMPOSSIBLE" << std::endl;
      return;
    }
    for (int i = 0; i < n / 2; i++) {
      res[2 * i][m - 1] = 'a' + (i & 1);
      res[2 * i + 1][m - 1] = 'a' + (i & 1);
    }
    b -= n / 2;
    m--;
  }
  if (n % 2 != 0) {
    if (a < m / 2) {
      out << "IMPOSSIBLE" << std::endl;
      return;
    }
    for (int i = 0; i < m / 2; i++) {
      res[n - 1][2 * i] = 'a' + (i & 1);
      res[n - 1][2 * i + 1] = 'a' + (i & 1);
    }
    a -= m / 2;
    n--;
  }
  a /= 2;
  b /= 2;
  int squares = (n / 2) * (m / 2);
  if (squares > a + b + c) {
    out << "IMPOSSIBLE" << std::endl;
    return;
  }
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < m / 2; j++) {
      int off = (i + j) & 1;
      if (a > 0) {
        res[2 * i][2 * j] = 'c' + off;
        res[2 * i][2 * j + 1] = 'c' + off;
        res[2 * i + 1][2 * j] = 'e' + off;
        res[2 * i + 1][2 * j + 1] = 'e' + off;
        a--;
      } else if (b > 0) {
        res[2 * i][2 * j] = 'c' + off;
        res[2 * i][2 * j + 1] = 'e' + off;
        res[2 * i + 1][2 * j] = 'c' + off;
        res[2 * i + 1][2 * j + 1] = 'e' + off;
        b--;
      } else {
        res[2 * i][2 * j] = 'c' + off;
        res[2 * i][2 * j + 1] = 'c' + off;
        res[2 * i + 1][2 * j] = 'c' + off;
        res[2 * i + 1][2 * j + 1] = 'c' + off;
        c--;
      }
    }
  }
  for (size_t i = 0; i < res.size(); i++) {
    for (size_t j = 0; j < res[i].size(); j++) {
      out << res[i][j];
    }
    out << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}