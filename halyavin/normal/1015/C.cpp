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
    int64_t m;
    in >> m;
    int64_t sum = 0;
    std::vector<int64_t> diffs;
    for (int i = 0; i < n; i++) {
        int64_t a, b;
        in >> a >> b;
        sum += a;
        diffs.push_back(a - b);
    }
    std::sort(diffs.begin(), diffs.end(), std::greater<>());
    int ans = 0;
    while (ans < n && sum > m) {
        sum -= diffs[ans];
        ans++;
    }
    if (sum <= m) {
        out << ans << "\n";
    } else {
        out << -1 << "\n";
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}