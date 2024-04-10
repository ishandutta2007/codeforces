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

int getNimb(int c, int64_t forbidden_mask, std::map<std::pair<int, int64_t>, int>& map) {
  auto it = map.find(std::pair<int, int64_t>{c, forbidden_mask});
  if (it != map.end()) {
    return it->second;
  }
  if (c == 0) {
    return 0;
  }
  std::vector<int> other;
  for (int i = 1; i <= c; i++) {
    if ((forbidden_mask & (1 << i)) == 0) {
      other.push_back(getNimb(c - i, forbidden_mask + (1 << i), map));
    }
  }
  std::sort(other.begin(), other.end());
  if (other.empty()) {
    return 0;
  }
  int j = 0;
  for (size_t i = 0; i < other.size(); i++) {
    if (j >= other.size() || other[j] != i) {
      map[std::pair<int, int64_t>(c, forbidden_mask)] = i;
      return i;
    }
    while (j < other.size() && other[j] == i) j++;
  }
  map[std::pair<int, int64_t>(c, forbidden_mask)] = other.size();
  return other.size();
}

int data[] = {
    0, 1, 1, 2, 2,
    2, 3, 3, 3, 3,
    4, 4, 4, 4, 4,
    5, 5, 5, 5, 5,
    5, 6, 6, 6, 6,
    6, 6, 6, 7, 7,
    7, 7, 7, 7, 7,
    7, 8, 8, 8, 8,
    8, 8, 8, 8, 8,
    9, 9, 9, 9, 9,
    9, 9, 9, 9, 9,
    10, 10, 10, 10, 10,
    10};

void run(std::istream& in, std::ostream& out) {
//  std::vector<int> calc(61);
//  std::map<std::pair<int, int64_t>, int> map;
//  for (int i = 1; i <= 60; i++) {
//    calc[i] = getNimb(i, 0, map);
//  }
//  for (int i = 0; i <= 60; i++) {
//    out << calc[i] << ", ";
//    if (i % 5 == 4) out << std::endl;
//  }
  int n;
  in >> n;
  int res = 0;
  for (int i = 0; i < n; i++) {
    int x;
    in >> x;
    res ^= data[x];
  }
  if (res == 0) {
    out << "YES" << std::endl;
  } else {
    out << "NO" << std::endl;
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}