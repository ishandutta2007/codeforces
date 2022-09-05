#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <queue>

template<class T>
struct BinTree1 {
  size_t size;
  std::vector<T> t;

  BinTree1(size_t N) :
      size(N),
      t(2 * N) { }

  BinTree1(const std::vector<T>& other) :
      size(other.size()),
      t(2 * other.size()) {
    std::copy(other.begin(), other.end(), t.begin() + size);
    for (size_t i = size; i-- > 1;) {
      t[i] = combine(t[2 * i], t[2 * i + 1]);
    }
  }

  T get(size_t p) {
    return t[p + size];
  }

  void modify(size_t p, T value) {
    p += size;
    t[p] = value;
    while (p > 1) {
      p = p / 2;
      t[p] = combine(t[2 * p], t[2 * p + 1]);
    }
  }

  T query(size_t l, size_t r) {
    l += size;
    r += size;
    T left = init();
    T right = init();
    while (l < r) {
      if (l & 1) {
        left = combine(left, t[l]);
        l++;
      }
      if (r & 1) {
        r--;
        right = combine(t[r], right);
      }
      l = l / 2;
      r = r / 2;
    }
    return combine(left, right);
  }

 private:
  T combine(T left, T right) {
    return left + right;
  }

  T init() {
    return T();
  }
};

using EndPoint = std::pair<int, int>;

struct Solution {
  int n, m;
  std::vector<std::string> data;
  std::vector<std::vector<int>> as;
  std::vector<std::vector<int>> bs;
  void run(std::istream& in, std::ostream& out) {
    in >> n >> m;
    data.resize(n);
    for (int i = 0; i < n; i++) {
      in >> data[i];
    }
    as.assign(n, std::vector<int>(m, 0));
    bs.assign(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      int last = 0;
      for (int j = 0; j <= m; j++) {
        if (data[i][j] == '.' || j == m) {
          for (int k = last; k < j; k++) {
            as[i][k] = j - k - 1;
            bs[i][k] = k - last;
          }
          last = j + 1;
        }
      }
    }
    int64_t res = 0;
    for (int diag = 0; diag <= n + m - 2; diag++) {
      BinTree1<int> tree(m);
      std::priority_queue<EndPoint, std::vector<EndPoint>, std::greater<EndPoint>> endPoints;
      for (int i = 0; i < m && i <= diag; i++) {
        int j = diag - i;
        if (j >= n) continue;
        if (data[j][i] == '.') {
          while (!endPoints.empty()) {
            EndPoint p = endPoints.top();
            tree.modify(p.second, 0);
            endPoints.pop();
          }
          continue;
        }
        endPoints.emplace(i + as[j][i], i);
        tree.modify(i, 1);
        res += tree.query(std::max(0, i - bs[j][i]), i + 1);
        while (!endPoints.empty() && endPoints.top().first == i) {
          tree.modify(endPoints.top().second, 0);
          endPoints.pop();
        }
      }
    }
    out << res << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}