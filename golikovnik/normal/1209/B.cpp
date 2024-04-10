#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::set;
using std::map;
using std::pair;
using ui32 = std::uint32_t;
using i32 = std::int32_t;
using ui64 = std::uint64_t;
using i64 = std::int64_t;
using std::size_t;
using std::sort;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unsigned n;
  cin >> n;
  std::string ss;
  cin >> ss;
  vector<pair<unsigned, unsigned>> a(n);
  for (auto& [x, y] : a) {
    cin >> x >> y;
  }
  unsigned max = 0;
  for (unsigned t = 0; t <= 10000; ++t) {
    unsigned result = 0;
    for (size_t i = 0; i != n; ++i) {
      auto [d, s] = a[i];
      unsigned n_changes = t < s ? 0u : (t - s) / d + 1u;
      n_changes %= 2;
      if (n_changes != (ss[i] - '0')) {
        ++result;
      }
    }
    max = std::max(max, result);
  }
  cout << max << '\n';
  return 0;
}