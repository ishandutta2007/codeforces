#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
  int T;
  in >> T;
  for (int test = 0; test < T; test++) {
    int n, m;
    in >> n >> m;
    std::vector<int> rowSums(n);
    std::vector<int> colSums(m);
    std::vector<std::string> field(n);
    for (int i = 0; i < n; i++) {
      in >> field[i];
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (field[i][j] == '.') {
          rowSums[i]++;
          colSums[j]++;
        }
      }
    }
    int minRow = *std::min_element(rowSums.begin(), rowSums.end());
    int minCol = *std::min_element(colSums.begin(), colSums.end());
    std::vector<int> goodRows;
    std::vector<int> goodCols;
    for (int i = 0; i < n; i++) {
      if (rowSums[i] == minRow) {
        goodRows.push_back(i);
      }
    }
    for (int i = 0; i < m; i++) {
      if (colSums[i] == minCol) {
        goodCols.push_back(i);
      }
    }
    bool good = false;
    for (int row : goodRows) {
      for (int col : goodCols) {
        if (field[row][col] == '.') {
          good = true;
        }
      }
    }
    if (good) {
      out << (minCol + minRow - 1) << "\n";
    } else {
      out << (minCol + minRow) << "\n";
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}