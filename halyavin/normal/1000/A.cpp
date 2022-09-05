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
#include <map>

void run(std::istream &in, std::ostream &out) {
    std::map<std::string, int> idx;
    idx.emplace("M", 0);
    idx.emplace("S", 1);
    idx.emplace("L", 2);
    idx.emplace("XS", 3);
    idx.emplace("XL", 4);
    idx.emplace("XXS", 5);
    idx.emplace("XXL", 6);
    idx.emplace("XXXS", 7);
    idx.emplace("XXXL", 8);
    int n;
    in >> n;
    std::array<int, 9> before = {};
    std::array<int, 9> after = {};
    for (int i = 0; i < n; i++) {
        std::string s;
        in >> s;
        before[idx[s]]++;
    }
    for (int i = 0; i < n; i++) {
        std::string s;
        in >> s;
        after[idx[s]]++;
    }
    int changes = 0;
    int all = before[0] + before[1] + before[2];
    int good = std::min(before[0], after[0]) + std::min(before[1], after[1]) + std::min(before[2], after[2]);
    changes += all - good;
    for (int i = 0; i < 3; i++) {
        all = before[3 + 2 * i] + before[4 + 2 * i];
        good = std::min(before[3 + 2 * i], after[3 + 2 * i]) + std::min(before[4 + 2 * i], after[4 + 2 * i]);
        changes += all - good;
    }
    std::cout << changes << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}