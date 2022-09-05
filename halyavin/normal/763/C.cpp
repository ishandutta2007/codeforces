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
std::pair<T, T> gcd2(T x, T y) {
  if (x == 0) {
    return {0, 1};
  }
  T s = y / x;
  std::pair<T, T> res = gcd2(y % x, x);
  return {res.second - s * res.first, res.first};
}

template<class T>
T inv(T x, T p) {
  x = x % p;
  if (x < 0) {
    x += p;
  }
  std::pair<T, T> res = gcd2(x, p);
  if (res.first < 0) {
    res.first += p;
  }
  if (res.first >= p) {
    res.first -= p;
  }
  return res.first;
}

std::pair<int, int> find(std::vector<int>& as, int m) {
  if (as.size() == 1) {
    return {as[0], 1};
  }
  int n = as.size();
  int diff = as[1] - as[0];
  std::vector<int> xs(as.size());
  for (size_t i = 0; i < as.size(); i++) {
    xs[i] = (as[i] + diff) % m;
  }
  std::sort(xs.begin(), xs.end());
  int count = 0;
  size_t j = 0;
  for (size_t i = 0; i < as.size(); i++) {
    while (j < xs.size() && xs[j] < as[i]) j++;
    if (j < xs.size() && as[i] == xs[j]) count++;
  }
  int k = n - count;
  int d = diff * int64_t(inv(k, m)) % m;
  for (size_t i = 0; i < as.size(); i++) {
    xs[i] = (as[i] + d) % m;
  }
  std::sort(xs.begin(), xs.end());
  count = 0;
  j = 0;
  int last = 0;
  for (size_t i = 0; i < as.size(); i++) {
    while (j < xs.size() && xs[j] < as[i]) j++;
    if (j < xs.size() && as[i] == xs[j]) {
      count++;
    } else {
      last = as[i];
    }
  }
  if (count != n - 1) {
    return {-1, -1};
  }
  return {last, d};
};

void run(std::istream &in, std::ostream &out) {
  int n, m;
  in >> m >> n;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  std::sort(as.begin(), as.end());
  if (n == m) {
    out << 0 << " " << 1 << std::endl;;
    return;
  }
  if (2 * n > m) {
    std::vector<int> bs;
    int cur = 0;
    for (int i = 0; i < m; i++) {
      if (cur >= n || as[cur] != i) {
        bs.push_back(i);
      } else {
        cur++;
      }
    }
    std::pair<int, int> res = find(bs, m);
    if (res.second < 0) {
      out << -1 << std::endl;
      return;
    }
    res.first = (res.first + res.second * int64_t(m - n)) % m;
    out << res.first << " " << res.second << std::endl;
    return;
  }
  std::pair<int, int> res = find(as, m);
  if (res.second < 0) {
    out << -1 << std::endl;
    return;
  }
  out << res.first << " " << res.second << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}