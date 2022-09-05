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

void run(std::istream &in, std::ostream &out) {
  int n, m;
  in >> n >> m;
  std::vector<int> invp(n);
  for (int i = 0; i < n; i++) {
    int x;
    in >> x;
    x--;
    invp[x] = i;
  }
  std::vector<std::pair<int, int>> forbidden;
  for (int i = 0; i < m; i++) {
    int a, b;
    in >> a >> b;
    a--;b--;
    a = invp[a];
    b = invp[b];
    if (a > b) std::swap(a, b);
    forbidden.emplace_back(a, b);
  }
  std::sort(forbidden.begin(), forbidden.end());
  std::vector<int> minT(forbidden.size());
  int cur = n;
  for (size_t i = minT.size(); i-- > 0; ) {
    cur = std::min(cur, forbidden[i].second);
    minT[i] = cur;
  }
  minT.push_back(n);
  int64_t ans = 0;
  int curPair = 0;
  for (int start = 0; start < n; start++) {
    while (curPair < forbidden.size() && forbidden[curPair].first < start) curPair++;
    if (minT[curPair] >= start) {
      ans += minT[curPair] - start;
    }
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}