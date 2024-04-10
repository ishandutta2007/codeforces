#include <bits/stdc++.h>

int main() {
  std::size_t n, k;
  std::cin >> n >> k;
  unsigned constexpr MAX = 2e5 + 5;
  std::vector<std::vector<unsigned>> times(MAX);
  while (n--) {
    unsigned x;
    std::cin >> x;
    unsigned cur = 0;
    while (true) {
      times[x].push_back(cur);
      if (!x) {
        break;
      }
      x /= 2;
      ++cur;
    }
  }
  unsigned result = std::numeric_limits<unsigned>::max();
  for (auto& v : times) {
    if (v.size() < k) {
      continue;
    }
    std::nth_element(v.begin(), v.begin() + k, v.end());
    result = std::min(result, std::accumulate(v.begin(), v.begin() + k, 0u));
  }
  std::cout << result << '\n';
  return 0;
}