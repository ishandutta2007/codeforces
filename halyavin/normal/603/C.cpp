#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,lzcnt,bmi,fma,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
  int n, k;
  in >> n >> k;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    in >> a;
    if (k % 2 == 0) {
      if (a == 1) {
        ans ^= 1;
      } else if (a == 2) {
        ans ^= 2;
      } else if (a % 2 == 0) {
        ans ^= 1;
      }
    } else {
      while (true) {
        if (a >= 5 && a % 2 != 0) {
          break;
        }
        if (a == 0 || a == 2) {
          break;
        }
        if (a == 1 || a== 3) {
          ans ^= 1;
          break;
        }
        if (a == 4 || a == 6) {
          ans ^= 2;
          break;
        }
        if ((a / 2) % 2 != 0) {
          ans ^= 1;
          break;
        }
        ans ^= 3;
        a /= 2;
      }
    }
  }
  if (ans == 0) {
    out << "Nicky" << std::endl;
  } else {
    out << "Kevin" << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}