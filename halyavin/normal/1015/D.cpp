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
    int64_t n, k, s;
    in >> n >> k >> s;
    if (s < k) {
        out << "NO\n";
        return;
    }
    int64_t step = s / k;
    int64_t max = step;
    if (s % k != 0) max++;
    if (max >= n) {
        out << "NO\n";
        return;
    }
    out << "YES\n";
    int cur = 1;
    int dir = 1;
    for (int i = 0; i < k; i++) {
        if (i < s % k) {
            cur += dir * (step + 1);
        } else {
            cur += dir * step;
        }
        dir = -dir;
        out << cur << " ";
    }
    out << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}