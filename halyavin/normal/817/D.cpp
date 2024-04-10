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
#include <array>

struct Solution {
  int n;
  std::vector<int> as;
  std::array<std::vector<int>, 20> tree;
  template<class F>
  void buildTree(F f, int init) {
    for (auto& layer : tree) {
      layer.assign(n, init);
    }
    tree[0] = as;
    for (size_t l = 1; l < tree.size(); l++) {
      auto& prevLayer = tree[l - 1];
      auto& layer = tree[l];
      int shift = 1 << (l - 1);
      for (int i = 0; i < n; i++) {
        if (i + shift < n) {
          layer[i] = f(prevLayer[i], prevLayer[i + shift]);
        } else {
          layer[i] = prevLayer[i];
        }
      }
    }
  }

  template<class F>
  int getInterval(F f, int l, int r) {
    int layer = 31 - __builtin_clz(r - l);
    return f(tree[layer][l], tree[layer][r - (1 << layer)]);
  }

  template<class F, class Comp>
  uint64_t updateAnswer(F f, int initValue, Comp comp) {
    buildTree(f, initValue);
    uint64_t res = 0;
    for (int i = 0; i < n; i++) {
      int l = -1;
      int r = i;
      while (r - l > 1) {
        int m = (l + r) / 2;
        if (comp(getInterval(f, m, i), as[i])) {
          r = m;
        } else {
          l = m;
        }
      }
      int64_t c = i - r + 1;
      l = i + 1;
      r = n + 1;
      while (r - l > 1) {
        int m = (l + r) / 2;
        if (!comp(as[i], getInterval(f, i + 1, m))) {
          l = m;
        } else {
          r = m;
        }
      }
      c *= l - i;
      res += c * as[i];
    }
    return res;
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    as.resize(n);
    for (int i = 0; i < n; i++) {
      in >> as[i];
    }

    uint64_t ans =
        updateAnswer([](int a, int b) { return std::max(a, b); }, 0, std::less<int>()) -
        updateAnswer([](int a, int b) { return std::min(a, b); }, 1000001, std::greater<int>());
    out << ans << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}