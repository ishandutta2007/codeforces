#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream &in, std::ostream &out) {
    int t;
    in >> t;
    for (int test = 0; test < t; test++) {
        int64_t n, x, y, d;
        in >> n >> x >> y >> d;
        int64_t ans = int64_t(1) << 60;
        if (std::abs(y - x) % d == 0) {
            ans = std::abs(y - x) / d;
        }
        int64_t left = (x + d - 2)/ d;
        if (std::abs(y - 1) % d == 0) {
            ans = std::min(ans, left + std::abs(y - 1)  / d);
        }
        int64_t right = (n - x + d - 1) / d;
        if (std::abs(n - y) % d == 0) {
            ans = std::min(ans, right + std::abs(n - y) / d);
        }
        if (ans == (int64_t(1) << 60)) {
            ans = -1;
        }
        out << ans << "\n";
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}