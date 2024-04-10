#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

const int p = 1'000'000'007;

struct Solution {
  int n;
  std::vector<int> direct;
  std::vector<std::vector<int>> reverse;
  std::vector<bool> flags;

  std::pair<int, int> dfs(int v) {
      flags[v] = true;
      int vertices = 1;
      int type = 0;
      if (direct[v] == v) {
          type = 1;
      } else if (direct[v] == -1) {
          type = 2;
      } else {
          if (!flags[direct[v]]) {
              auto res = dfs(direct[v]);
              vertices += res.first;
              if (type == 0) {
                  type = res.second;
              }
          }
      }
      for (int nv : reverse[v]) {
          if (!flags[nv]) {
              auto res = dfs(nv);
              vertices += res.first;
              if (type == 0) {
                  type = res.second;
              }
          }
      }
      return {vertices, type};
  }

  int getMult(int v) {
      auto res = dfs(v);
      if (res.second == 0) {
          return 2;
      } else if (res.second == 1) {
          return 1;
      } else { // res.second == 2
          return res.first;
      }
  }
  void run(std::istream& in, std::ostream& out) {
      in >> n;
      direct.assign(2 * n, -1);
      reverse.assign(2 * n, std::vector<int>());
      flags.assign(2 * n, false);
      for (int i = 0; i < n; i++) {
          int from, to;
          in >> from >> to;
          from--;
          to--;
          direct[from] = to;
          reverse[to].push_back(from);
      }
      int res = 1;
      for (int i = 0; i < 2 * n; i++) {
          if (!flags[i]) {
              res = (res * int64_t(getMult(i))) % p;
          }
      }
      out << res << "\n";
  }
};

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    Solution().run(std::cin, std::cout);
    return 0;
}