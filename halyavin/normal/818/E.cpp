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

template<class T>
struct BinTree2 {
  size_t size;
  std::vector<T> t;
  int k;

  BinTree2(size_t N, int k) :
      size(N),
      t(2 * N, 1),
      k(k) { }

  void modify(size_t l, size_t r, T value) {
      l += size;
      r += size;
      while (l < r) {
          if (l & 1) {
              t[l] = combine(t[l], value);
              l++;
          }
          if (r & 1) {
              r--;
              t[r] = combine(t[r], value);
          }
          l /= 2;
          r /= 2;
      }
  }

  T query(size_t p) {
      p += size;
      T res = init();
      while (p > 0) {
          res = combine(t[p], res);
          p = p / 2;
      }
      return res;
  }

 private:
  T combine(T left, T right) {
      return (int64_t(left) * right) % k;
  }

  T init() {
      return 1;
  }
};

void run(std::istream &in, std::ostream &out) {
    int n, k;
    in >> n >> k;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    BinTree2<int> tree(n, k);
    int64_t res = 0;
    int pos = n;
    for (int i = n - 1; i >= 0; i--) {
        tree.modify(i, n, as[i]);
        while (pos > i && tree.query(pos - 1) == 0) {
            pos--;
        }
        res += n - pos;
    }
    out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}