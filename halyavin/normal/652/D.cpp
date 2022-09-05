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
#include <tuple>

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

struct interval {
  int idx;
  int left;
  int right;
  interval() = default;
  interval(int idx, int left, int right) : idx(idx), left(left), right(right) {}
};

size_t compress(std::vector<interval>& intervals) {
  std::vector<std::tuple<int, int, int>> points;
  for (interval& t : intervals) {
    points.emplace_back(t.left, t.idx, 0);
    points.emplace_back(t.right, t.idx, 1);
  }
  std::sort(points.begin(), points.end());
  for (size_t i = 0; i < points.size(); i++) {
    if (std::get<2>(points[i]) == 0) {
      intervals[std::get<1>(points[i])].left = i;
    } else {
      intervals[std::get<1>(points[i])].right = i;
    }
  }
  return points.size();
}

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<interval> intervals(n);
  for (int i = 0; i < n; i++) {
    intervals[i].idx = i;
    in >> intervals[i].left >> intervals[i].right;
  }
  size_t comp_size = compress(intervals);
  std::sort(intervals.begin(), intervals.end(), [](const interval& a, const interval& b) {
    return a.left > b.left;
  });
  std::vector<int> ans(n);
  BinTree1<int> tree(comp_size);
  for (interval& t : intervals) {
    ans[t.idx] = tree.query(t.left, t.right);
    tree.modify(t.right, 1);
  }
  for (int i = 0; i < n; i++) {
    out << ans[i] << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}