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
    int n, k;
    in >> n >> k;
    std::vector<int> as(n);
    int min = k;
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    for (int i = 0; i < n; i++) {
        if (k % as[i] == 0) {
            min = std::min(min, k / as[i]);
        }
    }
    out << min << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}