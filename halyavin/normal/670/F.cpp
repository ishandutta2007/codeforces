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
#include <array>

const int p10[8] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

void run(std::istream &in, std::ostream &out) {
  std::string s;
  in >> s;
  std::array<int, 10> stat = {};
  int len = s.length();
  for (int i = 0; i < len; i++) {
    stat[s[i] - '0']++;
  }
  int klen;
  for (klen = 1; klen <= 6 && klen < len; klen++) {
    if (len - klen >= p10[klen - 1] && len - klen < p10[klen]) {
      break;
    }
  }
  len -= klen;
  klen = len;
  while (klen != 0) {
    stat[klen % 10]--;
    klen /= 10;
  }
  std::string sub;
  in >> sub;
  for (size_t i = 0; i < sub.length(); i++) {
    stat[sub[i] - '0']--;
  }
  std::vector<std::string> cases;
  if (sub[0] != '0' || len == 1) {
    std::string result = sub;
    for (size_t i = 0; i < stat.size(); i++) {
      result.append(stat[i], '0' + i);
    }
    cases.emplace_back(std::move(result));
  }
  int minDigit = 0;
  for (size_t i = 1; i < stat.size(); i++) {
    if (stat[i] != 0) {
      minDigit = i;
      break;
    }
  }
  if (minDigit != 0) {
    stat[minDigit]--;
    {
      std::string result(1, '0' + minDigit);
      for (size_t i = 0; i < stat.size(); i++) {
        result.append(stat[i], '0' + i);
        if (sub[0] == '0' + i) {
          result.append(sub);
        }
      }
      cases.emplace_back(std::move(result));
    }
    {
      std::string result(1, '0' + minDigit);
      for (size_t i = 0; i < stat.size(); i++) {
        if (sub[0] == '0' + i) {
          result.append(sub);
        }
        result.append(stat[i], '0' + i);
      }
      cases.emplace_back(std::move(result));
    }
  }
  int idx = 0;
  for (size_t i = 1; i < cases.size(); i++) {
    if (cases[i] < cases[idx]) {
      idx = i;
    }
  }
  out << cases[idx] << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}