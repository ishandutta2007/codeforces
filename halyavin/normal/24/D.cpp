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

void createSystem(std::vector<double>& a, std::vector<double>& b, std::vector<double>& c, int m) {
  b[0] = 2.0/3.0;
  c[0] = -1.0/3.0;
  double p = 1.0 / 4.0;
  for (int i = 1; i < m - 1; i++) {
    b[i] = 1.0 - p;
    a[i] = -p;
    c[i] = -p;
  }
  b[m - 1] = 2.0/3.0;
  a[m - 1] = -1.0/3.0;
}

void solveSystem(std::vector<double>& a, std::vector<double>& b, std::vector<double>& c, std::vector<double>& d,
                 int m) {
  for (int i = 0; i < m - 1; i++) {
    double coeff = a[i + 1] / b[i];
    a[i + 1] = 0;
    b[i + 1] -= coeff * c[i];
    d[i + 1] -= coeff * d[i];
  }
  for (int i = m - 1; i > 0; i--) {
    d[i] /= b[i];
    d[i - 1] -= c[i - 1] * d[i];
  }
  d[0] /= b[0];
}

void run(std::istream& in, std::ostream& out) {
  int n, m;
  in >> n >> m;
  int i, j;
  in >> i >> j;
  i--;
  j--;
  int rows = n - i - 1;
  out.precision(10);
  out << std::fixed;
  if (rows == 0) {
    out << 0.0 << std::endl;
    return;
  }
  if (m == 1) {
    out << rows * 2 << std::endl;
    return;
  }
  std::vector<double> a(m), b(m), c(m), d(m, 1);
  std::vector<double> cur(m, 0);
  for (int i = 0; i < rows; i++) {
    createSystem(a, b, c, m);
    d[0] = 1.0 + cur[0] / 3;
    d[m - 1] = 1.0 + cur[m - 1] / 3;
    for (int i = 1; i < m - 1; i++) {
      d[i] = 1.0 + cur[i] / 4.0;
    }
    solveSystem(a, b, c, d, m);
    cur = d;
  }
  out << cur[j] << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}