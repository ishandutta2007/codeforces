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
#include <queue>
#include <tuple>

const int64_t inf = 1LL << 60;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

void run(std::istream& in, std::ostream& out) {
  int n, m, p;
  in >> n >> m >> p;
  std::vector<std::vector<int>> graph(n, std::vector<int>(m, 0));
  std::vector<std::vector<std::pair<int, int>>> cells(p);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      in >> graph[i][j];
      graph[i][j]--;
      cells[graph[i][j]].emplace_back(i, j);
    }
  }
  std::vector<std::vector<int64_t>> dist(n, std::vector<int64_t>(m, inf));
  if (p == 1) {
    out << 0 << std::endl;
    return;
  }
  for (std::pair<int, int>& cell : cells[0]) {
    dist[cell.first][cell.second] = cell.first + cell.second;
  }
  std::vector<std::vector<int64_t>> tmp(n, std::vector<int64_t>(m));
  for (int ip = 1; ip < p; ip++) {
    if (uint64_t(cells[ip].size()) * cells[ip - 1].size() < uint64_t(10 * n * m)) {
      for (std::pair<int, int>& cell : cells[ip]) {
        int64_t d = inf;
        for (std::pair<int, int>& cell2 : cells[ip - 1]) {
          d = std::min(d, dist[cell2.first][cell2.second] + std::abs(cell2.first - cell.first)
              + std::abs(cell2.second - cell.second));
        }
        dist[cell.first][cell.second] = d;
      }
    } else {
      for (int i = 0; i < n; i++) {
        std::fill(tmp[i].begin(), tmp[i].end(), inf);
      }
      for (std::pair<int, int>& cell : cells[ip - 1]) {
        tmp[cell.first][cell.second] = dist[cell.first][cell.second];
      }
      std::priority_queue<std::tuple<int64_t, int, int>,
                          std::vector<std::tuple<int64_t, int, int>>,
                          std::greater<std::tuple<int64_t, int, int>>> queue;
      for (std::pair<int, int>& cell : cells[ip - 1]) {
        queue.push(std::tuple<int64_t, int, int>{dist[cell.first][cell.second], cell.first, cell.second});
      }

      while (!queue.empty()) {
        std::tuple<int64_t, int, int> cur = queue.top();
        queue.pop();
        int64_t d = std::get<0>(cur);
        int curx = std::get<1>(cur);
        int cury = std::get<2>(cur);
        for (int dir = 0; dir < 4; dir++) {
          int x = curx + dx[dir];
          int y = cury + dy[dir];
          if (x >= 0 && x < n && y >= 0 && y < m) {
            if (tmp[x][y] == inf) {
              queue.push(std::tuple<int64_t, int, int>{d + 1, x, y});
            }
            tmp[x][y] = std::min(tmp[x][y], d + 1);
          }
        }
      }
      for (std::pair<int, int>& cell : cells[ip]) {
        dist[cell.first][cell.second] = tmp[cell.first][cell.second];
      }
    }
  }
  std::pair<int, int> finalCell = cells[p - 1][0];
  out << dist[finalCell.first][finalCell.second] << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}