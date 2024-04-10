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
struct LazyBinMaxTree {
  size_t size;
  std::vector<T> t;
  std::vector<T> mod;

  LazyBinMaxTree(size_t N) :
      size(N),
      t(2 * N),
      mod(N) { }

  LazyBinMaxTree(const std::vector<T>& other) :
      size(other.size()),
      t(2 * other.size()),
      mod(other.size()) {
      std::copy(other.begin(), other.end(), t.begin() + size);
      for (size_t i = size; i-- > 1;) {
          t[i] = combine(t[2 * i], t[2 * i + 1]);
      }
  }

  T query(size_t l, size_t r) {
      if (l == r) return init();
      l += size;
      r += size;
      T leftMax = init();
      T rightMax = init();
      while (l < r) {
          if (leftMax != init()) {
              leftMax += mod[l - 1];
          }
          if (l & 1) {
              leftMax = combine(leftMax, t[l]);
              l++;
          }
          if (rightMax != init()) {
              rightMax += mod[r];
          }
          if (r & 1) {
              r--;
              rightMax = combine(t[r], rightMax);
          }
          l /= 2;
          r /= 2;
      }
      l--;
      while (r > 0) {
          if (leftMax != init()) leftMax += mod[l];
          if (rightMax != init()) rightMax += mod[r];
          l /= 2;
          r /= 2;
      }
      return combine(leftMax, rightMax);
  }

  void modify(size_t l, size_t r, T value) {
      if (l == r) return;
      l += size;
      r += size;
      bool leftAdd = false;
      bool rightAdd = false;
      while (l < r) {
          if (leftAdd) {
              restore(l - 1);
          }
          if (l & 1) {
              if (l < size) {
                  mod[l] += value;
              }
              t[l] += value;
              leftAdd = true;
              l++;
          }
          if (rightAdd) {
              restore(r);
          }
          if (r & 1) {
              r--;
              if (r < size) {
                  mod[r] += value;
              }
              t[r] += value;
              rightAdd = true;
          }
          l /= 2;
          r /= 2;
      }
      l--;
      while (r > 0) {
          if (leftAdd) restore(l);
          if (rightAdd) restore(r);
          l /= 2;
          r /= 2;
      }
  }

  T query(size_t p) {
      p += size;
      T res = t[p];
      while (p > 1) {
          p = p / 2;
          res += mod[p];
      }
      return res;
  }

  void modify(size_t p, T value) {
      p += size;
      t[p] += value;
      while (p > 1) {
          p = p / 2;
          restore(p);
      }
  }

 private:
  void restore(size_t p) {
      t[p] = combine(t[2 * p], t[2 * p + 1]) + mod[p];
  }

  T combine(T left, T right) {
      return std::min(left, right);
  }

  T init() {
      return std::numeric_limits<T>::max();
  }
};

void run(std::istream &in, std::ostream &out) {
    int n;
    in >> n;
    std::vector<std::pair<int, int>> tvs(n);
    for (int i = 0; i < n; i++) {
        in >> tvs[i].first >> tvs[i].second;
        tvs[i].second++;
    }
    std::vector<int> idx(2 * n);
    for (int i = 0; i < n ;i++) {
        idx[2 * i] = tvs[i].first;
        idx[2 * i + 1] = tvs[i].second;
    }
    std::sort(idx.begin(), idx.end());
    auto it = std::unique(idx.begin(), idx.end());
    idx.erase(it, idx.end());
    for (int i = 0; i < n; i++) {
        tvs[i].first = std::lower_bound(idx.begin(), idx.end(), tvs[i].first) - idx.begin();
        tvs[i].second = std::lower_bound(idx.begin(), idx.end(), tvs[i].second) - idx.begin();
    }
    LazyBinMaxTree<int> tree(idx.size());
    for (int i = 0; i < n; i++) {
        tree.modify(tvs[i].first, tvs[i].second, 1);
    }
    for (int i = 0; i < n; i++) {
        if (tree.query(tvs[i].first, tvs[i].second) > 1) {
            out << i + 1 << "\n";
            return;
        }
    }
    out << -1 << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}