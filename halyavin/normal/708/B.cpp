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

int64_t getDist(int64_t x) {
  int64_t left = 0;
  int64_t right = x + 2;
  while (right - left > 1) {
    int64_t middle = (left + right) / 2;
    if (middle * (middle - 1) / 2 > x) {
      right = middle;
    } else {
      left = middle;
    }
  }
  if (left * (left - 1) / 2 == x) {
    return left;
  }
  return -1;
}

void run(std::istream &in, std::ostream &out) {
  int64_t a00, a01, a10, a11;
  in >> a00 >> a01 >> a10 >> a11;
  int64_t sum = a00 + a01 + a10 + a11;
  int64_t n = getDist(sum);
  if (n < 0) {
    out << "Impossible" << std::endl;
    return;
  }
  int64_t a0 = getDist(a00);
  if (a0 < 0) {
    out << "Impossible" << std::endl;
    return;
  }
  int64_t a1 = getDist(a11);
  if (a1 < 0) {
    out << "Impossible" << std::endl;
    return;
  }
  if (a0 == 1) {
    int64_t len = a10 + a01;
    if (a11 == len * (len - 1) / 2) {
      std::string s;
      s.append(a10, '1');
      s.append(1, '0');
      s.append(a01, '1');
      out << s << std::endl;
      return;
    }
    if (a10 == 0 && a01 == 0) {
      std::string s;
      s.append(a1, '1');
      out << s << std::endl;
      return;
    }
    out << "Impossible" << std::endl;
    return;
  }
  if (a1 == 1) {
    int len = a01 + a10;
    if (a00 == len * (len - 1) / 2) {
      std::string s;
      s.append(a01, '0');
      s.append(1, '1');
      s.append(a10, '0');
      out << s << std::endl;
      return;
    }
    if (a10 == 0 && a01 == 0) {
      std::string s;
      s.append(a0, '0');
      out << s << std::endl;
      return;
    }
    out << "Impossible" << std::endl;
    return;
  }
  if (a0 + a1 != n) {
    out << "Impossible" << std::endl;
    return;
  }
  if (a01 + a10 != a0 * a1) {
    out << "Impossible" << std::endl;
    return;
  }
  std::string s;
  int r = a01 / a1;
  int t = a01 % a1;
  s.append(r, '0');
  if (t != 0) {
    s.append(a1 - t, '1');
    s.append(1, '0');
    s.append(t, '1');
    s.append(a0 - r - 1, '0');
  } else {
    s.append(a1, '1');
    s.append(a0 - r, '0');
  }
  out << s << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}