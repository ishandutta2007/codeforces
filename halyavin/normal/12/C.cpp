#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>

void run(std::istream& in, std::ostream& out) {
  int n, m;
  in >> n >> m;
  std::vector<int> prices(n);
  for (int i = 0; i < n; i++) {
    in >> prices[i];
  }
  std::sort(prices.begin(), prices.end());
  std::vector<int> fruit_counts;
  std::unordered_map<std::string, int> fruit_map;
  for (int i = 0; i < m;i++) {
    std::string fruit;
    in >> fruit;
    fruit_map[fruit]++;
  }
  for (auto& entries : fruit_map) {
    fruit_counts.push_back(entries.second);
  }
  std::sort(fruit_counts.begin(), fruit_counts.end(), std::greater<int>());
  int min_sum = 0;
  int max_sum = 0;
  for (size_t i = 0; i < fruit_counts.size(); i++) {
    min_sum += prices[i]*fruit_counts[i];
  }
  std::reverse(prices.begin(), prices.end());
  for (size_t i = 0; i < fruit_counts.size(); i++) {
    max_sum += prices[i]*fruit_counts[i];
  }
  out << min_sum << " " << max_sum << std::endl;
}

int main() {
  run(std::cin, std::cout);
  return 0;
}