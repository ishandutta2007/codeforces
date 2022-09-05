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

struct LinearProblem {
  std::array<int, 5> s;
  int q;
};

void run(std::istream& in, std::ostream& out) {
  int n, b, q;
  in >> n >> b >> q;
  std::vector<std::pair<int, int>> queries(q);
  for (int i = 0; i < q; i++) {
    in >> queries[i].first >> queries[i].second;
  }
  queries.emplace_back(b, n);
  queries.emplace_back(0, 0);
  std::sort(queries.begin(), queries.end());
  std::vector<LinearProblem> problems;
  for (int i = 0; i + 1 < queries.size(); i++) {
    if (queries[i].first == queries[i + 1].first) {
      if (queries[i].second != queries[i + 1].second) {
        out << "unfair" << std::endl;
        return;
      }
    }
    if (queries[i].second > queries[i + 1].second) {
      out << "unfair" << std::endl;
      return;
    }
    if (queries[i+1].second - queries[i].second > queries[i+1].first - queries[i].first) {
      out << "unfair" << std::endl;
      return;
    }
    LinearProblem s;
    s.q = queries[i + 1].second - queries[i].second;
    s.s.fill(0);
    for (int j = queries[i].first + 1; j <= queries[i + 1].first; j++) {
      s.s[j % 5]++;
    }
    problems.push_back(s);
  }
  for (int mask = 1; mask < 32; mask++) {
    std::vector<int> good;
    std::vector<int> bad;
    for (int i = 0; i < 5; i++) {
      if ((mask >> i) & 1) {
        good.push_back(i);
      } else {
        bad.push_back(i);
      }
    }
    int target = good.size() * (n / 5);
    int minSum = 0;
    int maxSum = 0;
    for (LinearProblem& s : problems) {
      int minValue = s.q;
      for (int idx : bad) {
        minValue -= s.s[idx];
      }
      minSum += std::max(0, minValue);
      int maxValue = 0;
      for (int idx : good) {
        maxValue += s.s[idx];
      }
      maxSum += std::min(s.q, maxValue);
    }
    if (target < minSum || target > maxSum) {
      out << "unfair" << std::endl;
      return;
    }
  }
  out << "fair" << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}