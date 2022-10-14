#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int C = 26;

using Count = std::array<int, C>;

Count get_count(int m, const std::vector<char> &s) {
  Count c{};
  for (int i = 0; i < m; ++i) {
    c[s[i] - 'a']++;
  }
  return c;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  std::vector<std::vector<char>> s(n, std::vector<char>(m + 1));
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i].data());
  }
  auto solve = [&]() -> bool {
    auto c0 = get_count(m, s[0]);
    for (int i = 1; i < n; ++i) {
      if (c0 != get_count(m, s[i])) {
        return false;
      }
    }
    bool keep = std::find_if(c0.begin(), c0.end(),
                             [](int c) { return c >= 2; }) != c0.end();
    std::vector<int> diff(n);
    for (int k = 1; k < n; ++k) {
      for (int i = 0; i < m; ++i) {
        diff[k] += s[0][i] != s[k][i];
      }
    }
    for (int i = 0; i < m; ++i) {
      for (int j = i + 1; j < m; ++j) {
        bool check = true;
        for (int k = 1; k < n && check; ++k) {
          int cur_diff = diff[k];
          cur_diff -= s[0][i] != s[k][i];
          cur_diff -= s[0][j] != s[k][j];
          cur_diff += s[0][i] != s[k][j];
          cur_diff += s[0][j] != s[k][i];
          check &= cur_diff == 2 || (cur_diff == 0 && keep);
        }
        if (check) {
          std::swap(s[0][i], s[0][j]);
          puts(s[0].data());
          return true;
        }
      }
    }
    return false;
  };
  if (!solve()) {
    puts("-1");
  }
}