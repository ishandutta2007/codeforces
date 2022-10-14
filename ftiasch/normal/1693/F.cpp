#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  }

  template <typename T = int> T read() const {
    T v;
    std::cin >> v;
    return v;
  }

  template <typename T = int> std::vector<T> read_vector(size_t n) const {
    std::vector<T> v(n);
    for (size_t i = 0; i < n; ++i) {
      v[i] = read<T>();
    }
    return v;
  }
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-91229OP0g8CGWjPGh.cpp"

int solve(int n, std::string s) {
  if (std::is_sorted(ALL(s))) {
    return 0;
  }
  int suffix0 = std::count(ALL(s), '0');
  int suffix1 = n - suffix0;
  if (suffix0 == suffix1) {
    return 1;
  }
  if (suffix0 < suffix1) {
    std::swap(suffix0, suffix1);
    std::reverse(ALL(s));
    for (auto &c : s) {
      c ^= 1;
    }
  }
  std::vector<int> suffix_map(n + n + 1);
  for (int i = 0, sum = suffix1 - suffix0; i < n; ++i) {
    suffix_map[n + sum] = i;
    sum -= s[i] == '1' ? 1 : -1;
  }
  suffix_map[n] = n;
  int i = 0, prefix1 = 0, result = 0;
  while (i < n && s[i] == '0') {
    i++;
    suffix0--;
  }
  while (suffix0 > prefix1 + suffix1) {
    int j = suffix_map[n + (prefix1 + suffix1) - suffix0];
    result++;
    int count = (prefix1 + j - i) >> 1;
    suffix0 -= count;
    suffix1 -= count - prefix1;
    prefix1 = count;
    i = j;
  }
  return result + !!suffix0;
}

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto s = io.read<std::string>();
    std::cout << solve(n, std::move(s)) << "\n";
  }
}