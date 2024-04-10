//  Copyright 2019 Nikita Golikov

#include <bits/stdc++.h>

using i32 = std::int32_t;
using ui32 = std::uint32_t;
using i64 = std::int64_t;
using ui64 = std::uint64_t;

template <typename T>
inline constexpr T type_min = std::numeric_limits<T>::min();

template <typename T>
inline constexpr T type_max = std::numeric_limits<T>::max();

template <typename... Args>
void read(Args&... args) {
  (std::cin >> ... >> args);
}

template <typename T>
T input() {
  T x{};
  std::cin >> x;
  return x;
}

void print() {
  std::cout << '\n';
}

template <typename T, typename... Args>
void print(T&& value, Args&&... args) {
  std::cout << std::forward<T>(value);
  if constexpr (sizeof...(args)) {
    std::cout << ' ';
  }
  print(std::forward<Args>(args)...);
}

template <typename T>
T make_vector() {
  return T();
}

template <typename T, typename... Args>
auto make_vector(std::size_t n, Args... args) {
  return std::vector(n, make_vector<T>(args...));
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ui32 n;
  read(n);
  std::vector<ui32> a(n);
  std::generate(a.begin(), a.end(), input<ui32>);
  std::set<ui32> left;
  ui32 ans = 0;
  for (ui32 take_left = 0; take_left <= n; ++take_left) {
    if (take_left) {
      if (!left.insert(a[take_left - 1]).second) {
        break;
      }
    }
    ans = std::max(ans, take_left);
    std::set<ui32> right;
    for (ui32 take_right = 1; take_right <= n - take_left; ++take_right) {
      auto el = a[n - take_right];
      if (!right.insert(el).second || left.count(el)) {
        break;
      }
      ans = std::max(ans, take_left + take_right);
    }
  }
  print(n - ans);
  return 0;
}