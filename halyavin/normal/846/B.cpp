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
    int n, k, M;
    in >> n >> k >> M;
    std::vector<int> times(k);
    for (int i = 0; i < k; i++) {
        in >> times[i];
    }
    std::sort(times.begin(), times.end());
    int sum = std::accumulate(times.begin(), times.end(), 0);
    int ans = 0;
    for (int full = 0; full <= n; full++) {
        int t = M - full * sum;
        if (t < 0) break;
        int res = full * (k + 1);
        for (int i = 0; i < k; i++) {
            int d = std::min(n - full, t / times[i]);
            res += d;
            t -= d * times[i];

        }
        ans = std::max(ans, res);
    }
    std::cout << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}