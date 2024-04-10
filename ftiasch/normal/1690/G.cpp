#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <iostream>
#include <vector>
#include <queue>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::cin.sync_with_stdio(false); }

  template <typename T = int> T read() {
    T v;
    std::cin >> v;
    return v;
  }

  template <typename T = int> std::vector<T> read_vector(size_t n) {
    std::vector<T> v(n);
    for (size_t i = 0; i < n; ++i) {
      v[i] = read<T>();
    }
    return v;
  }
};

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-11630ROQGQkg0ng8A.cpp"

#include <bits/stdc++.h>

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    int q = io.read();
    auto a = io.read_vector(n);
    std::map<int, int> intervals;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n && a[i] <= a[j]) {
        j++;
      }
      intervals[i] = a[i];
      i = j;
    }
    intervals[n] = -1;
    while (q--) {
      int x = io.read() - 1;
      a[x] -= io.read();
      auto i = std::prev(intervals.upper_bound(x));
      if (i->second > a[x]) {
        intervals[x] = a[x];
        i++;
        i = intervals.upper_bound(x);
        while (i != intervals.end() && a[x] <= i->second) {
          auto backup = i;
          i++;
          intervals.erase(backup);
        }
      }
      std::cout << intervals.size() - 1 << " \n"[!q];
    }
  }
}