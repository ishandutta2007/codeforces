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

struct Solution {
  std::vector<int> f;
  std::vector<int> colors;
  std::vector<int> degs;
  std::vector<std::vector<int>> cycles;

  int dfs(int v, int color) {
    colors[v] = color;
    int next_color = colors[f[v]];
    if (next_color == color) {
      cycles.push_back(std::vector<int>{v});
      return color;
    }
    if (next_color >= 0) {
      colors[v] = next_color;
      return next_color;
    }
    int res = dfs(f[v], color);
    if (res != color) {
      colors[v] = res;
    }
    return res;
  }

  void run(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    f.resize(n);
    degs.resize(n);
    for (int i = 0; i < n; i++) {
      in >> f[i];
      f[i]--;
      degs[f[i]]++;
    }
    colors.assign(n, -1);
    for (int i = 0; i < n; i++) {
      if (colors[i] < 0) {
        int res = dfs(i, cycles.size());
        if (res != (int)cycles.size()) {
          cycles[res].push_back(i);
        }
      }
    }
    for (std::vector<int>& cycle : cycles) {
      size_t pos = 1;
      for (size_t i=  1; i < cycle.size(); i++) {
        if (degs[cycle[i]] == 0) {
          cycle[pos] = cycle[i];
          pos++;
        }
      }
      cycle.resize(pos);
    }
    if (cycles.size() == 1 && cycles[0].size() == 1) {
      out << "0" << std::endl;
      return;
    }
    std::vector<std::pair<int, int>> ans;
    for (size_t i = 0; i < cycles.size(); i++) {
      std::vector<int>& cycle = cycles[i];
      std::vector<int>& ncycle = cycles[(i + 1) % cycles.size()];
      if (ncycle.size() == 1) {
        ans.emplace_back(cycle[0], ncycle[0]);
      } else {
        for (size_t j = 1; j < ncycle.size(); j++) {
          ans.emplace_back(cycle[0], ncycle[j]);
        }
      }
    }
    out << ans.size() << std::endl;
    for (int i = 0; i < ans.size(); i++) {
      out << (ans[i].first + 1) << " " << (ans[i].second + 1) << "\n";
    }
  }

};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}