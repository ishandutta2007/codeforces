#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

void run(std::istream &in, std::ostream &out) {
  std::string str;
  in >> str;
  int m;
  in >> m;
  for (int i = 0; i < m; i++) {
    int l, r, k;
    in >> l >> r >> k;
    l--;r--;
    k = k % (r - l + 1);
    std::string str2 = str;
    for (int j = l; j < l + k; j++) {
      str2[j] = str[j - k + (r - l + 1)];
    }
    for (int j = l + k; j <= r; j++) {
      str2[j] = str[j - k];
    }
    str = str2;
  }
  out << str << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}