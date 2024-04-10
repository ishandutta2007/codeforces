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
#include <array>

struct Solution {
    int n, k;

    std::array<std::vector<int>, 2> dyn;

    void calcDyn() {
        dyn[0].assign(n + 1, 0);
        dyn[1].assign(n + 1, 0);
        dyn[0][1] = 1;
        dyn[1][1] = 1;
        for (int len = 2; len <= n; len++) {
            for (int l = 0; l < 2; l++) {
                int r = l + len;
                int m = (l + r) / 2;
                dyn[l][len] = dyn[l][m - l] + dyn[m & 1][r - m] + 1;
            }
        }
    }

    void build(int k, int l, int r, int from, std::vector<int>& ans) {
        if (k == 1) {
            for (int i = l; i < r; i++) {
                ans[i] = from + (i - l);
            }
            return;
        }
        k--;
        int m = (r + l) / 2;
        int leftK = dyn[l & 1][m - l];
        leftK = std::min(k - 1, leftK);
        int rightK = k - leftK;
        build(leftK, l, m, from + (r - m), ans);
        build(rightK, m, r, from, ans);
    }

    void run(std::istream& in, std::ostream& out) {
        in >> n >> k;
        calcDyn();
        if (k > dyn[0][n] || k % 2 == 0) {
            out << -1 << std::endl;
            return;
        }
        std::vector<int> ans(n);
        build(k, 0, n, 1, ans);
        for (int i = 0; i < n; i++) {
            out << ans[i] << " ";
        }
        out << std::endl;
    }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}