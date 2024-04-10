#include <bits/stdc++.h>

int main() {
  unsigned n;
  std::uint32_t k;
  std::cin >> n >> k;
  std::vector<std::uint32_t> a(n);
  for (auto& x : a) {
    std::cin >> x;
  }
  std::sort(a.begin(), a.end());
  std::uint32_t left = a[n / 2];
  std::uint32_t right = std::numeric_limits<std::uint32_t>::max();
  while (left + 1 < right) {
    auto middle = left + (right - left) / 2;
    std::uint64_t need = 0;
    for (auto i = n / 2; i != n; ++i) {
      if (a[i] < middle) {
        need += middle - a[i];
      }
    }
    if (need <= k) {
      left = middle;
    } else {
      right = middle;
    }
  }
  std::cout << left << '\n';
  return 0;
}