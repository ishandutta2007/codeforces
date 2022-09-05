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

std::pair<int, int> readBoard(std::istream &in, int n) {
    std::pair<int, int> res{0, 0};
    for (int i = 0; i < n; i++) {
        std::string s;
        in >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                if ((i + j) % 2 == 0) {
                    res.first++;
                } else {
                    res.second++;
                }
            }
        }
    }
    return res;
}

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::array<std::pair<int, int>, 4> boards;
    for (int i = 0; i < 4; i++) {
        boards[i] = readBoard(in, n);
    }
    int evens = (n * n + 1) / 2;
    int odds = n * n - evens;
    int ans = 4 * n * n + 1;
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            int cur = 0;
            cur += evens - boards[i].first;
            cur += evens - boards[j].first;
            cur += boards[i].second;
            cur += boards[j].second;
            for (int k = 0; k < 4; k++) {
                if (k != i && k != j) {
                    cur += boards[k].first;
                    cur += odds - boards[k].second;
                }
            }
            ans = std::min(ans, cur);
        }
    }
    out << ans << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}