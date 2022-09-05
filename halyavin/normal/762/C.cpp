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

const int inf = 1000000000;
void calcSubseq(const std::string& a, const std::string& b, std::vector<int>& p1) {
  p1.assign(b.size() + 1, inf);
  p1[0] = 0;
  int cur = 0;
  for (int i = 0; i < b.size(); i++) {
    char c = b[i];
    while (cur < a.size() && a[cur] != c) {
      cur++;
    }
    if (cur >= a.size()) return;
    cur++;
    p1[i + 1] = cur;
  }
}

void run(std::istream &in, std::ostream &out) {
  std::string a;
  std::string b;
  in >> a >> b;
  std::vector<int> p1;
  std::vector<int> p2;
  calcSubseq(a, b, p1);
  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());
  calcSubseq(a, b, p2);
  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());
  std::pair<int, int> answer = {0, 0};
  int opt = 0;
  int i2 = p2.size() - 1;
  for (int i1 = 0; i1 < p1.size(); i1++) {
    while (i2 >= 0 && (p1[i1] + p2[i2] > a.size() || (i1 + i2 > b.size()))) i2--;
    if (i2 < 0) break;
    if (i1 + i2 > opt) {
      opt = i1 + i2;
      answer.first = i1;
      answer.second = i2;
    }
  }
  if (opt == 0) {
    out << "-" << std::endl;
  } else {
    out << b.substr(0, answer.first) << b.substr(b.size() - answer.second) << std::endl;
  }

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}