#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
  int a;
  in >> a;
  int sum = 0;
  for (int b = 2; b < a; b++) {
    int copy = a;
    while (copy > 0) {
      sum += copy % b;
      copy /= b;
    }
  }
  int q = a - 2;
  int x, y;
  for (x = sum, y = q; y ; x = x % y, std::swap(x, y));
  int d = x;
  sum /= d;
  q /= d;
  out << sum << "/" << q << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}