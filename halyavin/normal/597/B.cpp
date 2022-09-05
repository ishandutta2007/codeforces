#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<std::pair<int, int>> orders;
  for (int i = 0; i < n; i++) {
    int left, right;
    in >> left >> right;
    orders.emplace_back(right + 1, left);
  }
  std::sort(orders.begin(), orders.end());
  std::vector<int> dyn(n);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    int left = -1;
    int right = i;
    while (right - left > 1) {
      int middle = (left + right) / 2;
      if (orders[middle].first <= orders[i].second) {
        left = middle;
      } else {
        right = middle;
      }
    }
    int other = left < 0 ? 0 : dyn[left];
    dyn[i] = std::max(cur, other + 1);
    cur = dyn[i];
  }
  out << cur << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}