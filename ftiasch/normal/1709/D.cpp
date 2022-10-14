#line 2 "/home/ftiasch/Documents/shoka/sparse_table.h"

#include <cstring>
#include <functional>
#include <vector>

template <typename T, typename Compare = std::less<T>> struct SparseTable {
  explicit SparseTable(const std::vector<T> &value)
      : n(value.size()), l(log2n(n)), log(n), table(l, std::vector<T>(n)) {
    log[0] = 0;
    for (int i = 1; i < n; ++i) {
      log[i] = log[i - 1] + (1 << (log[i - 1] + 1) < i + 1);
    }
    table[0] = value;
    for (int i = 1; i < l; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  T operator()(int l, int r) const {
    const int lv = log[r - l];
    return min(table[lv][l], table[lv][r - (1 << lv) + 1]);
  }

private:
  static constexpr int log2n(int n) {
    return n > 1 ? 32 - __builtin_clz(n - 1) : 1;
  }

  static T min(const T &a, const T &b) {
    static Compare compare;
    return compare(a, b) ? a : b;
  }

  int n, l;
  std::vector<int> log;
  std::vector<std::vector<T>> table;
};
#line 2 "/tmp/tmp-11734301zAGglVrylQx.cpp"

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

  template <typename T> std::ostream &operator<<(const T &o) {
    return std::cout << o;
  }
};

template <typename T, typename Compare = std::less<T>>
struct PQ : public std::priority_queue<T, std::vector<T>, Compare> {
  T pop() {
    using Base = std::priority_queue<T, std::vector<T>, Compare>;
    auto t = Base::top();
    Base::pop();
    return t;
  }
};
#line 4 "/tmp/tmp-11734301zAGglVrylQx.cpp"

int main() {
  IO io;
  int n = io.read();
  int m = io.read();
  auto h = io.read_vector(m);
  SparseTable<int, std::greater<int>> rmq(h);
  int q = io.read();
  while (q--) {
    int xs = io.read();
    int ys = io.read() - 1;
    int xt = io.read();
    int yt = io.read() - 1;
    int k = io.read();
    int x = xs + (n - xs) / k * k;
    std::cout << (std::abs(xs - xt) % k == 0 && std::abs(ys - yt) % k == 0 &&
                          (ys <= yt ? rmq(ys, yt) : rmq(yt, ys)) < x
                      ? "YES"
                      : "NO")
              << "\n";
  }
}