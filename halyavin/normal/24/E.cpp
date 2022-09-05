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

struct group {
  std::vector<std::pair<int, int>> positive;
  std::vector<std::pair<int, int>> negative;

  bool isEmpty() {
    return positive.size() == 0 || negative.size() == 0;
  }
};

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<std::pair<int, int>> particles(n);
  for (int i = 0; i < n; i++) {
    in >> particles[i].first >> particles[i].second;
  }
  std::sort(particles.begin(), particles.end());
  std::vector<group> groups;
  group curGroup;
  bool isPositive = true;
  bool isZero = false;
  for (int i = 0; i < n; i++) {
    if (particles[i].second > 0) {
      if (isPositive) {
        curGroup.positive.push_back(particles[i]);
      } else {
        if (!curGroup.isEmpty()) {
          if (curGroup.negative.back().first == particles[i].first) {
            isZero = true;
          }
          groups.push_back(curGroup);
        }
        isPositive = true;
        curGroup.positive.clear();
        curGroup.negative.clear();
        curGroup.positive.push_back(particles[i]);
      }
    } else {
      isPositive = false;
      curGroup.negative.push_back(particles[i]);
    }
  }
  if (!curGroup.isEmpty()) {
    groups.push_back(curGroup);
  }
  if (isZero) {
    out << "0" << std::endl;
    return;
  }
  if (groups.size() == 0) {
    out << "-1" << std::endl;
    return;
  }
  double left = 0;
  double right = 1e10;
  while (true) {
    double middle = (left + right) / 2;
    if (middle <= left || middle >= right) break;
    bool isCollision = false;
    for (const group& curGroup : groups) {
      double maxPositive = -1e10;
      for (const std::pair<int, int>& particle : curGroup.positive) {
        maxPositive = std::max(maxPositive, particle.first + particle.second * middle);
      }
      double minNegative = 1e10;
      for (const std::pair<int, int>& particle : curGroup.negative) {
        minNegative = std::min(minNegative, particle.first + particle.second * middle);
      }
      if (minNegative < maxPositive) {
        isCollision = true;
        break;
      }
    }
    if (isCollision) {
      right = middle;
    } else {
      left = middle;
    }
  }
  out.precision(20);
  out << left << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}