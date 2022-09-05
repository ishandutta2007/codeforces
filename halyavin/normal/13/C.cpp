#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>

void run(std::istream &in, std::ostream &out) {
  int N;
  in >> N;
  std::vector<int> data(N);
  for (size_t i = 0; i < data.size(); i++) {
    in >> data[i];
  }
  std::vector<int> sortedData = data;
  std::sort(sortedData.begin(), sortedData.end());
  std::vector<int64_t> dyn(N);
  for (int i = 0; i < N; i++) {
    int64_t minValue = INT64_MAX;
    for (int j = 0; j < N; j++) {
      minValue = std::min(minValue, dyn[j]);
      dyn[j] = std::abs(sortedData[j] - data[i]) + minValue;
    }
  }
  int64_t result = *std::min_element(dyn.begin(), dyn.end());
  out << result << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}