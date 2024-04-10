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

struct Solution {
  int n, m;
  std::vector<std::vector<int>> grid;
  std::vector<std::vector<int>> dist;
  int fx, fy;
  bool switchLR;
  bool switchUD;
  int curx, cury;

  void tryL(std::istream& in, std::ostream& out) {
    out << (switchLR ? "R" : "L") << std::endl;
    int x, y;
    in >> x >> y;
    x--;y--;
    if (x == curx && y == cury) {
      switchLR = !switchLR;
      tryL(in, out);
    } else {
      curx = x;
      cury = y;
    }
  }

  void tryR(std::istream& in, std::ostream& out) {
    out << (switchLR ? "L" : "R") << std::endl;
    int x, y;
    in >> x >> y;
    x--;y--;
    if (x == curx && y == cury) {
      switchLR = !switchLR;
      tryR(in, out);
    } else {
      curx = x;
      cury = y;
    }
  }

  void tryD(std::istream& in, std::ostream& out) {
    out << (switchUD ? "U" : "D") << std::endl;
    int x, y;
    in >> x >> y;
    x--;y--;
    if (x == curx && y == cury) {
      switchUD = !switchUD;
      tryD(in, out);
    } else {
      curx = x;
      cury = y;
    }
  }

  void tryU(std::istream& in, std::ostream& out) {
    out << (switchUD ? "D" : "U") << std::endl;
    int x, y;
    in >> x >> y;
    x--;y--;
    if (x == curx && y == cury) {
      switchUD = !switchUD;
      tryU(in, out);
    } else {
      curx = x;
      cury = y;
    }
  }



  void calcDist() {
    std::queue<std::pair<int, int>> queue;
    dist.assign(n, std::vector<int>(m, 0));
    dist[fx][fy] = 1;
    queue.emplace(fx, fy);
    while (!queue.empty()) {
      std::pair<int, int> point = queue.front();
      queue.pop();
      int d = dist[point.first][point.second] + 1;
      if (point.first > 0 && dist[point.first - 1][point.second] == 0 && grid[point.first - 1][point.second] == 0) {
        dist[point.first - 1][point.second] = d;
        queue.emplace(point.first - 1, point.second);
      }
      if (point.first < n - 1 && dist[point.first + 1][point.second] == 0 && grid[point.first + 1][point.second] == 0) {
        dist[point.first + 1][point.second] = d;
        queue.emplace(point.first + 1, point.second);
      }
      if (point.second > 0 && dist[point.first][point.second - 1] == 0 && grid[point.first][point.second - 1] == 0) {
        dist[point.first][point.second - 1] = d;
        queue.emplace(point.first, point.second - 1);
      }
      if (point.second < m - 1 && dist[point.first][point.second + 1] == 0 && grid[point.first][point.second + 1] == 0) {
        dist[point.first][point.second + 1] = d;
        queue.emplace(point.first, point.second + 1);
      }
    }
  }

  void run(std::istream& in, std::ostream& out) {
    in >> n >> m;
    grid.assign(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
      std::string s;
      in >> s;
      for (int j = 0; j < m; j++) {
        if (s[j] == 'F') {
          fx = i;fy = j;
        }
        grid[i][j] = (s[j] == '*') ? 1 : 0;
      }
    }
    switchLR = false;
    switchUD = false;
    calcDist();
    curx = 0;
    cury = 0;
    while (curx != fx || cury != fy) {
      int d = dist[curx][cury];
      if (curx > 0 && dist[curx - 1][cury] == d - 1) {
        tryU(in, out);
        continue;
      }
      if (curx < n - 1 && dist[curx + 1][cury] == d - 1) {
        tryD(in, out);
        continue;
      }
      if (cury > 0 && dist[curx][cury - 1] == d - 1) {
        tryL(in, out);
        continue;
      }
      if (cury < m - 1 && dist[curx][cury + 1] == d - 1) {
        tryR(in, out);
        continue;
      }
    }
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}