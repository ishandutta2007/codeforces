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

template <typename T>
using MinPQ = std::priority_queue<T, std::vector<T>, std::greater<T>>;
#line 2 "/tmp/tmp-300543ChvTTYh4Ojn4.cpp"

int main() {
  IO io;
  int T = io.read();
  while (T--) {
    int n = io.read();
    std::vector<int> a(n + 2);
    for (int i = 1; i <= n; ++i) {
      a[i] = io.read() - 1;
    }
    std::vector<int> dp(n + 2), count(n);
    for (int i = n; i >= 0; --i) {
      a[n + 1] = a[i];
      dp[i] = -(n + 2);
      if (!i || a[i] == a[i + 1]) {
        dp[i] = std::max(dp[i], dp[i + 1] + 1);
      }
      int max_count = 0;
      for (int j = i + 1; j <= n; ++j) {
        max_count = std::max(max_count, ++count[a[j]]);
        if (max_count + max_count <= j - i && (~(j - i) & 1) &&
            (!i || a[i] == a[j + 1])) {
          dp[i] = std::max(dp[i], dp[j + 1] + 1);
        }
      }
      for (int j = i + 1; j <= n; ++j) {
        count[a[j]]--;
      }
    }
    std::cout << dp[0] - 1 << "\n";
  }
}