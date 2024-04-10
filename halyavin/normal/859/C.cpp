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
    std::vector<int> slices(n);
    for (int i = 0; i < n; i++) {
        in >> slices[i];
    }
    std::vector<int> dyn1(n);
    std::vector<int> dyn2(n);
    dyn1[n - 1] = slices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        dyn1[i] = std::max(slices[i] + dyn2[i + 1], dyn1[i + 1]);
        dyn2[i] = dyn1[i + 1] + dyn2[i + 1] + slices[i] - dyn1[i];
    }
    out << dyn2[0] << " " << dyn1[0] << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}