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
    int n, t;
    in >> n >> t;
    for (int i = 0; i < n; i++) {
        int a;
        in >> a;
        a = 86400 - a;
        t -= a;
        if (t <= 0) {
            out << i + 1 << std::endl;
            return;
        }
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}