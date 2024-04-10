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
#include <cmath>

bool isSquare(int x) {
    if (x < 0) return false;
    int y = (int)floor(sqrt((double)x));
    return y * y == x || (y + 1) * (y + 1) == x || (y - 1) * (y - 1) == x;
}

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    int ans = -1000000;
    for (int i = 0; i < n; i++) {
        int x;
        in >> x;
        if (!isSquare(x)) {
            ans = std::max(ans, x);
        }
    }
    out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}