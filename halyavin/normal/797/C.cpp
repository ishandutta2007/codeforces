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
  using T = std::pair<int, int>;
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
    if (left.second <= right.second) {
      return {left.first, left.second};
    }
    return {right.first, right.second};
  }

  T init() {
    return {-1, 256};
  }
};

void removeElement(std::vector<std::pair<int, int>>& list, int elem) {
  int prev = list[elem].first;
  int next = list[elem].second;
  if (prev != -1) {
    list[prev].second = next;
  }
  if (next != -1) {
    list[next].first = prev;
  }
}

void run(std::istream &in, std::ostream &out) {
  std::string s;
  in >> s;
  std::vector<std::pair<int, int>> init;
  init.reserve(s.length());
  for (size_t i = 0; i < s.length(); i++) {
    init.emplace_back(i, s[i]);
  }
  BinTree1 tree(init);
  std::vector<std::pair<int, int>> list(s.length());
  for (int i = 0; i < s.length(); i++) {
    list[i].first = i - 1;
    list[i].second = i + 1;
  }
  list.back().second = -1;
  std::string answer;
  int pos = -1;
  for (size_t i = 0; i < s.length(); i++) {
    std::pair<int, int> optRight = tree.query(pos + 1, s.length());
    if (pos != -1 && list[pos].first != -1) {
      int prev = list[pos].first;
      if (s[prev] <= optRight.second) {
        optRight.second = s[prev];
        optRight.first = prev;
      }
    }
    answer.push_back(optRight.second);
    if (pos != -1) {
      removeElement(list, pos);
    }
    pos = optRight.first;
    tree.modify(pos, {-1, 256});
  }
  out << answer << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}