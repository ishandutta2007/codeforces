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

void run(std::istream &in, std::ostream &out) {
  std::vector<std::array<int, 4>> combs;
  for (int i1 = 0; i1 <= 9; i1++) {
    for (int i2 = 0; i2 <= 9; i2++) {
      if (i2 != i1) {
        for (int i3 = 0; i3 <= 9; i3++) {
          if (i3 != i1 && i3 != i2) {
            for (int i4 = 0; i4 <= 9; i4++) {
              if (i4 != i3 && i4 != i2 && i4 != i1) {
                combs.push_back(std::array<int, 4>{i1, i2, i3, i4});
              }
            }
          }
        }
      }
    }
  }
  {
    out << "0000" << std::endl;
    out.flush();
    int c1, c2;
    in >> c1 >> c2;
    if (c1 == 4) return;
  }

  while (true) {
    std::array<int, 4> guess = combs[0];
    for (size_t i = 0; i < guess.size(); i++) {
      out << guess[i];
    }
    out << std::endl;
    out.flush();
    int c1, c2;
    in >> c1 >> c2;
    if (c1 == 4) return;

    auto it = std::partition(combs.begin(), combs.end(), [&guess, c1, c2](const std::array<int, 4>& variant){
      int real1 = 0, real2 = 0;
      for (int i = 0; i < 4; i++) {
        if (variant[i] == guess[i]) real1++;
      }
      if (real1 != c1) {
        return false;
      }
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          if (variant[i] == guess[j] && i != j) real2++;
        }
      }
      return real2 == c2;
    });
    combs.erase(it, combs.end());
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}