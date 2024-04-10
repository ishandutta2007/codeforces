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
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    std::string s;
    in >> s;
    int prev = 0;
    for (size_t i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == '0') {
            if (prev != i) {
                std::sort(as.begin() + prev, as.begin() + i + 1);
            }
            prev = i + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        if (as[i] != i + 1) {
            out << "NO\n";
            return;
        }
    }
    out << "YES\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}