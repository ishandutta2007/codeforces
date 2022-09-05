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
#include <queue>

struct Solution {
    void run(std::istream& in, std::ostream& out) {
        int N;
        in >> N;
        std::priority_queue<int, std::vector<int>, std::greater<int>> zeros;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pluses;
        int64_t ans = 0;
        zeros.push(10000000);
        pluses.push(10000000);
        for (int i = 0; i < N; i++) {
            int x;
            in >> x;
            int mz = zeros.top();
            int pz = pluses.top();
            if (x < std::min(mz, pz)) {
                zeros.push(x);
                continue;
            }
            if (mz < pz) {
                ans += x - mz;
                pluses.push(x);
                zeros.pop();
            } else {
                ans += x - pz;
                zeros.push(pz);
                pluses.pop();
                pluses.push(x);
            }
        }
        out << ans << std::endl;
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}