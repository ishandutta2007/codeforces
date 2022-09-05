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
    int k1, k2, k3;
    in >> k1 >> k2 >> k3;
    if (k1 == 1 || k2 == 1 || k3 == 1) {
        out << "YES\n";
        return;
    }
    for (int off1 = 0; off1 < 10; off1++) {
        for (int off2 = 0; off2 < 10; off2++) {
            for (int off3 = 0; off3 < 10; off3++) {
                bool good = true;
                for (int i = 0; i < 60; i++) {
                    if (i % k1 != off1 && i % k2 != off2 && i % k3 != off3) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    out << "YES\n";
                    return;
                }
            }
        }
    }
    out << "NO\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}