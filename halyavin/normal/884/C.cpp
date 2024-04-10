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
    std::vector<int> perm(n);
    for (int i = 0; i < n; i++) {
        in >> perm[i];
        perm[i]--;
    }
    std::vector<int> cycles;
    std::vector<bool> flags(n);
    for (int i = 0; i < n; i++) {
        if (!flags[i]) {
            int j = i;
            int len = 0;
            while (!flags[j]) {
                flags[j] = true;
                len++;
                j = perm[j];
            }
            cycles.push_back(len);
        }
    }
    std::sort(cycles.begin(), cycles.end(), std::greater<int>());
    if (cycles.size() == 1) {
        out << uint64_t(cycles[0]) * uint64_t(cycles[0]) << std::endl;
    } else {
        uint64_t answer = uint64_t(cycles[0] + cycles[1])*uint64_t(cycles[0] + cycles[1]);
        for (size_t i = 2; i < cycles.size(); i++) {
            answer += uint64_t(cycles[i]) * uint64_t(cycles[i]);
        }
        out << answer << std::endl;
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}