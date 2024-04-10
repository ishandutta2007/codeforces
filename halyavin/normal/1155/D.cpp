#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

struct Solution {
    int x;
    int n;
    std::vector<int64_t> as;
    std::vector<int64_t> sum;
    std::array<std::vector<int64_t>, 4> dyn;
    void run(std::istream& in, std::ostream& out) {
        in >> n >> x;
        as.resize(n);
        for (int i = 0; i < n; i++) {
            in >> as[i];
        }
        sum.resize(n + 1);
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + as[i - 1];
        }
        if (x > 0) {
            int64_t minSum = 0;
            int64_t ans = 0;
            for (int i = 1; i <= n; i++) {
                minSum = std::min(minSum, sum[i]);
                ans = std::max(sum[i] - minSum, ans);
            }
            out << ans * x << "\n";
            return;
        }
        int m = (1 - x);
        dyn[0].resize(n + 1);
        dyn[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            dyn[0][i] = std::max(dyn[0][i - 1], -sum[i]);
        }
        dyn[1].resize(n + 1);
        dyn[1][0] = 0;
        for (int i = 1; i <= n; i++) {
            dyn[1][i] = std::max(dyn[1][i - 1], sum[i] * m + dyn[0][i]);
        }
        dyn[2].resize(n + 1);
        dyn[2][0] = 0;
        for (int i = 1; i <= n; i++) {
            dyn[2][i] = std::max(dyn[2][i - 1], -sum[i] * m + dyn[1][i]);
        }
        dyn[3].resize(n + 1);
        dyn[3][0] = 0;
        for (int i = 1; i <= n; i++) {
            dyn[3][i] = std::max(dyn[3][i -1], sum[i] + dyn[2][i]);
        }
        out << dyn[3][n] << "\n";
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}