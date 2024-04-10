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
  int n, m;
  in >> n >> m;
  std::vector<int> cities(n);
  std::vector<int> towers(m);
  for (int i = 0; i < n; i++) {
    in >> cities[i];
  }
  for (int i = 0; i < m; i++) {
    in >> towers[i];
  }
  int ans = 0;
  int curTower = 0;
  for (int i = 0; i < n; i++) {
    while (curTower + 1 < m && std::abs(cities[i] - towers[curTower]) >= std::abs(cities[i] - towers[curTower + 1])) {
      curTower++;
    }
    ans = std::max(ans, std::abs(cities[i] - towers[curTower]));
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}