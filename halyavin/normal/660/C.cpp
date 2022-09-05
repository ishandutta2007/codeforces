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

void run(std::istream &in, std::ostream &out) {
  int n, k;
  in >> n >> k;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  int opt = 0;
  int from = 0;
  int to = -1;
  std::queue<int> zeros;
  for (int i = 0; i < n; i++) {
    if (as[i] == 0) {
      if (zeros.size() <= k) {
        opt = i;
        from = 0;
        to = i - 1;
        zeros.push(i);
      } else {
        if (i - zeros.front() - 1 > opt) {
          opt = i - zeros.front() - 1;
          from = zeros.front() + 1;
          to = i - 1;
        }
        zeros.push(i);
        zeros.pop();
      }
    }
  }
  if (zeros.size() <= k) {
    opt = n;
    from = 0;
    to = n - 1;
  } else {
    if (n - zeros.front() - 1 > opt) {
      opt = n - zeros.front() - 1;
      from = zeros.front() + 1;
      to = n - 1;
    }
  }
  out << opt << std::endl;
  for (int i = 0; i < n; i++) {
    if (i >= from && i <= to) {
      as[i] = 1;
    }
    out << as[i] << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}