#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <set>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<std::array<int, 3>> points(n);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < n; j++) {
      in >> points[j][i];
    }
  }
  std::sort(points.begin(), points.end(), [](std::array<int, 3> p1, std::array<int, 3> p2) {
    if (p1[0] > p2[0]) return true;
    if (p1[0] < p2[0]) return false;
    return p1[1] < p2[1];
  });
  int answer = 0;
  std::set<std::pair<int, int>> bound;
  for (size_t i = 0; i < points.size(); i++) {
    std::pair<int, int> p(points[i][1], points[i][2]);
    auto it = bound.upper_bound(std::pair<int, int>(p.first, 1e9));
    if (it != bound.end()) {
      if (it->second > p.second) {
        answer++;
        continue;
      }
      if (it->second == p.second) {
        continue;
      }
    }
    if (it == bound.begin()) {
      bound.insert(p);
      continue;
    }
    it--;
    while (true) {
      if (it->second <= p.second) {
        it = bound.erase(it);
      } else {
        break;
      }
      if (it == bound.begin()) {
        break;
      }
      it--;
    }
    if (it != bound.end() && it->first == p.first) {
      continue;
    }
    bound.insert(p);
  }
  out << answer << std::endl;
}

int main() {
  run(std::cin, std::cout);
  return 0;
}