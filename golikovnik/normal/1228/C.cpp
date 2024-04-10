#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::uint64_t x, n;
  std::cin >> x >> n;
  std::vector<std::uint64_t> p;
  for (std::uint64_t pr = 2; pr * pr <= x; ++pr) {
    if (x % pr) {
      continue;
    }
    p.push_back(pr);
    while (!(x % pr)) {
      x /= pr;
    }
  }
  if (x != 1) {
    p.push_back(x);
  }
  std::uint64_t result = 1;
  std::uint64_t constexpr MOD = 1e9 + 7;
  auto overflows = [](std::uint64_t x, std::uint64_t y) {
    return x > std::numeric_limits<std::uint64_t>::max() / y;
  };
  auto f = [n](auto k) {
    return n / k;
  };
  auto pw = [MOD](auto x, auto deg) {
    x %= MOD;
    std::uint64_t result = 1;
    while (deg) {
      if (deg % 2) {
        result *= x;
        result %= MOD;
      }
      x *= x;
      x %= MOD;
      deg /= 2;
    }
    return result;
  };
  for (auto pr : p) {
    std::uint64_t p_pow = pr;
    while (p_pow <= n) {
      std:uint64_t d = f(p_pow);
      if (!overflows(p_pow, pr)) {
        d -= f(p_pow * pr);
      }
      result *= pw(p_pow, d);
      result %= MOD;
      if (!overflows(p_pow, pr)) {
        p_pow *= pr;
      } else {
        break;
      }
    }
  }
  std::cout << result << '\n';
  return 0;
}