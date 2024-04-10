#include <bits/stdc++.h>

bool solve() {
  unsigned n;
  std::cin >> n;
  std::vector<unsigned> a(4 * n);
  std::map<unsigned, unsigned> cnt;
  for (auto& x : a) {
    std::cin >> x;
    ++cnt[x];
  }
  for (auto&& [_, c] : cnt) {
    if (c % 2 == 1) {
      return false;
    }
  }
  auto take = [&cnt](unsigned x) {
    cnt[x] -= 2;
    if (!cnt[x]) {
      cnt.erase(x);
    }
  };
  unsigned area = cnt.begin()->first * cnt.rbegin()->first;
  while (n) {
    auto mn = cnt.begin()->first;
    auto mx = cnt.rbegin()->first;
    if (area != mn * mx) {
      return false;
    }
    take(mn);
    take(mx);
    --n;
  }
  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  unsigned q;
  std::cin >> q;
  while (q--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}