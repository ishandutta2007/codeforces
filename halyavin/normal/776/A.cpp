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

void run(std::istream &in, std::ostream &out) {
  std::string a, b;
  in >> a >> b;
  int n;
  in >> n;
  out << a << " " << b << std::endl;
  for (int i = 0; i < n; i++) {
    std::string murdered, replaced;
    in >> murdered >> replaced;
    if (murdered == a) {
      a = replaced;
    } else {
      b = replaced;
    }
    out << a << " " << b << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}