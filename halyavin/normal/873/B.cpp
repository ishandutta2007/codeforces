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
    size_t n;
    in >> n;
    std::string s;
    in >> s;
    std::vector<int> prev(2 * n + 1, -1);
    size_t cur = n;
    int ans = 0;
    prev[cur] = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            cur++;
        } else {
            cur--;
        }
        if (prev[cur] != -1) {
            ans = std::max(ans, i + 1 - prev[cur]);
        } else {
            prev[cur] = i + 1;
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