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

void run(std::istream& in, std::ostream& out) {
  int n, m;
  in >> n >> m;
  std::vector<int> state(m);
  for (int i = 0; i < n; i++) {
    int k;
    in >> k;
    for (int j = 0; j < k; j++) {
      int pos;
      in >> pos;
      state[pos - 1] = 1;
    }
  }

  for (int i = 0; i < m; i++) {
    if (state[i] == 0) {
      out << "NO" << std::endl;
      return;
    }
  }
  out << "YES" << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}