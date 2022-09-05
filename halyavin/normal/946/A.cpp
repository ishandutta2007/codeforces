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
#include <cstdlib>

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    int res = 0;
    for (int i = 0; i < n; i++){
        int x;
        in >> x;
        res += std::abs(x);
    }
    out << res << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}