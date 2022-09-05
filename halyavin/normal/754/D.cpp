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

struct Interval {
  int l, r;
  int id;
  Interval(int l, int r, int id) : l(l), r(r), id(id) {}
};

void run(std::istream &in, std::ostream &out) {
  int k, n;
  in >> n >> k;
  std::vector<Interval> intervals;
  for (int i = 0; i < n; i++) {
    int l, r;
    in >> l >> r;
    intervals.emplace_back(l, r + 1, i + 1);
  }
  std::sort(intervals.begin(), intervals.end(), [](const Interval& left, const Interval& right) {
    return left.l < right.l;
  });
  int optProducts = 0;
  int optStart = -1;
  std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
  for (Interval& interval : intervals) {
    queue.push(interval.r);
    if (queue.size() > k) {
      queue.pop();
    }
    if (queue.size() == k) {
      int answer = queue.top() - interval.l;
      if (answer > optProducts) {
        optProducts = answer;
        optStart = interval.l;
      }
    }
  }
  if (optProducts == 0) {
    out << 0 << std::endl;
    for (int i = 0; i < k; i++) {
      out << i + 1 << " ";
    }
    out << std::endl;
    return;
  }
  out << optProducts << std::endl;
  int count = 0;
  for (Interval& interval : intervals) {
    if (interval.l <= optStart && interval.r >= optStart + optProducts && count < k) {
      out << interval.id << " ";
      count++;
    }
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}