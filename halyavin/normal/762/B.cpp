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
  int a, b, c;
  in >> a >> b >> c;
  int m;
  in >> m;
  std::vector<int> m1;
  std::vector<int> m2;
  std::string s;
  for (int i = 0; i < m; i++) {
    int val;
    in >> val >> s;
    if (s == "USB") {
      m1.push_back(val);
    } else {
      m2.push_back(val);
    }
  }
  std::sort(m1.begin(), m1.end());
  std::sort(m2.begin(), m2.end());
  int num = 0;
  int64_t cost = 0;
  int a1 = std::min((int)m1.size(), a);
  num += a1;
  for (int i = 0; i < a1; i++) {
    cost += m1[i];
  }
  m1.erase(m1.begin(), m1.begin() + a1);
  int a2 = std::min((int)m2.size(), b);
  num += a2;
  for (int i = 0; i < a2; i++) {
    cost += m2[i];
  }
  m2.erase(m2.begin(), m2.begin() + a2);
  std::vector<int>& common = m1;
  common.insert(common.end(), m2.begin(), m2.end());
  std::sort(common.begin(), common.end());
  int a3 = std::min((int)common.size(), c);
  num += a3;
  for (int i = 0; i < a3; i++) {
    cost += common[i];
  }
  out << num << " " << cost << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}