#line 1 "/home/ftiasch/Documents/shoka/util.h"
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using Long = long long;
using u64 = uint64_t;

struct IO {
  IO() { std::ios::sync_with_stdio(false); }

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
#line 2 "D_Circular_Spanning_Tree.cpp"

struct Solver {
  bool solve() {
    int ones = std::count(ALL(s), '1');
    if (ones == 0 || (ones & 1)) {
      return false;
    }
    std::cout << "YES\n";
    if (ones == s.size()) {
      for (int i = 1; i < n; ++i) {
        out(0, i);
      }
    } else {
      int r = 0;
      while (s[r] != '0' || s[(r + n - 1) % n] != '1') {
        r++;
      }
      // s[r-1] = '1' & s[r] == '0'
      for (int i = 1; i < n;) {
        int j = i;
        out(0, j, r);
        while (s[(r + j) % n] == '0') {
          out(j, j + 1, r);
          j++;
        }
        i = j + 1;
      }
    }
    return true;
  }

  void out(int i, int j, int offset = 0) const {
    std::cout << (offset + i) % n + 1 << " " << (offset + j) % n + 1 << "\n";
  }

  int n;
  std::string s;
};

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    auto s = io.read<std::string>();
    if (!Solver{n, s}.solve()) {
      std::cout << "NO\n";
    }
  }
}