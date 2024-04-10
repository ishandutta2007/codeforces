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
  int n,t;
  in >> n >> t;
  std::string s;
  in >> s;
  {
    size_t i = 0;
    while (s[i] == '0') i++;
    if (s[i] == '.') i--;
    s = s.substr(i);
  }
  size_t pos = s.find('.');
  int carry = 0;
  size_t cur;
  for (cur = pos + 1; cur < s.length(); cur++) {
    if (s[cur] >= '5') {
      break;
    }
  }
  if (cur == s.length()) {
    out << s << std::endl;
    return;
  }
  t--;
  cur--;
  carry = 1;
  while (cur > pos && t > 0) {
    if (s[cur] == '9') {
      cur--;
      continue;
    }
    if (s[cur] >= '4') {
      t--;
      cur--;
      continue;
    }
    break;
  }
  s = s.substr(0, cur + 1);
  cur++;
  for(;cur-- > 0;) {
    if (s[cur] == '.') {
      continue;
    }
    if (s[cur] == '9') {
      s[cur] = '0';
      continue;
    }
    s[cur]++;
    carry = 0;
    break;
  }
  if (carry) { s = "1" + s; }
  while (s[s.length()-1]=='0') s.pop_back();
  if (s[s.length() - 1] == '.') s.pop_back();
  out << s << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}