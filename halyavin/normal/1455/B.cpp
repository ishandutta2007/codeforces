#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
  int t;
  in >> t;
  for (int test = 0; test < t; test++) {
    int x;
    in >> x;
    int left = 0;
    int right = 10000;
    while (right - left > 1) {
      int middle = (left + right) / 2;
      int bound = middle * (middle + 1) / 2;
      if (bound >= x) {
        right = middle;
      } else {
        left = middle;
      }
    }
    int bound = right * (right + 1) / 2;
    if (x + 1 == bound) {
      right++;
    }
    out << right << "\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}