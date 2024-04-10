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
    int n, m;
    in >> n >> m;
    std::vector<int> seq(m);
    for (int i = 0; i < m; i++) {
        in >> seq[i];
        seq[i]--;
    }
    std::vector<int> perm(n, -1);
    for (int i = 0; i + 1 < m; i++) {
        int v = (seq[i + 1] - seq[i] + n - 1) % n;
        if (perm[seq[i]] == -1 || perm[seq[i]] == v) {
            perm[seq[i]] = v;
        } else {
            out << -1 << std::endl;
            return;
        }
    }
    std::vector<bool> flags(n);
    for (int i = 0; i < n; i++) {
        if (perm[i] >= 0) {
            if (flags[perm[i]]) {
                out << -1 << std::endl;
                return;
            }
            flags[perm[i]] = true;
        }
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (perm[i] < 0) {
            while (flags[cur]) cur++;
            perm[i] = cur;
            flags[cur] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        out << perm[i] + 1 << " ";
    }
    out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}