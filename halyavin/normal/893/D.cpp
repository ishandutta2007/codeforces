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
    int n, d;
    in >> n >> d;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    std::vector<std::pair<int, int>> intervals;
    {
        int sum = 0;
        int max_sum = 0;
        for (int i = 0; i < n; i++) {
            if (as[i] == 0) {
                intervals.emplace_back(sum, max_sum);
                sum = 0;
                max_sum = 0;
            } else {
                sum += as[i];
                max_sum = std::max(max_sum, sum);
            }
        }
        intervals.emplace_back(sum, max_sum);
    }
    if (intervals[0].second > d) {
        out << -1 << "\n";
        return;
    }
    if (intervals.size() == 1) {
        out << 0 << "\n";
        return;
    }
    std::vector<int> low(intervals.size() - 1);
    std::vector<int> high(intervals.size() - 1);
    int bound = 0;
    int sum = 0;
    for (size_t i = 0; i + 1 < intervals.size(); i++) {
        sum += intervals[i].first;
        if (sum < 0) {
            bound += -sum;
            sum = 0;
        }
        low[i] = bound;
    }
    sum = 0;
    for (size_t i = 0; i + 1 < intervals.size(); i++) {
        sum += intervals[i].first;
        high[i] = d - intervals[i + 1].second - sum;
    }
    for (size_t i = high.size() - 1; i > 0; i--) {
        high[i - 1] = std::min(high[i - 1], high[i]);
    }
    for (size_t i = 0; i < low.size(); i++) {
        if (low[i] > high[i]) {
            out << -1 << "\n";
            return;
        }
    }
    int ans = 0;
    int cur = 0;
    for (size_t i = 0; i < low.size(); i++) {
        if (low[i] > cur) {
            ans++;
            cur = high[i];
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