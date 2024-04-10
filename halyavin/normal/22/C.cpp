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
  int n, m, v;
  in >> n >> m >> v;
  if (m < n - 1) {
    out << "-1" << std::endl;
    return;
  }
  if (m > (n - 1) * (n - 2) / 2 + 1) {
    out << "-1" << std::endl;
    return;
  }
  std::vector<int> others;
  for (int i = 1; i < v; i++) {
    others.push_back(i);
  }
  for (int i = v + 1; i <= n; i++) {
    others.push_back(i);
  }
  int last = others.back();
  others.resize(others.size() - 1);
  out << v << " " << last << std::endl;
  m--;
  for (size_t i= 0; i < others.size(); i++) {
    out << v << " " << others[i] << std::endl;
  }
  m -= others.size();
  int curi = 0;
  int curj = 1;
  for(; m > 0;  m--) {
    out << others[curi] << " " << others[curj] << std::endl;
    curj++;
    if (curj == others.size()) {
      curi++;
      curj = curi + 1;
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}