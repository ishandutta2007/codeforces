#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::set;
using std::map;
using i32 = std::int32_t;
using ui32 = std::uint32_t;
using i64 = std::int64_t;
using ui64 = std::uint64_t;
using std::pair;
using std::tuple;
using std::sort;
using std::size_t;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t n, k;
  cin >> n >> k;
  std::string s;
  cin >> s;
  bool first = true;
  for (auto& x : s) {
    if (!k) {
      break;
    }
    auto x_prev = x;
    if (s.size() != 1 && first) {
      x = '1';
    } else {
      x = '0';
    }
    first = false;
    k -= (x_prev != x);
  }
  cout << s << '\n';
  return 0;
}