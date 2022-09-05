#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <array>

constexpr std::array<int, 4> data = {0, 1, 2, 9};

void run(std::istream &in, std::ostream &out) {
    int n, k;
    in >> n >> k;
    int64_t c = 1;
    int64_t ans = 1;
    for (int i = 1; i <= k; i++) {
        c *= n - i + 1;
        c /= i;
        ans += c * data[i - 1];
    }
    out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}