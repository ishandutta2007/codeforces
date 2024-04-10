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
#include <set>

std::pair<int, int> digits[] = {{3,1},{0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::string s;
  in >> s;
  std::vector<std::pair<int, int>> cells(n);
  for (int i = 0; i < n; i++) {
    cells[i] = digits[s[i] - '0'];
  }
  std::set<std::pair<int, int>> correctSet;
  for (int i = 0; i <= 9; i++) {
    correctSet.insert(digits[i]);
  }
  for (int dx = -3; dx <= 3; dx++) {
    for (int dy = -3; dy <= 3; dy++) {
      if (dx == 0 && dy == 0) continue;
      bool good = false;
      for (int i = 0; i < n; i++) {
        if (correctSet.count(std::make_pair(dx + cells[i].first, dy + cells[i].second)) == 0) {
          good = true;
        }
      }
      if (!good) {
        out << "NO" << std::endl;
        return;
      }
    }
  }
  out << "YES" << std::endl;
  return;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}