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
  std::string s;
  in >> s;
  int shift = 0;
  std::string t;
  size_t pos = s.find('.', 0);
  if (pos != std::string::npos) {
    shift = -(int)(s.length() - pos - 1);
    t = s.substr(0, pos);
    if (s.length() - pos - 1 > 0) {
      t += s.substr(pos + 1, s.length() - pos - 1);
    }
  } else {
    t = s;
  }
  size_t nonZero;
  for(nonZero = 0; nonZero + 1 < t.length(); nonZero++) {
    if (t[nonZero] != '0') {
      break;
    }
  }
  t = t.substr(nonZero);
  for (nonZero = t.length() - 1; nonZero > 0; nonZero--) {
    if (t[nonZero] != '0') {
      break;
    }
  }
  shift += t.length() - nonZero - 1;
  t = t.substr(0, nonZero + 1);
  if (t == "0") {
    out << "0" << std::endl;
    return;
  }
  if (t.length() == 1) {
    out << t;
    if (shift != 0) {
      out << "E" << shift;
    }
    out << std::endl;
    return;
  }
  shift += t.length() - 1;
  out << t[0] << "." << t.substr(1);
  if (shift != 0) {
    out << "E" << shift;
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}