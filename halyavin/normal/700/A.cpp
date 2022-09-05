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

bool canReach(int n, int l, int v1, int v2, int k, double t) {
  if (t >= l / (double)v1) {
    return true;
  }
  double dist = l;
  double time = 0;
  while (n > 0) {
    if (n <= k) {
      time += dist / v2;
      return time <= t;
    }
    n -= k;
    if (time + dist / v2 > t) {
      return false;
    }
    double dt = (dist - (t - time) * v1) / (v2 - v1);
    double dt2 = dt + (dt * (v2 - v1)) / (v1 + v2);
    time += dt2;
    dist -= dt2 * v1;
    if (time > t) {
      return false;
    }
  }
  return true;
}

void run(std::istream &in, std::ostream &out) {
  int n, l, v1, v2, k;
  in >> n >> l >> v1 >> v2 >> k;
  double left = 0;
  double right = l / (double)v1;
  while (true) {
    double middle = (left + right) / 2;
    if (middle <= left || middle >= right) break;
    if (canReach(n, l, v1, v2, k, middle)) {
      right = middle;
    } else {
      left = middle;
    }
  }
  out.precision(12);
  out << right << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}