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
  int n, k;
  in >> n >> k;
  std::vector<int> children(n);
  std::iota(children.begin(), children.end(), 1);
  int cur = 0;
  for (int i = 0; i < k; i++) {
    int a;
    in >> a;
    cur = (cur + a) % children.size();
    out << children[cur] << " ";
    children.erase(children.begin() + cur);
    cur = cur % children.size();
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}