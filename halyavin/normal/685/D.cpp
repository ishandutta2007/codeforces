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

void run(std::istream& in, std::ostream& out) {
  int n, k;
  in >> n >> k;
  std::vector<std::pair<int, int>> points(n);
  for (int i = 0; i < n; i++) {
    in >> points[i].first >> points[i].second;
  }
  std::vector<std::pair<int, std::pair<int, int>>> events;
  for (int i = 0; i < n; i++) {
    events.emplace_back(std::make_pair(points[i].first - k, std::make_pair(1, i)));
    events.emplace_back(std::make_pair(points[i].first, std::make_pair(-1, i)));
  }
  std::sort(events.begin(), events.end());
  std::map<int, int> curStarts;
  std::vector<int> curCounts(n + 1);
  std::vector<int64_t> finalCounts(n + 1);
  int maxAns = 0;
  int pos = -1000000000;
  for (auto& event : events) {
//    for (int i = 0; i <= maxAns; i++) {
//      std::cerr << curCounts[i] << " ";
//    }
//    std::cerr << std::endl;
    if (event.first > pos) {
      for (int i = 0; i <= maxAns; i++) {
        finalCounts[i] += curCounts[i] * int64_t(event.first - pos);
      }
      pos = event.first;
    }
    int delta = event.second.first;
    int y = points[event.second.second].second;
    int& orig = curStarts[y];
    int first = 0;
    auto it = curStarts.find(y);
    auto lead = it;
    ++lead;
    while (true) {
      if (it->first <= y - k) {
        ++it;
        break;
      }
      first += it->second;
      if (it == curStarts.begin()) break;
      --it;
    }
//    std::cerr << delta << " " << y << std::endl;
    for (int j = 0; j < k; j++) {
      curCounts[first]--;
      curCounts[first + delta]++;
      if (it != curStarts.end() && it->first == y + j - k + 1) {
        first -= it->second;
        ++it;
      }
      if (lead != curStarts.end() && lead->first == y + j + 1) {
        first += lead->second;
        ++lead;
      }
    }
    orig += delta;
    if (maxAns < n && curCounts[maxAns + 1] != 0) {
      maxAns++;
    } else {
      while (maxAns > 0 && curCounts[maxAns] == 0) {
        maxAns--;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    out << finalCounts[i] << " ";
  }
  out << std::endl;

}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}