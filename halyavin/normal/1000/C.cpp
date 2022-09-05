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
#include <queue>

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<std::pair<int64_t, int64_t>> intervals(n);
    for (int i = 0; i < n; i++) {
        in >> intervals[i].first >> intervals[i].second;
    }
    std::sort(intervals.begin(), intervals.end());
    std::priority_queue<int64_t, std::vector<int64_t>, std::greater<int64_t>> queue;
    int idx = 0;
    int64_t current = -1;
    std::vector<int64_t> stat(n + 1);
    while (idx < n || queue.size() > 0) {
        int64_t next = int64_t(1) << 62;
        if (idx < n) {
            next = intervals[idx].first;
        }
        if (queue.size() > 0) {
            next = std::min(next, queue.top());
        }
        stat[queue.size()] += next - current - 1;
        current = next;
        while (idx < n && intervals[idx].first == current) {
            queue.push(intervals[idx].second);
            idx++;
        }
        stat[queue.size()]++;
        while (!queue.empty() && queue.top() == current) {
            queue.pop();
        }
    }
    for (int i = 1; i <= n; i++) {
        out << stat[i] << " ";
    }
    out << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}