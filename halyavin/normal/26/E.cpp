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

void printOne(const std::vector<int>& as, int idxOne, int w, std::ostream& out) {
  int sum = std::accumulate(as.begin(), as.end(), 0);
  int inside = sum - w;
  out << (idxOne + 1) << " ";
  for (size_t i = 0; i < as.size(); i++) {
    if (i == idxOne) {
      continue;
    }
    for (int j = 0; j < as[i]; j++) {
      if (inside == 0) {
        out << (idxOne + 1) << " ";
      }
      out << (i + 1) << " " << (i + 1) << " ";
      inside--;
    }
  }
  if (inside == 0) {
    out << (idxOne + 1) << " ";
  }
}

void run(std::istream& in, std::ostream& out) {
  int n, w;
  in >> n >> w;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  int all = std::accumulate(as.begin(), as.end(), 0);
  if (w < 0 || w > all) {
    out << "No" << std::endl;
    return;
  }
  if (n == 1) {
    if (w != all) {
      out << "No" << std::endl;
      return;
    }
    out << "Yes" << std::endl;
    for (int i = 0; i < all; i++) {
      out << 1 << " " << 1 << " ";
    }
    out << std::endl;
    return;
  }
  int one = std::distance(as.begin(), std::find(as.begin(), as.end(), 1));
  if (one < n) {
    if (w < 1) {
      out << "No" << std::endl;
      return;
    }
    out << "Yes" << std::endl;
    printOne(as, one, w, out);
    out << std::endl;
    return;
  }
  if (w < 2) {
    out << "No" << std::endl;
    return;
  }
  out << "Yes" << std::endl;
  int prev = as[0];
  as[0] = 1;
  as[1]--;
  int all1 = all - prev;
  int w1 = std::min(w - 1, all1);
  int w2 = w - w1;
  printOne(as, 0, w1, out);
  std::fill(as.begin(), as.end(), 0);
  as[1] = 1;
  as[0] = prev - 1;
  printOne(as, 1, w2, out);
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}