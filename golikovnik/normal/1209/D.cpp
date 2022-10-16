#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::cerr;
using std::vector;
using std::set;
using std::map;
using std::pair;
using ui32 = std::uint32_t;
using i32 = std::int32_t;
using ui64 = std::uint64_t;
using i64 = std::int64_t;
using std::size_t;
using std::sort;

int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(nullptr);

  unsigned n, k;
  cin >> k >> n;
  vector<vector<unsigned>> graph(k);
  for (size_t i = 0; i != n; ++i) {
    unsigned u, v;
    cin >> u >> v;
    --u;
    --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<bool> used(k);
  unsigned sz = 0;
  unsigned answer = 0;
  std::function<void(unsigned)> dfs = [&](auto u) {
    used[u] = true;
    ++sz;
    for (auto v : graph[u]) {
      if (!used[v]) {
        dfs(v);
      }
    }
  };

  for (unsigned i = 0; i != k; ++i) {
    if (!used[i]) {
      dfs(i);
      answer += sz - 1;
      sz = 0;
    }
  }

  cout << n - answer << '\n';
  return 0;
}