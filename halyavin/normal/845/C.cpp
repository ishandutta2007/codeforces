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
    std::vector<std::pair<int, int>> shows(n);
    for (int i = 0; i < n; i++) {
        in >> shows[i].first >> shows[i].second;
    }
    std::sort(shows.begin(), shows.end());
    int t1 = -1;
    int t2 = -1;
    for (int i = 0; i < n; i++) {
        if (t1 < shows[i].first) {
            t1 = shows[i].second;
        } else if (t2 < shows[i].first) {
            t2 = shows[i].second;
        } else {
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