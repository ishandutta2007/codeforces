#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::set;
using std::map;
using i32 = std::int32_t;
using ui32 = std::uint32_t;
using i64 = std::int64_t;
using ui64 = std::uint64_t;
using std::pair;
using std::tuple;
using std::sort;
using std::size_t;

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  size_t n;
  cin >> n;
  vector<ui64> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  vector<vector<size_t>> graph(n);
  for (size_t i = 1; i != n; ++i) {
    size_t u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  size_t const LOG = 20;
  vector<vector<ui64>> up_g(n, vector<ui64>(LOG));
  vector<vector<size_t>> up(n, vector<size_t>(LOG));
  vector<size_t> p(n);
  vector<size_t> d(n);
  std::function<void(size_t, size_t)> dfs = [&](auto v, auto par) {
    if (v != par) {
      d[v] = d[par] + 1;
    }
    p[v] = par;
    up[v][0] = v;
    up_g[v][0] = a[v];
    for (auto k = 1u; k < LOG; ++k) {
      up[v][k] = up[p[up[v][k - 1]]][k - 1];
      up_g[v][k] = std::gcd(up_g[v][k - 1], up_g[p[up[v][k - 1]]][k - 1]);
    }
    for (auto u : graph[v]) {
      if (u != par) {
        dfs(u, v);
      }
    }
  };
  dfs(0, 0);
  vector<size_t> lg(n + 1);
  for (size_t i = 2; i <= n; ++i) {
    lg[i] = lg[i / 2] + 1;
  }
  ui64 answer = 0;
  ui64 constexpr MOD = 1e9 + 7;
  auto add = [MOD](ui64 x, ui64 y) -> ui64 {
    x += y;
    if (x >= MOD) {
      x -= MOD;
    }
    return x;
  };
  auto multiply = [MOD](ui64 x, ui64 y) -> ui64 {
    return x * y % MOD;
  };
  auto preserves_gcd = [](ui64 x, ui64 y) -> bool {
//    return std::gcd(x, y) == y;
      if (!y) {
        return !x;
      }
      return x % y == 0;
  };
  for (size_t v = 0; v != n; ++v) {
    ui64 cur_g = a[v];
    ui64 cur_v = v;
    while (true) {
      auto top = cur_v;
      for (int k = lg[d[v] + 1]; k >= 0; --k) {
        if (preserves_gcd(up_g[top][k], cur_g)) {
          top = up[top][k];
          if (!top) {
            break;
          }
          if (preserves_gcd(a[p[top]], cur_g)) {
            top = p[top];
          } else {
            break;
          }
        }
      }
      answer = add(answer, multiply(cur_g, d[cur_v] - d[top] + 1));
      if (!top) {
        break;
      }
      cur_v = p[top];
      cur_g = std::gcd(cur_g, a[cur_v]);
    }
  }
  cout << answer << '\n';
  return 0;
}