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
#include <map>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::map<int, int> pos;
  std::vector<int> dyn(n);
  std::vector<int> prev(n);
  int cur = 0;
  int cprev = -1;
  for (int i = 0; i < n; i++) {
    int color;
    in >> color;
    auto it = pos.find(color);
    if (it == pos.end()) {
      pos[color] = i;
    } else {
      int pos2 = it->second - 1;
      int ans = pos2 < 0 ? 1 : dyn[pos2] + 1;
      if (ans > cur) {
        if (ans == 1) {
          pos2 = -1;
        }
        cur = ans;
        cprev = pos2;
      }
      pos[color] = i;
    }
    dyn[i] = cur;
    prev[i] = cprev;
  }
  if (dyn[n - 1] == 0) {
    out << -1 << std::endl;
    return;
  }
  out << dyn[n-1] << std::endl;
  cur = n- 1;
  std::vector<std::pair<int, int>> ans;
  while (cur >= 0) {
    ans.emplace_back(prev[cur] + 2, cur + 1);
    cur = prev[cur];
  }
  std::reverse(ans.begin(), ans.end());
  for (size_t i = 0; i < ans.size(); i++) {
    out << ans[i].first << " " << ans[i].second << "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}