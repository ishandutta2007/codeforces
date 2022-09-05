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
  int n;
  in >> n;
  int ca = 0;
  int cb = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    in >> x >> y;
    if (x > y) ca++;
    if (y > x) cb++;
  }
  if (ca > cb) {
    out << "Mishka" << std::endl;
  } else if (ca < cb) {
    out << "Chris" << std::endl;
  } else {
    out << "Friendship is magic!^^" << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}