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

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      in >> matrix[i][j];
    }
  }
  int k;
  in >> k;
  std::vector<int64_t> ans(k);
  for (int i = 0; i < k; i++) {
    int a, b, c;
    in >> a >> b >> c;
    a--;b--;
    int64_t sum = 0;
    for (int l = 0; l < n; l++) {
      for (int m = 0; m < n; m++) {
        matrix[l][m] = std::min({matrix[l][m], matrix[l][a] + c + matrix[b][m], matrix[l][b] + c + matrix[a][m]});
        sum += matrix[l][m];
      }
    }
    ans[i] = sum / 2;
  }
  for (int i = 0; i < k; i++) {
    out << ans[i] << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}