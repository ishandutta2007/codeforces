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
    int min = n + 1;
    for (int i = 2; i * i <= n ;i++) {
        int v = i + (n + i - 1) / i;
        min = std::min(min, v);
    }
    out << 2 * min << "\n";

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}