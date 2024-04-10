#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

void run(std::istream &in, std::ostream &out) {
  int n, m, k;
  in >> n >> m >> k;
  std::vector<std::string> graph(n);
  for (int i = 0; i < n; i++) {
    in >> graph[i];
  }
  std::vector<std::vector<int>> visited(n, std::vector<int>(m, -1));
  std::vector<int> components;
  std::vector<std::pair<int, int>> queue;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (visited[i][j]<0 && graph[i][j] == '.') {
        int idx = components.size();
        int count = 0;
        queue.clear();
        queue.emplace_back(i, j);
        size_t qleft = 0;
        visited[i][j] = idx;
        while (qleft < queue.size()) {
          std::pair<int, int> p = queue[qleft];
          qleft++;
          if (visited[p.first - 1][p.second] < 0) {
            if (graph[p.first - 1][p.second] == '.') {
              visited[p.first - 1][p.second] = idx;
              queue.emplace_back(p.first - 1, p.second);
            } else {
              count++;
            }
          }
          if (visited[p.first + 1][p.second] < 0) {
            if (graph[p.first + 1][p.second] == '.') {
              visited[p.first + 1][p.second] = idx;
              queue.emplace_back(p.first + 1, p.second);
            } else {
              count++;
            }
          }
          if (visited[p.first][p.second - 1] < 0) {
            if (graph[p.first][p.second - 1] == '.') {
              visited[p.first][p.second - 1] = idx;
              queue.emplace_back(p.first, p.second - 1);
            } else {
              count++;
            }
          }
          if (visited[p.first][p.second + 1] < 0) {
            if (graph[p.first][p.second + 1] == '.') {
              visited[p.first][p.second + 1]  = idx;
              queue.emplace_back(p.first, p.second + 1);
            } else {
              count++;
            }
          }
        }
        components.push_back(count);
      }
    }
  }
  for (int i = 0; i < k; i++) {
    int x, y;
    in >> x >> y;
    x--;y--;
    int component = visited[x][y];
    out << components[component] << std::endl;
  }

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}