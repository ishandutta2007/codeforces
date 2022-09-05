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
    std::vector<std::pair<int, int>> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i].first;
        as[i].second = i;
    }
    std::sort(as.begin(), as.end(), std::greater<std::pair<int, int>>());
    as.emplace_back(0, -1);
    std::vector<std::vector<std::pair<int, int>>> dyn(n + 1, std::vector<std::pair<int, int>>(n + 1));
    for (int i = 1; i <= n; i++) {
        int optValue = as[i - 1].first - as[i].first;
        int optInd = i;
        for (int j = i; j <= n; j++) {
            if (as[j - 1].first - as[j].first > optValue) {
                optValue = as[j - 1].first - as[j].first;
                optInd = j;
            }
            dyn[i][j].first = optValue;
            dyn[i][j].second = optInd;
        }
    }
    int opt1 = -1;
    int opt2 = -1;
    int opt3 = -1;
    int optC1 = -1;
    int optC2 = -1;
    int optC3 = -1;
    for (int c1 = 1; c1 < n; c1++) {
        for (int c2 = 1; c2 <= 2 * c1 && c1 + c2 < n; c2++) {
            if (2 * c2 < c1) continue;
            int c3Max = std::min(n - c1 - c2, 2 * std::min(c1, c2));
            int c3Min = std::max(1, (std::max(c1, c2) + 1)/ 2);
            if (c3Min > c3Max) continue;
            int diff1 = as[c1 - 1].first - as[c1].first;
            int diff2 = as[c1 + c2 - 1].first - as[c1 + c2].first;
            int diff3 = dyn[c1 + c2 + c3Min][c1 + c2 + c3Max].first;
            int c3 = dyn[c1 + c2 + c3Min][c1 + c2 + c3Max].second - c1 - c2;
            if (diff1 > opt1 || (diff1 == opt1 && (diff2 > opt2 || (diff2 == opt2 && diff3 > opt3)))) {
                opt1 = diff1;
                opt2 = diff2;
                opt3 = diff3;
                optC1 = c1;
                optC2 = c2;
                optC3 = c3;
            }
        }
    }
    std::vector<int> ans(n, -1);
    for (int i = 0; i < optC1; i++) {
        ans[as[i].second] = 1;
    }
    for (int i = optC1; i < optC1 + optC2; i++) {
        ans[as[i].second] = 2;
    }
    for (int i = optC1 + optC2; i < optC1 + optC2 + optC3; i++) {
        ans[as[i].second] = 3;
    }
    for (int i = 0; i < n; i++) {
        out << ans[i] << " ";
    }
    out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}