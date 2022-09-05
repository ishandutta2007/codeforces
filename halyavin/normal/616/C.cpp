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

  int n, m;

  std::vector<std::vector<int>> graph;
  std::vector<std::vector<int>> flags;
  std::vector<int> comp_size;

  int dfs(int x, int y, int comp) {
    if (flags[x][y] == comp) {
      return 0;
    }
    flags[x][y] = comp;
    int res = 1;
    if (x + 1 < n && graph[x + 1][y] == 0) {
      res += dfs(x + 1, y, comp);
    }
    if (x > 0 && graph[x - 1][y] == 0) {
      res += dfs(x - 1, y, comp);
    }
    if (y + 1 < m && graph[x][y + 1] == 0) {
      res += dfs(x, y + 1, comp);
    }
    if (y > 0 && graph[x][y - 1] == 0) {
      res += dfs(x, y - 1, comp);
    }
    return res;
  }

  char getAns(int x, int y) {
    if (graph[x][y] == 0) {
      return '.';
    }

    std::vector<int> comp;
    if (x + 1 < n && graph[x + 1][y] == 0) {
      comp.push_back(flags[x+1][y]);
    }
    if (x > 0 && graph[x - 1][y] == 0) {
      comp.push_back(flags[x - 1][y]);
    }
    if (y + 1 < m && graph[x][y + 1] == 0) {
      comp.push_back(flags[x][y+1]);
    }
    if (y > 0 && graph[x][y - 1] == 0) {
      comp.push_back(flags[x][y -1]);
    }
    std::sort(comp.begin(), comp.end());
    auto end = std::unique(comp.begin(), comp.end());
    int res = 1;
    for (auto it = comp.begin(); it != end; ++it) {
      res += comp_size[*it];
    }
    return (char) ((res % 10) + '0');
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n >> m;
    graph.resize(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
      std::string s;
      in >> s;
      for (int j = 0; j < m; j++) {
        graph[i][j] = s[j] == '*' ? 1 : 0;
      }
    }
    flags.resize(n, std::vector<int>(m, -1));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (graph[i][j] == 0 && flags[i][j] == -1) {
          int comp = comp_size.size();
          int size = dfs(i, j, comp);
          comp_size.push_back(size);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      std::string s(m, '0');
      for (int j = 0; j < m; j++) {
        s[j] = getAns(i, j);
      }
      out << s << std::endl;
    }
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}