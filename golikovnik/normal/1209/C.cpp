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

  unsigned tests;
  cin >> tests;
  while (tests--) {
    ui32 n;
    cin >> n;
    std::string s;
    cin >> s;
    vector<unsigned> a(n);
    for (size_t i = 0; i != n; ++i) {
      a[i] = s[i] - '0';
    }
    vector<unsigned> suff_min(n);
    suff_min.back() = a.back();
    for (size_t i = n - 1; i--; ) {
      suff_min[i] = std::min(suff_min[i + 1], a[i]);
    }
    bool done = false;
    for (unsigned first = 0u; first <= 9u; ++first) {
      bool ok = true;
      unsigned max_first = 0;
      unsigned max_second = 0;
      vector<unsigned> clr(n);
      for (size_t i = 0; i != n; ++i) {
        auto d = a[i];
        if (d < first) {
          if (d < max_first) {
            ok = false;
            break;
          }
          max_first = std::max(max_first, d);
        } else if (d == first) {
          if (i == n - 1 || suff_min[i + 1] >= first) {
            max_first = first;
          } else {
            if (d < max_second) {
              ok = false;
              break;
            }
            max_second = std::max(max_second, d);
            clr[i] = 1;
          }
        } else {
          if (d < max_second) {
            ok = false;
            break;
          }
          max_second = std::max(max_second, d);
          clr[i] = 1;
        }
      }
      if (!ok) {
        continue;
      }
      for (auto c : clr) {
        if (c) {
          cout << '2';
        } else {
          cout << '1';
        }
      }
      cout << '\n';
      done = true;
      break;
    }
    if (!done) {
      cout << "-\n";
    }
  }
  return 0;
}