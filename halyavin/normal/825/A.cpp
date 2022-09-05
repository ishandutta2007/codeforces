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
    std::string s;
    in >> s;
    s.push_back('0');
    int res = 0;
    int cur = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            cur++;
        } else {
            res = 10 * res + cur;
            cur = 0;
        }
    }
    out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}