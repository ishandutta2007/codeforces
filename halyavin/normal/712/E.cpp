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

struct BinTree1 {
  using T = std::pair<double, double>;
  size_t size;
  std::vector<T> t;

  BinTree1(size_t N) :
      size(N),
      t(2 * N) {}

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
    bool leftFlag = false;
    bool rightFlag = false;
    while (l < r) {
      if (l & 1) {
        if (leftFlag) {
          left = combine(left, t[l]);
        } else {
          leftFlag = true;
          left = t[l];
        }
        l++;
      }
      if (r & 1) {
        r--;
        if (rightFlag) {
          right = combine(t[r], right);
        } else {
          right = t[r];
          rightFlag = true;
        }
      }
      l = l / 2;
      r = r / 2;
    }
    if (!leftFlag) {
      return right;
    }
    if (!rightFlag) {
      return left;
    }
    return combine(left, right);
  }

 private:
  T combine(T left, T right) {
    return {left.first * right.first / (1 - left.second * (1 - right.first)),
            right.second + left.second * right.first * (1 - right.second) / (1 - left.second * (1 - right.first))
    };
  }

  T init() {
    return {0, 0};
  }
};

void run(std::istream& in, std::ostream& out) {
  int n, q;
  in >> n >> q;
  std::vector<std::pair<double, double>> start(n);
  for (int i = 0; i < n; i++) {
    double a, b;
    in >> a >> b;
    start[i] = std::make_pair(a / b, a / b);
  }
  BinTree1 tree(start);
  out.precision(10);
  for (int i = 0; i < q; i++) {
    int type;
    in >> type;
    switch (type) {
      case 1: {
        size_t index;
        double a, b;
        in >> index >> a >> b;
        index--;
        tree.modify(index, std::make_pair(a / b, a / b));
        break;
      }
      case 2: {
        size_t l, r;
        in >> l >> r;
        l--;
        r--;
        out << tree.query(l, r + 1).first << std::endl;
      }
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}