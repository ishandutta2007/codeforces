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

struct sub {
  int idx;
  int pos;

  sub() : idx(0), pos(0) { }

  sub(int idx, int pos) : idx(idx), pos(pos) { }
};

struct variant {
  int len;
  int64_t sum;
  variant() : len(0), sum(0) {}
  variant(int len, int64_t sum) : len(len), sum(sum) {}
  int64_t get() { return sum * len; }
};

struct Solution {
  std::vector<std::string> t;
  int all;
  int levels;
  std::vector<sub> order;
  std::vector<std::vector<std::vector<int>>> comps;
  std::vector<int64_t> costs;
  int ncomps;

  void init_order() {
    std::array<int, 26> counts = {};
    for (size_t i = 0; i < t.size(); i++) {
      for (size_t j = 0; j < t[i].length(); j++) {
        counts[t[i][j] - 'a']++;
      }
    }
    int sum = 0;
    for (size_t i = 0; i < counts.size(); i++) {
      sum += counts[i];
      counts[i] = sum;
    }
    for (size_t i = 0; i < t.size(); i++) {
      for (size_t j = 0; j < t[i].length(); j++) {
        int comp = t[i][j] - 'a';
        counts[comp]--;
        order[counts[comp]].idx = i;
        order[counts[comp]].pos = j;
        comps[0][i][j] = comp;
      }
    }
    ncomps = 26;
  }

  std::pair<int, int> get_pair(int level, int shift, int idx, int pos) {
    std::pair<int, int> res;
    res.first = comps[level - 1][idx][pos];
    if (pos + shift < t[idx].length()) {
      res.second = comps[level - 1][idx][pos + shift];
    } else {
      res.second = -1;
    }
    return res;
  };

  void double_order(int level) {
    std::vector<sub> new_order;
    new_order.reserve(all);
    int shift = 1 << (level - 1);
    for (size_t i = 0; i < t.size(); i++) {
      for(size_t j = 0; j < t[i].length(); j++) {
        if (j + shift >= t[i].length()) {
          new_order.emplace_back(i, j);
        }
      }
    }
    for (sub& str : order) {
      if (str.pos >= shift) {
        new_order.emplace_back(str.idx, str.pos - shift);
      }
    }
    std::vector<int> stats(ncomps);
    auto& comps_prev = comps[level - 1];
    for (size_t i = 0; i < comps_prev.size(); i++) {
      for (size_t j = 0; j < comps_prev[i].size(); j++) {
        stats[comps_prev[i][j]]++;
      }
    }
    int sum = 0;
    for (int i = 0; i < ncomps; i++) {
      int next_sum = sum + stats[i];
      stats[i] = sum;
      sum = next_sum;
    }
    for (sub& str : new_order) {
      int comp = comps_prev[str.idx][str.pos];
      order[stats[comp]] = str;
      stats[comp]++;
    }
    int cur_comp = 0;
    comps[level][order[0].idx][order[0].pos] = 0;
    std::pair<int, int> prev = get_pair(level, shift, order[0].idx, order[0].pos);
    for (size_t i = 1; i < order.size(); i++) {
      std::pair<int, int> cur = get_pair(level, shift, order[i].idx, order[i].pos);
      if (cur != prev) {
        cur_comp++;
        prev = cur;
      }
      comps[level][order[i].idx][order[i].pos] = cur_comp;
    }
    ncomps = cur_comp + 1;
  }

  int common_prefix(int i1, int i2) {
    int res = 0;
    int idx1 = order[i1].idx;
    int pos1 = order[i1].pos;
    int idx2 = order[i2].idx;
    int pos2 = order[i2].pos;
    int len1 = t[idx1].length() - pos1;
    int len2 = t[idx2].length() - pos2;
    int len = std::min(len1, len2);
    for (int i = levels - 1; i >= 0; i--) {
      if ((1 << i) + res > len) {
        continue;
      }
      if (comps[i][idx1][pos1] == comps[i][idx2][pos2]) {
        res += 1 << i;
        pos1 += 1 << i;
        pos2 += 1 << i;
      }
    }
    return res;
  }

  void run(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    t.resize(n);
    all = 0;
    for (int i = 0; i < n; i++) {
      in >> t[i];
      all += t[i].length();
    }
    costs.resize(n);
    for (int i = 0; i < n; i++) {
      in >> costs[i];
    }
    levels = 1;
    while (1 << (levels - 1) < all) levels++;
    comps.resize(levels);
    for (int i = 0; i < levels; i++) {
      comps[i].resize(n);
      for (int j = 0; j < n; j++) {
        comps[i][j].resize(t[j].length());
      }
    }
    order.resize(all);
    init_order();
    for (int i = 1; i < levels; i++) {
      double_order(i);
    }
    int64_t ans = 0;
    std::vector<variant> stack;
    stack.emplace_back(0, 0);
    stack.emplace_back(t[order[0].idx].length() - order[0].pos, costs[order[0].idx]);
    for (size_t i = 1; i < order.size(); i++) {
      int cur_cost = costs[order[i].idx];
      int common = common_prefix(i - 1, i);
      while (stack.size() > 1 && std::min(common, stack[stack.size() - 1].len) <= stack[stack.size() - 2].len) {
        ans = std::max(ans, stack.back().get());
        stack[stack.size() - 2].sum += stack[stack.size() - 1].sum;
        stack.resize(stack.size() - 1);
      }
      if (stack.back().len > common) {
        ans = std::max(ans, stack.back().get());
      }
      stack.back().len = std::min(stack.back().len, common);
      if (t[order[i].idx].length() - order[i].pos > common) {
        stack.emplace_back(t[order[i].idx].length() - order[i].pos, cur_cost);
      } else {
        stack.back().sum += cur_cost;
      }
    }
    while (stack.size() > 1) {
      ans = std::max(ans, stack.back().get());
      stack[stack.size() - 2].sum += stack[stack.size() - 1].sum;
      stack.resize(stack.size() - 1);
    }
    ans = std::max(ans, stack.back().get());
    out << ans << std::endl;
  }

};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}