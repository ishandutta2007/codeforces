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
#include <sstream>

void run(std::istream &in, std::ostream &out) {
    int x;
    in >> x;
    if (x == 0) {
        out << "YES\n";
        return;
    }
    while (x % 10 == 0) {
        x /= 10;
    }
    std::ostringstream str;
    str << x;
    std::string sx = str.str();
    std::string rsx = sx;
    std::reverse(rsx.begin(), rsx.end());
    if (sx == rsx) {
        out << "YES\n";
    } else {
        out << "NO\n";
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}