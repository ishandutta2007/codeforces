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
  std::vector<std::pair<int, int>> beacons(n);
  for (int i = 0; i < n; i++) {
    in >> beacons[i].first >> beacons[i].second;
  }
  std::sort(beacons.begin(), beacons.end());
  std::vector<int> dyn(n);
  int max_value = 1;
  for (int i = 0; i < n; i++) {
    int before = beacons[i].first - beacons[i].second;
    auto it = std::lower_bound(beacons.begin(), beacons.end(), std::pair<int, int>(before, 0));
    int ind = std::distance(beacons.begin(), it) - 1;
    if (ind < 0) {
      dyn[i] = 1;
    } else {
      dyn[i] = dyn[ind] + 1;
      max_value = std::max(max_value, dyn[i]);
    }
  }
  out << (n - max_value) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}