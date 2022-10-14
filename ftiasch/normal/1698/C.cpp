#line 1 "Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
  }

  template <typename T = int> T read() const {
    T v;
    std::cin >> v;
    return v;
  }

  template <typename T = int> std::vector<T> read_vector(size_t n) const {
    std::vector<T> v(n);
    for (size_t i = 0; i < n; ++i) {
      v[i] = read<T>();
    }
    return v;
  }
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-262300k22wOwVXEIuq.cpp"

bool check(std::vector<int> a) {
  int zeros = 0;
  std::vector<int> positives, negatives;
  for (int a : a) {
    if (a > 0) {
      positives.push_back(a);
    } else if (a < 0) {
      negatives.push_back(a);
    } else {
      zeros++;
    }
  }
  if (positives.size() >= 3 || negatives.size() >= 3) {
    return false;
  }
  a.clear();
  for (int x : positives) {
    a.push_back(x);
  }
  for (int x : negatives) {
    a.push_back(x);
  }
  for (int i = 1; i <= 3 && i <= zeros; ++i) {
    a.push_back(0);
  }
  int n = a.size();
  std::set<int> s;
  for (int a : a) {
    s.insert(a);
  }
  for (int k = 0; k < n; ++k) {
    for (int j = 0; j < k; ++j) {
      for (int i = 0; i < j; ++i) {
        if (!s.count(a[i] + a[j] + a[k])) {
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::cout << (check(io.read_vector(n)) ? "YES" : "NO") << "\n";
  }
}