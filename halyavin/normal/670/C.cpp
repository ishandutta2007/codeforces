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
#include <map>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::map<int, int> stat;
  for (int i = 0; i < n; i++) {
    int lang;
    in >>lang;
    stat[lang]++;
  }
  int m;
  in >> m;
  std::vector<int> bs(m);
  std::vector<int> cs(m);
  for (int i = 0; i < m; i++) {
    in >> bs[i];
  }
  for (int i =0; i< m; i++) {
    in >> cs[i];
  }
  int optB = -1;
  int optC = -1;
  int opt = -1;
  for (int i = 0; i < m; i++) {
    if (stat[bs[i]] > optB) {
      optB = stat[bs[i]];
      optC = stat[cs[i]];
      opt = i;
      continue;
    }
    if (stat[bs[i]] < optB) {
      continue;
    }
    if (stat[cs[i]] > optC) {
      optC = stat[cs[i]];
      opt = i;
      continue;
    }
  }
  out << (opt + 1) << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}