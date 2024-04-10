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
#line 2 "/tmp/tmp-148791uLcpjIgdfvS4.cpp"

using Result = std::tuple<int, int, int, int>;

struct Stat {
  Result add(int a, int i) {
    best = std::min(best, {2 * sum - i, i});
    sum++;
    return {2 * sum - (i + 1) - best.first, a, best.second, i + 1};
  }

  int sum = 0;
  std::pair<int, int> best = {INT_MAX, -1};
};

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::map<int, Stat> stats;
    Result result{INT_MIN, -1, -1, -1};
    for (int i = 0; i < n; ++i) {
      int a = io.read();
      result = std::max(result, stats[a].add(a, i));
    }
    auto [_, a, l, r] = result;
    std::cout << a << " " << l + 1 << " " << r << std::endl;
  }
}