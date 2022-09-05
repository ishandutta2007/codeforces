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
#include <cmath>

struct Solution {
  uint32_t counter = 0;
  int n;
  std::vector<int> colors;
  std::vector<int> answer;
  std::vector<int> map;

  int getAnswer(int k) {
    int res = 0;
    int pos = 0;
    while (pos < n) {
      res++;
      counter++;
      int diff = 0;
      while (pos < n && diff <= k) {
        if (map[colors[pos]] == counter) {
          pos++;
          continue;
        } else {
          if (diff < k) {
            map[colors[pos]] = counter;
            diff++;
            pos++;
            continue;
          } else {
            break;
          }
        }
      }
    }
    return res;
  }

  void binSearch(int left, int right, int minValue, int maxValue) {
    if (minValue == maxValue) {
      std::fill(answer.begin() + left, answer.begin() + right, minValue);
      return;
    }
    if (left >= right) {
      return;
    }
    if (right - left == 1) {
      answer[left] = getAnswer(left);
      return;
    }
    int middle = (left + right) / 2;
    answer[middle] = getAnswer(middle);
    binSearch(left, middle, answer[middle], maxValue);
    binSearch(middle + 1, right, minValue, answer[middle]);
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    colors.resize(n);
    for (int i = 0; i < n; i++) {
      in >> colors[i];
      colors[i]--;
    }
    answer.resize(n + 1);
    map.assign(n, -1);
    int cur = 1;
    int limit = std::floor(std::sqrt(n * std::log(n + 1)));
    answer[0] = n;
    for (; cur <= n && cur < limit; cur++) {
      answer[cur] = getAnswer(cur);
    }
    binSearch(cur, n + 1, 1, answer[cur - 1]);
    for (int i = 1; i <= n; i++) {
      out << answer[i] << " ";
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