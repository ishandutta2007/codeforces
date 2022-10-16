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
  set<ui32> a;
  while (n--) {
    ui32 x;
    cin >> x;
    a.insert(x);
  }
  unsigned clr = 0;
  while (!a.empty()) {
    ++clr;
    auto el = *a.begin();
    a.erase(a.begin());
    for (auto test = el + el; test <= 100; test += el) {
      a.erase(test);
    }
  }
  cout << clr << '\n';
  return 0;
}