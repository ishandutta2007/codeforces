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

  template <typename T> std::ostream &operator<<(const T &o) {
    return std::cout << o;
  }
};

template <typename T, typename Compare = std::less<T>>
struct PQ : public std::priority_queue<T, std::vector<T>, Compare> {
  T pop() {
    using Base = std::priority_queue<T, std::vector<T>, Compare>;
    auto t = Base::top();
    Base::pop();
    return t;
  }
};
#line 2 "/tmp/tmp-1173430YJjwmBJa4Xx7.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    auto s = io.read<std::string>();
    int n = s.size();
    std::vector<std::pair<int, int>> suf(n + 1);
    suf[n] = {0, 0};
    for (int i = n; i--;) {
      auto [l, r] = suf[i + 1];
      if (s[i] == '?') {
        l--;
        r++;
      } else {
        int c = s[i] == '(' ? -1 : 1;
        l += c;
        r += c;
      }
      if (l < 0) {
        l += 2;
      }
      suf[i] = {l, r};
    }
    int pre = 0;
    bool ok = true;
    for (int i = 0; i < n && ok; ++i) {
      if (s[i] == '?') {
        auto [l, r] = suf[i + 1];
        if (l <= pre + 1 && pre + 1 <= r) {
          if (l <= pre - 1) {
            ok = false;
          }
          pre++;
        } else {
          pre--;
        }
      } else {
        pre += (s[i] == '(' ? 1 : -1);
      }
    }
    std::cout << (ok ? "YES" : "NO") << "\n";
  }
}