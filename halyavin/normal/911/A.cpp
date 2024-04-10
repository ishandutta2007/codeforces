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
    int minValue = *std::min_element(as.begin(), as.end());
    std::vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (as[i] == minValue) {
            pos.push_back(i);
        }
    }
    int minDist = n;
    for (int i = 1; i < pos.size(); i++) {
        minDist = std::min(minDist, pos[i] - pos[i - 1]);
    }
    out << minDist << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}