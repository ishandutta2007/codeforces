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
#include <set>

void run(std::istream &in, std::ostream &out) {
    int n, A;
    in >> n >> A;
    A--;
    std::vector<int> curSum(1000000);
    std::vector<std::set<int>> sumToColors(n + 1);
    for (int i = 0; i < 1000000; i++) {
        if (i != A) {
            sumToColors[0].insert(i);
        }
    }
    int sumA = 0;
    for (int i = 0; i < n; i++) {
        int c;
        in >> c;
        c--;
        if (c != A) {
            int sum = curSum[c];
            auto it = sumToColors[sum].find(c);
            if (it != sumToColors[sum].end()) {
                sumToColors[sum].erase(it);
                sumToColors[sum + 1].insert(c);
            }
            curSum[c]++;
        } else {
            sumToColors[sumA].clear();
            sumA++;
        }
    }
    for (int i = sumA; (size_t)i < sumToColors.size(); i++) {
        if (!sumToColors[i].empty()) {
            out << *sumToColors[i].begin() + 1 << std::endl;
            return;
        }
    }
    out << -1 << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}