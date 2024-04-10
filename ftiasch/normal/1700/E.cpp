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
#line 2 "/tmp/tmp-949623Zrjs2V0QKVY.cpp"

using Pair = std::pair<int, int>;

const std::vector<Pair> NEIGHBOURS{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
const std::vector<Pair> SELFS{{-1, 0}, {0, -1}, {0, 0}, {0, 1}, {1, 0}};

struct Solver {
  std::pair<int, int> solve() {
    int oks = 0;
    Pair not_ok;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (ok(i, j)) {
          oks++;
        } else {
          not_ok = {i, j};
        }
      }
    }
    if (oks == n * m) {
      return {0, 0};
    }
    std::vector<Pair> candidates, affects;
    {
      auto [x, y] = not_ok;
      for (auto [dx, dy] : SELFS) {
        int xx = x + dx;
        int yy = y + dy;
        if (1 <= xx && xx <= n && 1 <= yy && yy <= m) {
          candidates.emplace_back(xx, yy);
        }
      }
    }
    int now = 0, ways = 0;
    std::vector<std::vector<int>> timestamp(n + 1, std::vector<int>(m + 1));
    for (int px = 1; px <= n; ++px) {
      for (int py = 1; py <= m; ++py) {
        bool is_candidate =
            std::find(ALL(candidates), Pair{px, py}) != candidates.end();
        for (auto [qx, qy] : candidates) {
          if (!is_candidate || Pair{px, py} < Pair{qx, qy}) {
            ++now;
            affects.clear();
            for (auto [x, y] : {Pair{px, py}, Pair{qx, qy}}) {
              for (auto [dx, dy] : SELFS) {
                int xx = x + dx;
                int yy = y + dy;
                if (1 <= xx && xx <= n && 1 <= yy && yy <= m &&
                    timestamp[xx][yy] != now) {
                  timestamp[xx][yy] = now;
                  affects.emplace_back(xx, yy);
                }
              }
            }
            int backup = oks;
            for (auto [x, y] : affects) {
              oks -= ok(x, y);
            }
            std::swap(a[px][py], a[qx][qy]);
            for (auto [x, y] : affects) {
              oks += ok(x, y);
            }
            if (oks == n * m) {
              ways++;
            }
            std::swap(a[px][py], a[qx][qy]);
            oks = backup;
          }
        }
      }
    }
    if (ways) {
      return {1, ways};
    }
    return {2, 0};
  }

  bool ok(int x, int y) {
    if (1 <= x && x <= n && 1 <= y && y <= m) {
      if (a[x][y] == 1) {
        return true;
      }
      for (auto [dx, dy] : NEIGHBOURS) {
        if (a[x + dx][y + dy] < a[x][y]) {
          return true;
        }
      }
    }
    return false;
  }

  int n, m;
  std::vector<std::vector<int>> a;
};

int main() {
  IO io;
  int n = io.read();
  int m = io.read();
  std::vector<std::vector<int>> a(n + 2, std::vector<int>(m + 2, INT_MAX));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      a[i][j] = io.read();
    }
  }
  auto [steps, ways] = Solver{n, m, a}.solve();
  if (steps == 1) {
    std::cout << "1 " << ways << "\n";
  } else {
    std::cout << steps << "\n";
  }
}