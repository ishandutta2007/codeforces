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
    int spec = 2;
    bool good = true;
    for (int i = 0; i < n; i++) {
        int v;
        in >> v;
        v--;
        if (v == spec) {
            good = false;
            break;
        }
        spec = 3 - spec - v;
    }
    if (good) {
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