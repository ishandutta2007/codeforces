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
  int A, B, C;
  in >> A >> B >> C;
  out.precision(20);
  if (A == 0) {
    if (B == 0) {
      if (C == 0) {
        out << -1 << std::endl;
        return;
      }
      out << 0 << std::endl;
      return;
    }
    out << 1 << std::endl;
    out << (double) -C / B << std::endl;
    return;
  }
  int64_t D = int64_t(B) * B - int64_t(A) * C * 4;
  if (D < 0) {
    out << 0 << std::endl;
    return;
  }
  if (D == 0) {
    out << 1 << std::endl;
    out << -(double) B / (2 * A) << std::endl;
    return;
  }
  out << 2 << std::endl;
  double x1 = (-(double) B - sqrt(D)) / (2 * A);
  double x2 = (-(double) B + sqrt(D)) / (2 * A);
  if (x1 > x2) std::swap(x1, x2);
  out << x1 << std::endl;
  out << x2 << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}