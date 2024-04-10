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

struct ant {
  int s;
  int d;
  int idx;
};

struct Solution {
  int n, m;
  int64_t t;
  int offset;
  std::vector<ant> init;
  std::vector<int> answer;
  std::vector<uint32_t> lefts;
  std::vector<uint32_t> rights;

  void reduce() {
    int defect = 0;
    for (ant& p : init) {
      defect += p.d;
    }
    int64_t rounds = t / m;
    offset = static_cast<int>((rounds * defect) % n);
    if (offset != 0) {
      offset = n - offset;
    }
    t = t % m;
  }

  int getBeforeLeft(uint32_t pos) {
    int res = 0;
    while (pos >= m) {
      res += lefts.size();
      pos -= m;
    }
    res += std::distance(lefts.begin(), std::lower_bound(lefts.begin(), lefts.end(), pos));
    return res;
  }

  void solveRight() {
    lefts.clear();
    for (int i = 0; i < n; i++) {
      if (init[i].d < 0) {
        lefts.push_back(init[i].s);
      }
    }
    for (int i = 0; i < n; i++) {
      if (init[i].d > 0) {
        uint32_t from = init[i].s;
        uint32_t to = from + 2 * uint32_t(t);
        int change = offset + getBeforeLeft(to) - getBeforeLeft(from);
        answer[(i + change) % n] = (from + t) % m;
      }
    }
  }

  int getBeforeRight(uint32_t pos) {
    int res = 0;
    while (pos >= m) {
      res += rights.size();
      pos -= m;
    }
    res += std::distance(rights.begin(), std::lower_bound(rights.begin(), rights.end(), pos));
    return res;
  }

  void solveLeft() {
    rights.clear();
    for (int i = 0; i < n; i++) {
      if (init[i].d > 0) {
        rights.push_back(m - init[i].s - 1);
      }
    }
    std::reverse(rights.begin(), rights.end());
    for (int i = 0; i < n; i++) {
      if (init[i].d < 0) {
        uint32_t from = m - init[i].s - 1;
        uint32_t to = from + 2 * uint32_t(t);
        int change = (offset - (getBeforeRight(to) - getBeforeRight(from))) % n;
        answer[(i + change + n) % n] = (init[i].s - t + m) % m;
      }
    }
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n >> m >> t;
    init.resize(n);
    for (int i = 0; i < n; i++) {
      char c;
      in >> init[i].s >> c;
      init[i].s--;
      init[i].d = c == 'L' ? -1 : 1;
      init[i].idx = i;
    }
    std::sort(init.begin(), init.end(), [](const ant& left, const ant& right) { return left.s < right.s;});
    reduce();
    answer.assign(n, -1);
    solveRight();
    solveLeft();
    std::vector<int> realAnswer(n);
    for (int i = 0; i < n; i++) {
      realAnswer[init[i].idx] = answer[i] + 1;
    }
    for (int i = 0; i < n; i++) {
      out << realAnswer[i] << " ";
    }
    out << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}