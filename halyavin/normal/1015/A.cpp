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
    int n, m;
    in >> n >> m;
    std::vector<bool> flags(m);
    for (int i = 0; i < n; i++) {
        int l, r;
        in >> l >> r;
        l--;
        std::fill(flags.begin() + l, flags.begin() + r, true);
    }
    int all = 0;
    for (int i = 0; i < m; i++) {
        if (!flags[i]) all++;
    }
    out << all << "\n";
    for (int i = 0; i < m; i++) {
        if (!flags[i]) {
            out << (i + 1) << " ";
        }
    }
    out << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}