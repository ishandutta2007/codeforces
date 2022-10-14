#line 1 "/home/ftiasch/Documents/shoka/y_combinator.h"
#include <functional>

// Authored by ecnerwala

namespace details {

template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}

  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

} // namespace details

template <class Fun> decltype(auto) y_combinator(Fun &&fun) {
  return details::y_combinator_result<std::decay_t<Fun>>(
      std::forward<Fun>(fun));
}
#line 2 "/tmp/tmp-1173430NSxjoEUg25KZ.cpp"

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
#line 4 "/tmp/tmp-1173430NSxjoEUg25KZ.cpp"

struct Set : public std::set<int> {
  int delta = 0;
};

int main() {
  IO io;
  int n = io.read();
  auto a = io.read_vector(n);
  std::vector<std::vector<int>> tree(n);
  for (int i = 0; i < n - 1; ++i) {
    int a = io.read() - 1;
    int b = io.read() - 1;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  auto solve =
      y_combinator([&](auto solve, int p, int u) -> std::pair<int, Set> {
        int ru = 0;
        Set su;
        bool changed = false;
        for (int v : tree[u]) {
          if (v != p) {
            auto [rv, sv] = solve(u, v);
            ru += rv;
            if (su.size() < sv.size()) {
              std::swap(su, sv);
            }
            for (int y : sv) {
              changed |= su.count(a[u] ^ (y ^ sv.delta) ^ su.delta);
            }
            for (int y : sv) {
              su.insert((y ^ sv.delta) ^ su.delta);
            }
          }
        }
        changed |= su.count(a[u] ^ su.delta);
        su.insert(su.delta);
        su.delta ^= a[u];
        if (changed) {
          return {ru + 1, {}};
        }
        return {ru, std::move(su)};
      });
  std::cout << solve(-1, 0).first << "\n";
}