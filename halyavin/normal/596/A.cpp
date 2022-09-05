#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  int x[4];
  int y[4];
  for (int i = 0; i < n; i++) {
    in >> x[i] >> y[i];
  }
  if (n == 1) {
    out << "-1" << std::endl;
    return;
  }
  if (n == 2) {
    if (x[0] == x[1] || y[0] == y[1]) {
      out << "-1" << std::endl;
      return;
    }
    out << abs(x[0]-x[1]) * abs(y[0]-y[1]) << std::endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (x[i] != x[j] && y[i] != y[j]) {
        out << abs(x[i]-x[j]) * abs(y[i]-y[j]) << std::endl;
        return;
      }
    }
  }
  out << "-1" << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}