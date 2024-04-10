#include <bits/stdc++.h>

int main() {
  std::vector<unsigned> period_len(10);
  std::vector<std::uint64_t> period_s(10);
  for (unsigned d = 0; d != 10; ++d) {
    std::uint64_t s = 0;
    unsigned times = 0;
    unsigned cur = d;
    do {
      ++times;
      s += cur;
      cur += d;
      cur %= 10;
    } while (cur != d);
    period_len[d] = times;
    period_s[d] = s;
  }
  unsigned q;
  std::cin >> q;
  while (q--) {
    std::uint64_t n, m;
    std::cin >> n >> m;
    auto times = n / m;
    m %= 10;
    auto periods = times / period_len[m];
    std::uint64_t result = periods * period_s[m];
    times %= period_len[m];
    auto cur = m;
    while (times--) {
      result += cur;
      cur += m;
      cur %= 10;
    }
    std::cout << result << '\n';
  }
  return 0;
}