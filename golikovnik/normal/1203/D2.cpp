#include <bits/stdc++.h>

int main() {
  std::string s, t;
  std::cin >> s >> t;
  auto n = s.size();
  auto m = t.size();
  auto get_lcs = [n, m, &s, &t]() {
    std::vector<std::size_t> result(n + 1);
    for (std::size_t len = 1; len <= n; ++len) {
      auto prev = result[len - 1];
      result[len] = prev + (prev != m && s[len - 1] == t[prev]);
    }
    return result;
  };
  auto lcs_pref = get_lcs();
  std::reverse(s.begin(), s.end());
  std::reverse(t.begin(), t.end());
  auto lcs_suff = get_lcs();
  auto is_subseq = [n, m, &lcs_pref, &lcs_suff](auto from, auto to) {
    auto pref = lcs_pref[from];
    auto suff = lcs_suff[n - to];
    // std::cerr << from << ' ' << to << ' ' << pref << ' ' << suff << '\n';
    return suff >= m - pref;
  };
  std::size_t r = 0;
  std::size_t answer = 0;
  for (std::size_t l = 0; l != n; ++l) {
    r = std::max(r, l);
    while (r != n && is_subseq(l, r)) {
      ++r;
    }
    if (l != r && !is_subseq(l, r)) {
      --r;
    }
    auto result = r - l;
    if (result > answer) {
      answer = result;
      // std::cerr << l << ' ' << r << ' ' << answer << '\n';
    }
  }
  std::cout << answer << '\n';
  return 0;
}