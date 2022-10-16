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
using std::string;
using std::reverse;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<unsigned> a(4);
  unsigned s = 0;
  for (auto& x : a) {
    cin >> x;
    s += x;
  }
  for (auto mask = 0u; mask != 16; ++mask) {
    unsigned k = 0;
    for (size_t i = 0; i != 4; ++i) {
      if (mask & (1u << i)) {
        k += a[i];
      }
    }
    if (k == s - k) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}