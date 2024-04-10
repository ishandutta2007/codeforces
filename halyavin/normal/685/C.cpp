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

const int64_t inf = (1LL << 62) - 1LL;

bool check(std::array<int64_t, 8>& bounds, std::array<int64_t, 3>& example) {
  for (int i = 0; i < 4; i++) {
    if (bounds[i] + bounds[7 - i] < 0) {
      return false;
    }
  }
  int64_t critX1 = -(bounds[4] + bounds[7]);
  int64_t critX2 = (bounds[0] + bounds[3]);
  if (critX1 & 1) critX1++;
  if (critX2 & 1) critX2--;
  critX1 /= 2;
  critX2 /= 2;
  if (critX1 > critX2) {
    return false;
  }
  int64_t bound1 = std::min(bounds[0] - critX1, bounds[4] + critX1);
  int64_t bound2 = std::min(bounds[3] - critX1, bounds[7] + critX1);
  if (bound1 < -bound2) {
    return false;
  }
  bound1 = std::min(bounds[0] - critX2, bounds[4] + critX2);
  bound2 = std::min(bounds[3] - critX2, bounds[7] + critX2);
  if (bound1 < -bound2) {
    return false;
  }

  int64_t critX3 = -(bounds[5] + bounds[6]);
  int64_t critX4 = (bounds[1] + bounds[2]);
  if (critX3 & 1) critX3++;
  if (critX4 & 1) critX4--;
  critX3 /= 2;
  critX4 /= 2;
  if (critX3 > critX4) {
    return false;
  }
  bound1 = std::min(bounds[1] - critX3, bounds[5] + critX3);
  bound2 = std::min(bounds[2] - critX3, bounds[6] + critX3);
  if (bound1 < -bound2) {
    return false;
  }
  bound1 = std::min(bounds[1] - critX4, bounds[5] + critX4);
  bound2 = std::min(bounds[2] - critX4, bounds[6] + critX4);
  if (bound1 < -bound2) {
    return false;
  }
  int64_t critXMin = std::max(critX3, critX1);
  int64_t critXMax = std::min(critX2, critX4);
  if (critXMin > critXMax) {
    return false;
  }
  int64_t& x = example[0];
  int64_t& y = example[1];
  int64_t& z = example[2];
  x = critXMin;
  int64_t yz0 = std::min(bounds[0] - x, bounds[4] + x);
  int64_t yz1 = std::min(bounds[1] - x, bounds[5] + x);
  int64_t yz2 = std::min(bounds[2] - x, bounds[6] + x);
  int64_t yz3 = std::min(bounds[3] - x, bounds[7] + x);
  if (yz0 == -yz3 && yz1 == -yz2) {
    if ((yz0 & 1) != (yz1 & 1)) {
      if (x == critXMax) {
        return false;
      }
      x++;
      yz0 = std::min(bounds[0] - x, bounds[4] + x);
      yz1 = std::min(bounds[1] - x, bounds[5] + x);
      yz2 = std::min(bounds[2] - x, bounds[6] + x);
      yz3 = std::min(bounds[3] - x, bounds[7] + x);
    }
  }
  int64_t critY = yz0 + yz1;
  if (critY & 1) critY--;
  y = critY / 2;
  z = std::min(yz0 - y, yz2 + y);
  return true;
}

void run(std::istream& in, std::ostream& out) {
  int t;
  in >> t;
  for (int test = 0; test < t; test++) {
    int n;
    in >> n;
    std::array<int64_t, 8> bounds;
    std::fill(bounds.begin(), bounds.end(), inf);
    for (int i = 0; i < n; i++) {
      int64_t x, y, z;
      in >> x >> y >> z;
      bounds[0] = std::min(bounds[0], x + y + z);
      bounds[1] = std::min(bounds[1], x + y - z);
      bounds[2] = std::min(bounds[2], x - y + z);
      bounds[3] = std::min(bounds[3], x - y - z);

      bounds[4] = std::min(bounds[4], -x + y + z);
      bounds[5] = std::min(bounds[5], -x + y - z);
      bounds[6] = std::min(bounds[6], -x - y + z);
      bounds[7] = std::min(bounds[7], -x - y - z);
    }
    int64_t left = -1;
    int64_t right = inf;
    std::array<int64_t, 3> res = {};
    while (right - left > 1) {
      int64_t middle = (left + right) / 2;
      std::array<int64_t, 8> bounds2 = bounds;
      for (size_t i = 0; i < 8; i++) {
        bounds2[i] += middle;
      }
      if (check(bounds2, res)) {
        right = middle;
      } else {
        left = middle;
      }
    }
    out << res[0] << " " << res[1] << " " << res[2] << "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}