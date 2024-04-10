#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <utility>

void run(std::istream &in, std::ostream &out) {
  int n;
  int z;
  in >> n >> z;
  std::vector<int> xs(n);
  for (int i = 0; i < n; i++) {
    in >> xs[i];
  }
  std::sort(xs.begin(), xs.end());
  int left = 0;
  int right = n / 2 + 1;
  while (right - left > 1) {
    int middle = (left + right) / 2;
    bool good = true;
    for (int i = 0; i < middle; i++) {
      if (xs[n - middle + i] - xs[i] < z) {
        good = false;
        break;
      }
    }
    if (good) {
      left = middle;
    } else {
      right = middle;
    }
  }
  out << left << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}