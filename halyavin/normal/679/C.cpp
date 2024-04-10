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

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct Solution {
  int k, n;
  std::vector<std::vector<int>> field;
  std::vector<std::vector<int>> comps;
  std::vector<std::pair<int, int>> compCells;
  std::vector<int> compsSize;
  std::vector<std::vector<int>> sqCells;

  void dfs(int x, int y, int c) {
    for (int dir = 0; dir < 4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if (nx >= 0 && nx < n && ny >= 0 && ny < n && field[nx][ny] == 0 && comps[nx][ny] == -1) {
        comps[nx][ny] = c;
        compsSize[c]++;
        dfs(nx, ny, c);
      }
    }
  }

  void getComps() {
    comps = std::vector<std::vector<int>>(n, std::vector<int>(n, -1));
    compCells.clear();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (field[i][j] != 0) {
          continue;
        }
        if (comps[i][j] < 0) {
          comps[i][j] = compCells.size();
          compCells.emplace_back(i, j);
          compsSize.push_back(1);
          dfs(i, j, comps[i][j]);
        }
      }
    }
  }

  void getSqCells() {
    std::vector<std::vector<int>> sum1(n, std::vector<int>(n - k + 1));
    for (int x = 0; x < n; x++) {
      int sum = 0;
      for (int i = 0; i < k; i++) {
        sum += field[x][i];
      }
      sum1[x][0] = sum;
      for (int y = 1; y < sum1[x].size(); y++) {
        sum1[x][y] = sum1[x][y - 1] + field[x][y + k - 1] - field[x][y - 1];
      }
    }
    sqCells.resize(n - k + 1);
    for (int x = 0; x < n - k + 1; x++) {
      sqCells[x].resize(n - k + 1);
    }
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < sum1[i].size(); j++) {
        sqCells[0][j] += sum1[i][j];
      }
    }
    for (int x = 1; x < n - k + 1; x++) {
      for (int y = 0; y < sum1[x - 1].size(); y++) {
        sqCells[x][y] = sqCells[x - 1][y] + sum1[x + k - 1][y] - sum1[x - 1][y];
      }
    }
  }

  std::vector<int> comp;
  int cur;

  void addCell(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n) {
      int c = comps[x][y];
      if (c != -1) {
        comp[c]++;
        if (comp[c] == 1) {
          cur += compsSize[c];
        }
      }
    }
  }

  void removeCell(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < n) {
      int c = comps[x][y];
      if (c != -1) {
        comp[c]--;
        if (comp[c] == 0) {
          cur -= compsSize[c];
        }
      }
    }
  }

  void checkRow(int x) {
    comp.clear();
    comp.resize(compCells.size());
    int y = 0;
    cur = sqCells[x][0];
    for (int i = x - 1; i <= x + k; i++) {
      for (int j = 0; j <= k; j++) {
        if ((i == x - 1) + (i == x + k) + (j == k) < 2) {
          addCell(i, j);
        }
      }
    }
    answer = std::max(answer, cur);
    for (y++; y < n - k + 1; y++) {
      addCell(x - 1, y + k - 1);
      for (int i = 0; i < k; i++) {
        addCell(x + i, y + k);
      }
      addCell(x + k, y + k - 1);
      removeCell(x - 1, y - 1);
      for (int i = 0; i < k; i++) {
        removeCell(x + i, y - 2);
      }
      removeCell(x + k, y - 1);
      cur -= sqCells[x][y - 1];
      cur += sqCells[x][y];
      answer = std::max(answer, cur);
    }
  }

  int answer;

  void run(std::istream& in, std::ostream& out) {
    in >> n >> k;
    field.resize(n);
    for (int i = 0; i < n; i++) {
      field[i].resize(n);
      std::string s;
      in >> s;
      for (int j = 0; j < n; j++) {
        if (s[j] == 'X') {
          field[i][j] = 1;
        }
      }
    }
    getComps();
    getSqCells();
    answer = 0;
    for (int x = 0; x < n - k + 1; x++) {
      checkRow(x);
    }
    out << answer << std::endl;
  }

};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}