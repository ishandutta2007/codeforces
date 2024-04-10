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
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
        as[i]--;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (as[j] < as[i]) {
                res ^=1;
            }
        }
    }
    int m;
    in >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        in >> l >> r;
        int d = r - l + 1;
        res ^= (d / 2) & 1;
        if (res) {
            out << "odd\n";
        } else {
            out << "even\n";
        }
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}