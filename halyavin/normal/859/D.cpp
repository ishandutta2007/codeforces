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
#include <map>
#include <array>

struct Solution {

  std::map<std::array<int, 3>, double> optRestricted;
  std::map<std::array<int, 3>, double> winProb;
  std::vector<std::vector<double>> p;

  double getWinProb(int start, int levels, int winner) {
      if (levels == 0) {
          if (start == winner) {
              return 1;
          } else {
              return 0;
          }
      }
      auto it = winProb.find(std::array<int, 3>{start, levels, winner});
      if (it != winProb.end()) {
          return it->second;
      }

      double prob = 0;
      int start2 = start + (1 << (levels - 1));
      if (winner >= start2) {
          for (int i = 0; i < (1 << (levels - 1)); i++) {
              prob += getWinProb(start, levels - 1, start + i) * p[winner][start + i];
          }
          prob *= getWinProb(start2, levels - 1, winner);
      } else {
          for (int i = 0; i < (1 << (levels - 1)); i++) {
              prob += getWinProb(start2, levels - 1, start2 + i) * p[winner][start2 + i];
          }
          prob *= getWinProb(start, levels - 1, winner);
      }

      winProb.emplace(std::array<int, 3>{start, levels, winner}, prob);
      return prob;
  }

  double dfs(int start, int levels, int winner) {
      auto it = optRestricted.find(std::array<int, 3>{start, levels, winner});
      if (it != optRestricted.end()) {
          return it->second;
      }
      double opt = 0;
      int start2 = start + (1 << (levels - 1));
      if (winner >= start2) {
          for (int i = 0; i < (1 << (levels - 1)); i++) {
              double res = dfs(start, levels - 1, start + i) + dfs(start2, levels - 1, winner);
              opt = std::max(opt, res);
          }
      } else {
          for (int i = 0; i < (1 << (levels - 1)); i++) {
              double res = dfs(start, levels - 1, winner) + dfs(start2, levels - 1, start2 + i);
              opt = std::max(opt, res);
          }
      }

      opt += (1 << (levels - 1)) * getWinProb(start, levels, winner);
      optRestricted.emplace(std::array<int, 3>{start, levels, winner}, opt);
      return opt;
  }

  void run(std::istream& in, std::ostream& out) {
      int n;
      in >> n;
      p = std::vector<std::vector<double>>(1 << n, std::vector<double>(1 << n, 0));
      for (int i = 0; i < 1 << n; i++) {
          for (int j = 0; j < 1 << n; j++) {
              int x;
              in >> x;
              p[i][j] = x / 100.0;
          }
      }
      optRestricted.clear();
      winProb.clear();
      double res = 0;
      for (int i = 0; i < 1 << n; i++) {
          res = std::max(res, dfs(0, n, i));
      }
      out.precision(10);
      out << res << "\n";
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}