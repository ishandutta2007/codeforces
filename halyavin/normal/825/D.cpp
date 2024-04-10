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

void run(std::istream &in, std::ostream &out) {
    std::string s, t;
    in >> s >> t;
    std::array<int, 26> statT = {};
    for (char c : t) {
        statT[c - 'a']++;
    }
    std::array<int, 26> statS = {};
    int empty = 0;
    for (char c : s) {
        if (c == '?') {
            empty++;
        } else {
            statS[c - 'a']++;
        }
    }
    int k;
    for (k = 1; ; k++) {
        int res = 0;
        for (int i = 0; i < 26; i++) {
            res += std::max(statT[i] * k - statS[i], 0);
        }
        if (res > empty) {
            k--;
            break;
        }
    }
    std::string res;
    for (int i = 0; i < 26; i++) {
        int d = std::max(statT[i] * k - statS[i], 0);
        res.append(d, 'a' + i);
    }
    size_t pos = 0;
    for (char& c : s) {
        if (c == '?') {
            if (pos < res.size()) {
                c = res[pos];
                pos++;
            } else {
                c = 'a';
            }
        }
    }
    out << s << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}