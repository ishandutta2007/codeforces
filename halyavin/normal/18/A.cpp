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
#include <array>

struct ipoint {
  int x,y;
  ipoint() : x(0), y(0) {}
  ipoint(int x, int y) : x(x), y(y) {}
};

bool isRight(std::array<ipoint, 3>& ps) {
  std::array<int, 3> d2;
  for (int i = 0; i < 3; i++) {
    int j = (i + 1) % 3;
    d2[i] = (ps[j].x - ps[i].x) * (ps[j].x - ps[i].x) + (ps[j].y - ps[i].y) * (ps[j].y - ps[i].y);
    if (d2[i] == 0) {
      return false;
    }
  }
  for (int i = 0; i < 3; i++) {
    int ni = (i + 1) % 3;
    int ni2 = (i + 2) % 3;
    if (d2[i] == d2[ni] + d2[ni2]) {
      return true;
    }
  }
  return false;
}
void run(std::istream &in, std::ostream &out) {
  std::array<ipoint, 3> ps;
  for (int i = 0; i < 3; i++) {
    in >> ps[i].x >> ps[i].y;
  }
  if (isRight(ps)) {
    out << "RIGHT" << std::endl;
    return;
  }
  const int dx[4] = {-1, 1, 0, 0};
  const int dy[4] = {0, 0, -1, 1};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      ps[i].x += dx[j];
      ps[i].y += dy[j];
      if (isRight(ps)) {
        out << "ALMOST" << std::endl;
        return;
      }
      ps[i].x -= dx[j];
      ps[i].y -= dy[j];
    }
  }
  out << "NEITHER" << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}