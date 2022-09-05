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

std::vector<int> buildPrev(const std::vector<int>& as) {
  std::vector<int> result(as.size());
  std::map<int, int> lastPos;
  for (size_t i = 0; i < as.size(); i++) {
    auto it = lastPos.find(as[i]);
    if (it == lastPos.end()) {
      result[i] = -1;
    } else {
      result[i] = it->second;
    }
    lastPos[as[i]] = i;
  }
  return result;
}

template<class T>
struct BinTree2 {
  size_t size;
  std::vector<T> t;

  BinTree2(size_t N) :
      size(N),
      t(2 * N) { }

  BinTree2(const std::vector<T>& other) :
      size(other.size()),
      t(2 * other.size()) {
    std::copy(other.begin(), other.end(), t.begin() + size);
  }

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
    return left ^ right;
  }

  T init() {
    return T();
  }
};

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  std::vector<int> prev = buildPrev(as);
  std::vector<int> xorAs(n + 1);
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    cur ^= as[i - 1];
    xorAs[i] = cur;
  }
  int m;
  in >> m;
  std::vector<std::pair<int, int>> queries(m);
  std::vector<std::vector<int>> queriesByR(n);
  for (int i = 0; i < m; i++) {
    in >> queries[i].first >> queries[i].second;
    queries[i].first--;
    queries[i].second--;
    queriesByR[queries[i].second].push_back(i);
  }
  BinTree2<int> tree(n);
  std::vector<int> answer(m);
  for (int i = 0; i < n; i++) {
    int r = i;
    int l = prev[i];
    tree.modify(l + 1, r + 1, as[i]);
    for (int query : queriesByR[i]) {
      answer[query] = tree.query(queries[query].first) ^ xorAs[queries[query].second + 1] ^ xorAs[queries[query].first];
    }
  }
  for (int i = 0; i < m; i++) {
    out << answer[i] << "\n";
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}