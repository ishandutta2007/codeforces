#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<std::array<int, 3>> points;
  for (int i = 0; i < n; i++) {
    int x, y;
    in >> x >> y;
    points.push_back( { x, y, i });
  }
  using pref = std::array<int, 3>*;
  std::unordered_map<int, std::vector<int>> map;
  {
    std::vector<pref> order1;
    for (auto& p : points) {
      order1.push_back(&p);
    }
    std::sort(order1.begin(), order1.end(),
        [](const pref& left, const pref& right) {
          if ((*left)[1]-(*left)[0] < (*right)[1]-(*right)[0]) {
            return true;
          }
          if ((*left)[1] - (*left)[0] > (*right)[1]-(*right)[0]) {
            return false;
          }
          if ((*left)[0] > (*right)[0]) {
            return true;
          }
          return false;
        });

    for (pref p : order1) {
      map[(*p)[1] - (*p)[0]].push_back((*p)[2]);
    }
  }
  std::vector<int> order(n);
  std::vector<int> ansOrder(n);
  for (int i = 0; i < n; i++) {
    int w;
    in >> w;
    std::vector<int>& vs = map[w];
    if (vs.empty()) {
      out << "NO" << std::endl;
      return;
    }
    order[vs.back()] = i;
    ansOrder[i] = vs.back();
    vs.resize(vs.size() - 1);
  }
  {
    std::vector<pref> order2;
    for (auto& p : points) {
      order2.push_back(&p);
    }
    std::sort(order2.begin(), order2.end(),
        [](const pref& left, const pref& right) {
          if ((*left)[0] < (*right)[0]) {
            return true;
          }
          if ((*left)[0] > (*right)[0]) {
            return false;
          }
          return (*left)[1] < (*right)[1];
        });
    std::unordered_map<int, std::vector<int>> mapX;
    for (pref p : order2) {
      mapX[(*p)[0]].push_back((*p)[2]);
    }
    for (auto& entrance : mapX) {
      std::vector<int>& points = entrance.second;
      for (size_t i = 0; i + 1 < points.size(); i++) {
        if (order[points[i + 1]] < order[points[i]]) {
          out << "NO" << std::endl;
          return;
        }
      }
    }
  }
  {
    std::vector<pref> order3;
    for (auto& p : points) {
      order3.push_back(&p);
    }
    std::sort(order3.begin(), order3.end(),
        [](const pref& left, const pref& right) {
          if ((*left)[1] < (*right)[1]) {
            return true;
          }
          if ((*left)[1] > (*right)[1]) {
            return false;
          }
          return (*left)[0] < (*right)[0];
        });
    std::unordered_map<int, std::vector<int>> mapY;
    for (pref p : order3) {
      mapY[(*p)[1]].push_back((*p)[2]);
    }
    for (auto& entrance : mapY) {
      std::vector<int>& points = entrance.second;
      for (size_t i = 0; i + 1 < points.size(); i++) {
        if (order[points[i + 1]] < order[points[i]]) {
          out << "NO" << std::endl;
          return;
        }
      }
    }
  }
  out << "YES" << std::endl;
  for (int i = 0; i < n; i++) {
    out << points[ansOrder[i]][0] << " " << points[ansOrder[i]][1] << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}