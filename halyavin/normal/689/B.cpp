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
  int n;
  in >> n;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
    as[i]--;
  }
  std::vector<int> dyn(n, n);
  std::vector<int> queue(n);
  int bque = 0;
  int eque = 1;
  queue[0] = 0;
  dyn[0] = 0;
  while (eque > bque) {
    int v = queue[bque];
    bque++;
    int d = dyn[v] + 1;
    if (v > 0 && dyn[v - 1] > d) {
      dyn[v - 1] = d;
      queue[eque] = v - 1;
      eque++;
    }
    if (v < n - 1 && dyn[v + 1] > d) {
      dyn[v + 1] = d;
      queue[eque] = v + 1;
      eque++;
    }

    if (dyn[as[v]] > d) {
      dyn[as[v]] = d;
      queue[eque] = as[v];
      eque++;
    }
  }
  for (int i = 0; i < n; i++) {
    out << dyn[i] << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}