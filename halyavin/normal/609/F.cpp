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
#include <map>


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
      t[i] = std::max(t[2 * i], t[2 * i + 1]);
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
      t[p] = std::max(t[2 * p], t[2 * p + 1]);
    }
  }

  void modifyMax(size_t p, T value) {
    p += size;
    t[p] = value;
    while (p > 1) {
      p = p / 2;
      if (t[p] >= value) break;
      t[p] = value;
    }
  }

  size_t getNode(size_t node, T value) {
    while (node < size) {
      if (t[2 * node] >= value) {
        node = 2 * node;
      } else {
        node = 2 * node + 1;
      }
    }
    return node - size;
  }

  size_t query(size_t l, size_t r, T value) {
    l += size;
    r += size;
    size_t minR = 0;
    while (l < r) {
      if (l & 1) {
        if (t[l] >= value) return getNode(l, value);
        l++;
      }
      if (r & 1) {
        r--;
        if (t[r] >= value) minR = r;
      }
      l = l / 2;
      r = r / 2;
    }
    return minR == 0 ? size : getNode(minR, value);
  }

};

struct frog {
  int num;
  int x;
  int max;
};

void run(std::istream& in, std::ostream& out) {
  int n, m;
  in >> n >> m;
  std::vector<frog> init(n);
  for (int i = 0; i < n; i++) {
    int x, t;
    in >> x >> t;
    init[i].x = x;
    init[i].max = x + t;
    init[i].num = i;
  }
  std::sort(init.begin(), init.end(), [](const frog& left, const frog& right) { return left.x < right.x; });
  std::vector<int> start(n);
  std::multimap<int, int> insects;
  for (int i = 0; i < n; i++) {
    start[i] = init[i].max;
  }
  BinTree1<int> tree(start);
  std::vector<int> eat(n);
  std::vector<int> res(n);
  for (int i = 0; i < m; i++) {
    int value, size;
    in >> value >> size;
    int pos = tree.query(0, n, value);
    if (pos >= n || init[pos].x > value) {
      insects.emplace(value, size);
      continue;
    }
    int frogPos = init[pos].num;
    int curBegin = start[pos];
    int curEnd = start[pos] + size;
    int eaten = 1;
    auto it = insects.upper_bound(curBegin);
    while (it != insects.end() && it->first <= curEnd) {
      eaten++;
      curEnd += it->second;
      it = insects.erase(it);
    }
    eat[frogPos] += eaten;
    start[pos] = curEnd;
    tree.modifyMax(pos, start[pos]);
  }
  for (int i = 0; i < n; i++) {
    res[init[i].num] = start[i] - init[i].x;
  }
  for (int i = 0; i < n; i++) {
    out << eat[i] << " " << res[i]  << "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}