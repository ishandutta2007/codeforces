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

struct ipoint {
  int x, y;

  ipoint() : x(0), y(0) { }

  ipoint(int x, int y) : x(x), y(y) { }
};

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  int64_t index;
  in >> index;
  ipoint m;
  in >> m.x >> m.y;
  std::vector<ipoint> points(n);
  for (int i = 0; i < n; i++) {
    in >> points[i].x >> points[i].y;
  }
  index %= 2 * n;
  for (int i = 0; i < index; i++) {
    m.x = points[i % n].x * 2 - m.x;
    m.y = points[i % n].y * 2 - m.y;
  }
  out << m.x << " " << m.y << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}