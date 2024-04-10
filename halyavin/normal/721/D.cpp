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

struct Solution {
  int n, k, x;
  std::vector<int64_t> data;

  void solve() {
    int pos = 0, neg = 0, zero = 0;
    for (int v : data) {
      if (v > 0) pos++;
      if (v == 0) zero++;
      if (v < 0) neg++;
    }
    if (zero > k) {
      return;
    }
    if (zero > 0) {
      k -= zero;
      int last = !(neg & 1);
      for (int64_t& v : data) {
        if (v != 0) continue;
        if (zero > 1) {
          v += x;
          zero--;
          pos++;
          continue;
        }
        if (last) {
          v -= x;
          zero--;
          neg++;
        } else {
          v += x;
          zero--;
          pos++;
        }
      }

    }
    if ((neg & 1) == 0) {
      int minpos = 0;
      int64_t minvalue = std::abs(data[0]);
      for (size_t i = 1; i < data.size(); i++) {
        if (std::abs(data[i]) < minvalue) {
          minvalue = std::abs(data[i]);
          minpos = i;
        }
      }
      int steps = std::min(k, (int)(minvalue / x + 1));
      if (data[minpos] > 0) {
        data[minpos] -= steps * int64_t(x);
      } else {
        data[minpos] += steps * int64_t(x);
      }
      k -= steps;
    }
    if (k == 0) {
      return;
    }
    std::priority_queue<std::pair<int64_t, int>> queue;
    for (int i = 0; i < n; i++) {
      queue.emplace(-std::abs(data[i]),i);
    }
    for (int i= 0; i < k; i++) {
      std::pair<int64_t, int> cur = queue.top();
      queue.pop();
      int v = cur.second;
      if (data[v] > 0) {
        data[v] += x;
      } else {
        data[v] -= x;
      }
      queue.emplace(-std::abs(data[v]), v);
    }
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n >> k >> x;
    data.resize(n);
    for (int i = 0; i < n; i++) {
      in >> data[i];
    }
    solve();
    for (int i = 0; i < n; i++) {
      out << data[i] << " ";
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