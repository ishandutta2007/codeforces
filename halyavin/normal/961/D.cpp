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

bool isInLine(const std::pair<int, int>& p1, const std::pair<int, int>& p2, const std::pair<int, int>& p3) {
    int64_t d1x = p2.first - p1.first;
    int64_t d1y = p2.second - p1.second;
    int64_t d2x = p3.first - p1.first;
    int64_t d2y = p3.second - p1.second;
    return d1x * d2y == d1y * d2x;
}

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<std::pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        in >> points[i].first >> points[i].second;
    }
    if (n <= 4) {
        out << "YES\n";
        return;
    }
    for (int i1 = 0; i1 < 3; i1++) {
        for (int j1 = i1 + 1; j1 < 3; j1++) {
            std::vector<int> ps;
            for (int i = 0; i < n; i++) {
                if (!isInLine(points[i1], points[j1], points[i])) {
                    ps.push_back(i);
                }
            }
            if (ps.size() <= 2) {
                out << "YES\n";
                return;
            }
            bool good = true;
            for (size_t i = 2; i < ps.size(); i++) {
                if (!isInLine(points[ps[0]], points[ps[1]], points[ps[i]])) {
                    good = false;
                    break;
                }
            }
            if (good) {
                out << "YES\n";
                return;
            }
        }
    }
    out << "NO\n";
    return;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}