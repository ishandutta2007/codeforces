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
  int n, m;
  in >> n >> m;
  std::vector<int> cs(n);
  for (int i = 0; i < n; i++) {
    in >> cs[i];
  }
  std::vector<int> ws(n);
  for (int i = 0; i < n; i++) {
    in >> ws[i];
  }
  int64_t ans = 0;
  std::vector<bool> bad(n);
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> queue;
  for (int i = 0; i < n ;i++) {
    int change = cs[i] % 100;
    if (change == 0) continue;
    m -= change;
    queue.emplace(ws[i] * (100 - change), i);
    if (m < 0) {
      bad[queue.top().second] = true;
      ans += queue.top().first;
      m += 100;
      queue.pop();
    }
  }
  out << ans << std::endl;
  for (int i = 0; i < n; i++) {
    if (bad[i]) {
      out << (cs[i] / 100 + 1) << " " << 0 << "\n";
    } else {
      out << (cs[i] / 100) << " " << (cs[i] % 100) << "\n";
    }
  }
  out.flush();
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}