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
struct BinATree {
  size_t size;
  std::vector<T> t;

  BinATree(const std::vector<T>& other) :
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
    return std::max(left, right);
  }

  T init() {
    return -1000000001;
  }
};

template<class T>
struct BinBTree {
  size_t size;
  std::vector<T> t;

  BinBTree(const std::vector<T>& other) :
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
    return 1000000001;
  }
};

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  std::vector<int> bs(n);
  for (int i = 0; i < n; i++) {
    in >> bs[i];
  }

  as.push_back(1000000001);
  bs.push_back(-1000000001);

  BinATree<int> aTree(as);
  BinBTree<int> bTree(bs);

  int64_t res = 0;
  size_t l = 0;
  size_t r = 0;
  for (size_t i = 0; i + 1 < as.size(); i++) {
    r = std::max(r, i);
    l = std::max(l, i);
    {
      int maxA = aTree.query(i, l + 1);
      int minB = bTree.query(i, l + 1);
      while (l < n && maxA < minB) {
        l++;
        maxA = std::max(maxA, as[l]);
        minB = std::min(minB, bs[l]);
      }
    }
    {
      int maxA = aTree.query(i, r + 1);
      int minB = bTree.query(i, r + 1);
      while (r < n && maxA <= minB) {
        r++;
        maxA = std::max(maxA, as[r]);
        minB = std::min(minB, bs[r]);
      }
    }
    res += r - l;
  }
  out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}