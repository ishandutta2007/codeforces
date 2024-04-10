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

bool isFirst(std::vector<int64_t>& times, int idx) {
  return idx == 0 || times[idx] != times[idx - 1];
}

void run(std::istream &in, std::ostream &out) {
  int64_t ts, tf, t;
  in >> ts >> tf >> t;
  int n;
  in >> n;
  std::vector<int64_t> times(n);
  std::vector<int64_t> serveTimes(n);
  for (int i = 0; i < n; i++) {
    in >> times[i];
  }
  int qStart = 0;
  int qEnd = 0;
  int64_t cur = ts;
  while (cur <= tf - t) {
    while (qEnd < n && times[qEnd] <= cur) qEnd++;
    if (qStart == qEnd) {
      out << cur << std::endl;
      return;
    }
    cur += t;
    serveTimes[qStart] = cur;
    qStart++;
  }
  int64_t ans = ts;
  int64_t opt = 0;
  for (int i = 0; i < qStart; i++) {
    if (isFirst(times, i) && serveTimes[i] <= tf - t) {
      if (serveTimes[i] - times[i] < ans) {
        ans = serveTimes[i] - times[i];
        opt = times[i];
      }
    }
    if (i != 0 && times[i] > times[i - 1] + 1) {
      if (serveTimes[i - 1] - (times[i] - 1) < ans) {
        ans = serveTimes[i - 1] - (times[i] - 1);
        opt = times[i] - 1;
      }
    }
  }
  if (ts - (times[0] - 1) < ans) {
    ans = ts - (times[0] - 1);
    opt = times[0] - 1;
  }
  out << opt << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}