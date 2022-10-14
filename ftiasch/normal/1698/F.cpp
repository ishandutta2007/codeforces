#line 1 "/home/ftiasch/Documents/shoka/util.h"
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
#line 2 "/tmp/tmp-219097cyBQav9Sxrnu.cpp"

struct Solver : public std::vector<std::pair<int, int>> {
  static auto adjacent(int n, const std::vector<int> &a) {
    std::multiset<std::pair<int, int>> ms;
    for (int i = 1; i < n; ++i) {
      int x = a[i - 1];
      int y = a[i];
      if (x > y) {
        std::swap(x, y);
      }
      ms.emplace(x, y);
    }
    return ms;
  }

  Solver(int n_, std::vector<int> &&a_, std::vector<int> &&b_)
      : n{n_}, a{std::move(a_)}, b{std::move(b_)}, first(n) {
    valid = a.front() == b.front() && a.back() == b.back() &&
            adjacent(n, a) == adjacent(n, b);
    if (valid) {
      for (int i = 0; i + 1 < n; ++i) {
        if (a[i + 1] != b[i + 1]) {
          int x = a[i];
          int y = a[i + 1];
          int z = b[i + 1];
          // a | x y . . .
          // b | x z . . .
          // y != z
          if (find(i + 2, z, x) == n) {
            int k = find(i + 2, x, z);
            assert(k < n && a[k - 1] == x && a[k] == z);
            std::fill(ALL(first), -1);
            // i < p < k - 1
            // k < q < n
            for (int p = i; p < k - 1; ++p) {
              first[a[p]] = p;
            }
            int q = k;
            while (q < n && !~first[a[q]]) {
              q++;
            }
            assert(q < n);
            apply(first[a[q]], q + 1);
          }
          int k = find(i + 2, z, x);
          assert(k < n);
          apply(i, k + 1);
        }
      }
      // std::cerr << KV(a) << "\n" << KV(b) << std::endl;
    }
  }

  int find(int k, int x, int y) {
    while (k < n && (a[k - 1] != x || a[k] != y)) {
      k++;
    }
    return k;
  }

  void apply(int l, int r) {
    assert(a[l] == a[r - 1]);
    std::reverse(a.begin() + l, a.begin() + r);
    emplace_back(l + 1, r);
  }

  int n;
  std::vector<int> a, b, first;
  bool valid;
};

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      a[i] = io.read() - 1;
    }
    for (int i = 0; i < n; ++i) {
      b[i] = io.read() - 1;
    }
    Solver plan{n, std::move(a), std::move(b)};
    if (plan.valid) {
      std::cout << "YES\n";
      std::cout << plan.size() << "\n";
      for (auto [l, r] : plan) {
        std::cout << l << " " << r << "\n";
      }
    } else {
      std::cout << "NO\n";
    }
  }
}