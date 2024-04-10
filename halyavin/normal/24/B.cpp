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
#include <map>

static int scores[10] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

void run(std::istream& in, std::ostream& out) {
  int t;
  in >> t;
  std::map<std::string, int> driversMap;
  std::vector<std::string> driversNames;
  std::vector<std::vector<int>> drivers1(50 * 20, std::vector<int>(51));
  std::vector<std::vector<int>> drivers2(50 * 20, std::vector<int>(51));
  for (int i = 0; i < t; i++) {
    int n;
    in >> n;
    for (int j = 0; j < n; j++) {
      std::string name;
      in >> name;
      int idx;
      if (driversMap.find(name) != driversMap.end()) {
        idx = driversMap[name];
      } else {
        idx = driversNames.size();
        driversMap[name] = idx;
        driversNames.push_back(name);
      }
      if (j < 10) {
        drivers1[idx][0] += scores[j];
        drivers2[idx][1] += scores[j];
      }
      if (j == 0) {
        drivers1[idx][1]++;
        drivers2[idx][0]++;
      } else {
        drivers1[idx][j + 1]++;
        drivers2[idx][j + 1]++;
      }
    }
  }
  int maxInd = 0;
  std::vector<int> maxScore = drivers1[0];
  for (size_t i = 1; i < drivers1.size(); i++) {
    if (drivers1[i] > maxScore) {
      maxScore = drivers1[i];
      maxInd = i;
    }
  }
  out << driversNames[maxInd] << std::endl;
  maxInd = 0;
  maxScore = drivers2[0];
  for (size_t i = 1; i < drivers2.size(); i++) {
    if (drivers2[i] > maxScore) {
      maxScore = drivers2[i];
      maxInd = i;
    }
  }
  out << driversNames[maxInd] << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}