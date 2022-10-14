#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

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
#line 2 "/tmp/tmp-56992c2XVYd1Mt5rk.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    auto s = io.read<std::string>();
    int t0 = ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 +
             (s[4] - '0');
    int x = io.read();
    int result = 0;
    int t = t0;
    do {
      int h = t / 60;
      int m = t % 60;
      result += (h / 10) == m % 10 && (h % 10) == (m / 10);
      t = (t + x) % (24 * 60);
    } while (t != t0);
    std::cout << result << "\n";
  }
}