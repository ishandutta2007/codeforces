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
    int n;
    in >> n;
    std::array<int, 100001> stat = {};
    for (int i = 0; i < n; i++) {
        int a;
        in >> a;
        stat[a]++;
    }
    for (size_t i = 0; i < stat.size(); i++) {
        if (stat[i] & 1) {
            out << "Conan\n";
            return;
        }
    }
    out << "Agasa\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}