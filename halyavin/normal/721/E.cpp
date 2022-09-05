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

struct BInterval {
  int x;
  int length;
  int value;
  BInterval(int x, int length, int value) : x(x), length(length), value(value) {
  }
};

struct CompactB {
  int size = 0;
  int p;
  CompactB(int p) : p(p) {}
  std::vector<BInterval> bs; // value, length
  void add(int x, int length) {
    bs.emplace_back(x, length, size);
    size += length;
  }

  std::pair<int, int> lower_bound(int x) {
    int left = 0;
    int right = bs.size();
    while (right - left > 1) {
      int middle = (left + right) / 2;
      if (bs[middle].x >= x) {
        left = middle;
      } else {
        right = middle;
      }
    }
    int shift = std::min((bs[left].x - x) / p, bs[left].length - 1);
    return {bs[left].x - shift * p, bs[left].value + shift};
  }
};

void run(std::istream &in, std::ostream &out) {
  int L, n, p, t;
  in >> L >> n >> p >> t;
  int cur = 0;
  int ans = 0;
  std::vector<std::pair<int, int>> intervals;
  for (int i = 0; i < n; i++) {
    int from, to;
    in >> from >> to;
    if (from >= L) continue;
    to = std::min(to, L);
    intervals.emplace_back(from, to);
  }
  CompactB bPoints(p);
  bPoints.add(L + t + 1, 1);
  for (size_t i = intervals.size(); i-- > 0; ) {
    std::pair<int, int>& interval = intervals[i];
    int leftPoint = interval.second - p + t;
    int rightPoint = interval.second + t;
    std::pair<int, int> searchRes = bPoints.lower_bound(leftPoint);
    int breakPoint = searchRes.first;
    int value, offset;
    if (breakPoint >= rightPoint) {
      offset = p;
      value = searchRes.second;
    } else {
      offset = rightPoint - breakPoint;
      value = searchRes.second - 1;
    }
    int intervalLength = interval.second - interval.first;
    int64_t firstGreater = offset + (bPoints.size - value - 1) * int64_t(p);
    if (firstGreater > intervalLength) continue;
    int length = (intervalLength - firstGreater) / p + 1;
    bPoints.add(interval.second - firstGreater, length);
  }
  out << bPoints.size - 1 << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}