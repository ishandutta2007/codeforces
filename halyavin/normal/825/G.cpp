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
#include <memory>

template<class T>
struct BinTree1 {
  size_t size;
  std::vector<T> t;

  BinTree1(size_t N) :
      size(N),
      t(2 * N, init()) {}

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
      return std::min(left, right);
  }

  T init() {
      return 1000000000;
  }
};

struct Solution {
  int n;
  std::unique_ptr<BinTree1<int>> tree;
  std::vector<std::vector<int>> graph;
  std::vector<int> left;
  std::vector<int> right;
  std::vector<int> value;
  int dfs(int v, int prev, int order, int cur) {
      value[v] = cur;
      left[v] = order;
      order++;
      for (int nv : graph[v]) {
          if (nv != prev) {
              order = dfs(nv, v, order, std::min(cur, nv));
          }
      }
      right[v] = order;
      return order;
  }

  void init(int root) {
      left.resize(n);
      right.resize(n);
      value.resize(n);
      dfs(root, -1, 0, root);
  }

  void run(std::istream& in, std::ostream& out) {
      int q;
      in >> n >> q;
      tree.reset(new BinTree1<int>(n));
      graph.assign(n, std::vector<int>());
      for (int i = 0; i < n - 1; i++) {
          int from, to;
          in >> from >> to;
          from--;
          to--;
          graph[from].push_back(to);
          graph[to].push_back(from);
      }
      int t, x;
      in >> t >> x;
      q--;
      init(x % n);
      int last = 0;
      int minBlack = 1000000000;
      for (int request = 0; request < q; request++) {
          in >> t >> x;
          x = (x + last) % n;
          if (t == 1) {
              minBlack = std::min(minBlack, value[x]);
//              tree->modify(x, value[x]);
          } else {
              int res = std::min(value[x], minBlack);
//              if (left[x] > 0) {
//                  res = std::min(res, tree->query(0, left[x]));
//              }
//              if (right[x] < n) {
//                  res = std::min(res, tree->query(right[x], n));
//              }
              last = res + 1;
              out << last << std::endl;
          }
      }
  }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}