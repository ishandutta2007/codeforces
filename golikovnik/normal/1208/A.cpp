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
  ui32 tests;
  read(tests);
  while (tests--) {
    ui32 a, b, n;
    read(a, b, n);
    n %= 3;
    if (n == 0) {
      print(a);
    } else if (n == 1) {
      print(b);
    } else {
      print(a ^ b);
    }
  }
  return 0;
}