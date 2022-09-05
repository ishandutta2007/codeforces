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
    std::vector<int> res(n);
    for (int i = 0; i < n; i++) {
        in >> res[i];
    }
    std::vector<int> zeros(n + 1);
    for (int i = 1; i <= n ;i++) {
        zeros[i] = zeros[i - 1] + ((res[i - 1] == 0) ? 1 : 0);
    }
    std::vector<int> ones(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        ones[i] = ones[i + 1] + ((res[i] == 1) ? 1 : 0);
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = std::max(ans, zeros[i] + ones[i]);
    }
    out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}