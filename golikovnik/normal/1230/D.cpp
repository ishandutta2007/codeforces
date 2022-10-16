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

  size_t n;
  cin >> n;
  vector<ui64> a(n), cost(n);
  std::map<ui64, unsigned> guys;
  for (auto& x : a) {
    cin >> x;
  }
  for (size_t i = 0; i != n; ++i) {
    ui64 w;
    cin >> w;
    ++guys[a[i]];
    cost[i] = w;
  }
  vector<bool> used(n);
  ui64 answer = 0;
  for (size_t i = 0; i != n; ++i) {
    if (used[i] || guys[a[i]] < 2) {
      continue;
    }
    for (size_t j = 0; j != n; ++j) {
      if (used[j]) {
        continue;
      }
      if ((a[j] | a[i]) == a[i]) {
        used[j] = true;
        answer += cost[j];
      }
    }
  }
  cout << answer << '\n';
  return 0;
}