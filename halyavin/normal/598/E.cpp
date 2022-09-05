#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

int dyn[31][31][51];

void run(std::istream &in, std::ostream &out) {
  for (int i = 0; i < 31; i++) {
    for (int j = 0; j < 31; j++) {
      for (int k = 0; k < 51; k++) {
        dyn[i][j][k] = 1 << 29;
      }
    }
  }
  for (int i = 1; i < 31; i++) {
    for (int j = 1; j < 31; j++) {
      for (int k = 0; k <= i * j && k <= 50; k++) {
        if (k == i * j || k == 0) {
          dyn[i][j][k] = 0;
          continue;
        }
        int m = dyn[i][j][k];
        for (int split = 1; split < i; split++) {
          for (int k1 = 0; k1 <= k; k1++) {
            m = std::min(m, dyn[split][j][k1] + dyn[i-split][j][k-k1] + j * j);
          }
        }
        for (int split = 1; split < j; split++) {
          for (int k1 = 0; k1 <= k; k1++) {
            m = std::min(m, dyn[i][split][k1] + dyn[i][j-split][k-k1] + i * i);
          }
        }
        dyn[i][j][k] = m;
      }
    }
  }
  int t;
  in >> t;
  for (int i= 0; i < t; i++) {
    int n, m, k;
    in >> n >> m >> k;
    out << dyn[n][m][k] << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}