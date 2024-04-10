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
#include <array>

void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> str(n);
  for (int i = 0; i < n; i++) {
    in >> str[i];
  }

  std::vector<std::pair<int, int>> letterRepeats;
  std::vector<std::pair<int, int>> stringRepeats;
  {
    std::map<int, std::array<int, 11>> letterPos;
    for (int i = 0; i < n; i++) {
      int letter = str[i];
      if (letterPos.find(letter) != letterPos.end()) {
        std::array<int, 11>& data = letterPos[letter];
        data[0]++;
        data[data[0]] = i;
        for (int j = 1; j < data[0]; j++) {
          letterRepeats.emplace_back(i - data[j], data[j]);
        }
      } else {
        std::array<int, 11>& data = letterPos[letter];
        data[0] = 1;
        data[1] = i;
      }
    }
    letterPos.clear();
  }
  std::sort(letterRepeats.begin(), letterRepeats.end());
  int prevLen = -1;
  int count = 0;
  for (size_t i = 0; i < letterRepeats.size(); i++) {
    if (letterRepeats[i].first != prevLen) {
      prevLen = letterRepeats[i].first;
      count = 1;
      if (prevLen == 1) {
        stringRepeats.emplace_back(1, letterRepeats[i].second);
      }
    } else {
      if (letterRepeats[i].second == letterRepeats[i - 1].second + 1) {
        count++;
        if (count >= prevLen) {
          stringRepeats.emplace_back(prevLen, letterRepeats[i].second - prevLen + 1);
        }
      } else {
        count = 1;
        if (prevLen == 1) {
          stringRepeats.emplace_back(1, letterRepeats[i].second);
        }
      }
    }
  }
  std::sort(stringRepeats.begin(), stringRepeats.end());
  int curPos = 0;
  for (size_t i = 0; i < stringRepeats.size(); i++) {
    if (stringRepeats[i].second >= curPos) {
      curPos = stringRepeats[i].first + stringRepeats[i].second;
    }
  }
  out << n - curPos << std::endl;
  for (int i = curPos; i < n; i++) {
    out << str[i] << " ";
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}