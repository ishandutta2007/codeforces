#include <bits/stdc++.h>

int main() {
  unsigned n, m;
  std::cin >> n >> m;
  auto const ALPHA = 26u;
  std::vector<std::vector<unsigned>> cnt(m, std::vector<unsigned>(ALPHA));
  for (auto i = 0u; i != n; ++i) {
    std::string s;
    std::cin >> s;
    for (auto j = 0u; j != m; ++j) {
      ++cnt[j][s[j] - 'A'];
    }
  }
  std::uint32_t answer = 0;
  for (auto i = 0u; i != m; ++i) {
    unsigned score;
    std::cin >> score;
    answer += score * (*std::max_element(cnt[i].begin(), cnt[i].end()));
  }
  std::cout << answer << '\n';
  return 0;
}