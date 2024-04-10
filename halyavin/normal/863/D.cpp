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
    int n, q, m;
    in >> n >> q >> m;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    std::vector<std::vector<int>> ops;
    for (int i = 0; i < q; i++) {
        int t, l, r;
        in >> t >> l >> r;
        l--;
        ops.emplace_back(std::vector<int>{t, l, r});
    }
    std::reverse(ops.begin(), ops.end());
    for (int i = 0; i < m; i++) {
        int b;
        in >> b;
        b--;
        for (auto& op : ops) {
            if (op[0] == 1) {
                if (b >= op[1] && b < op[2]) {
                    if (b == op[1]) {
                        b = op[2];
                    }
                    b--;
                }
            } else {
                if (b >= op[1] && b < op[2]) {
                    b = op[1] + op[2] - b - 1;
                }
            }
        }
        out << as[b] << " ";
    }
    out << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}