#line 1 "/home/ftiasch/Documents/shoka/nd_vector.h"
#include <vector>

template <typename T, int N> struct NDVector {
  using Nested = NDVector<T, N - 1>;
  using Vector = std::vector<typename Nested::Vector>;

  template <typename... Args> static Vector create(int n, Args &&...args) {
    return Vector(n, Nested::create(std::forward<Args>(args)...));
  }
};

template <typename T> struct NDVector<T, 1> {
  using Vector = std::vector<T>;

  template <typename... Args> static Vector create(Args &&...args) {
    return Vector(std::forward<Args>(args)...);
  }
};
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
#line 3 "/tmp/tmp-147012BK4es141ZYlo.cpp"

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
#line 5 "/tmp/tmp-147012BK4es141ZYlo.cpp"

int main() {
  IO io;
  int n = io.read();
  std::vector<int> to(n << 1);
  for (int i = 0; i < n << 1; ++i) {
    to[i] = io.read() - 1;
  }
  std::vector<int> head(n << 1, -1), next(n << 1);
  for (int i = 0; i < n << 1; ++i) {
    next[i] = head[to[i ^ 1]];
    head[to[i ^ 1]] = i;
  }
  auto board = NDVector<int, 2>::create(2, n, -1);
  auto plan = NDVector<char, 3>::create(2, 2, n + 1);
  std::vector<bool> used_vertex(n << 1), used_edge(n);
  auto dfs =
      y_combinator([&](auto dfs, std::vector<int> &cycles, int u) -> void {
        cycles.push_back(u);
        if (!used_vertex[u]) {
          used_vertex[u] = true;
          for (int iterator = head[u]; ~iterator; iterator = next[iterator]) {
            if (!used_edge[iterator >> 1]) {
              used_edge[iterator >> 1] = true;
              dfs(cycles, to[iterator]);
              cycles.push_back(u);
            }
          }
        }
      });
  auto LR = [&](int t, int c) {
    plan[t][0][c] = plan[t][1][c] = 'L';
    plan[t][0][c + 1] = plan[t][1][c + 1] = 'R';
  };
  auto UD = [&](int t, int c) {
    plan[t][0][c] = 'U';
    plan[t][1][c] = 'D';
  };
  int offset = 0;
  for (int s = 0; s < n << 1; ++s) {
    if (!used_vertex[s]) {
      std::vector<int> cycles;
      dfs(cycles, s);
      cycles.pop_back();
      if (cycles.size() == 2) {
        std::cout << -1 << "\n";
        return 0;
      }
      int half = cycles.size() >> 1;
      if (half > 0) {
        for (int i = 0; i < half; ++i) {
          board[0][offset + i] = cycles[i];
          board[1][offset + half - 1 - i] = cycles[half + i];
        }
        if (half & 1) {
          UD(0, offset + half - 1);
          UD(1, offset);
          for (int i = offset; i + 2 < offset + half; i += 2) {
            LR(0, i);
            LR(1, i + 1);
          }
        } else {
          for (int i = offset; i < offset + half; i += 2) {
            LR(0, i);
          }
          UD(1, offset);
          for (int i = offset + 1; i + 2 < offset + half; i += 2) {
            LR(1, i);
          }
          UD(1, offset + half - 1);
        }
        offset += half;
      }
    }
  }
  std::cout << 2 << " " << n << "\n\n";
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << board[i][j] + 1 << " \n"[j + 1 == n];
    }
  }
  for (int t = 0; t < 2; ++t) {
    for (int i = 0; i < 2; ++i) {
      std::cout << plan[t][i].data() << "\n";
    }
  }
  // verify
  // auto edge = [](int a, int b) {
  //   if (a > b) {
  //     std::swap(a, b);
  //   }
  //   return std::make_pair(a, b);
  // };
  // {
  //   std::map<std::pair<int, int>, int> m;
  //   for (int i = 0; i < n << 1; i += 2) {
  //     m[edge(to[i], to[i ^ 1])]++;
  //   }
  //   std::cerr << m << std::endl;
  // }
  // for (int t = 0; t < 2; ++t) {
  //   std::map<std::pair<int, int>, int> m;
  //   for (int i = 0; i < 2; ++i) {
  //     for (int j = 0; j < n; ++j) {
  //       if (plan[t][i][j] == 'L') {
  //         m[edge(board[i][j], board[i][j + 1])]++;
  //       }
  //       if (plan[t][i][j] == 'U') {
  //         m[edge(board[i][j], board[i + 1][j])]++;
  //       }
  //     }
  //   }
  //   std::cerr << m << std::endl;
  // }
}