#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
  int T;
  in >> T;
  for (int test = 0; test < T; test++) {
    int n, k;
    in >> n >> k;
    if (k % 3 != 0) {
      if (n % 3 == 0) {
        out << "Bob\n";
      } else {
        out << "Alice\n";
      }
    } else {
      n = n % (k + 1);
      if (n % 3 == 0 && n != k) {
        out << "Bob\n";
      } else {
        out << "Alice\n";
      }
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}