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
#include <map>
#include <array>

void run(std::istream& in, std::ostream& out) {
  std::array<std::map<int, int>, 27> stat;
  int q;
  in >> q;
  for (int i = 0; i < q; i++) {
    int t, p;
    in >> t >> p;
    if (t == 1) {
      for (auto& statLevel : stat) {
        statLevel[p]++;
        p /= 2;
      }
    } else if (t == 2) {
      for (auto& statLevel : stat) {
        statLevel[p]--;
        p /= 2;
      }
    } else {
      int l;
      in >> l;
      int res = 0;
      for (size_t level = 0; level < stat.size(); level++) {
        if ((l & 1) != 0) {
          res += stat[level][p ^ (l - 1)];
        }
        p /= 2;
        l /= 2;
      }
      out << res << std::endl;
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}