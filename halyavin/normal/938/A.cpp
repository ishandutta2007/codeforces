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

bool vowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

void run(std::istream &in, std::ostream &out) {
    std::string s;
    int len;
    in >> len >> s;
    std::string res;
    bool prev = false;
    for (char c : s) {
        if (prev && vowel(c)) continue;
        res.push_back(c);
        prev = vowel(c);
    }
    out << res << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}