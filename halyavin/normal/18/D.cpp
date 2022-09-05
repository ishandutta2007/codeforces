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
#include <iomanip>

const int mod = 1000000000;

void mul2(std::vector<int>& num) {
  int c = 0;
  for (int i = 0; i < num.size(); i++) {
    int v = num[i] * 2 + c;
    if (v >= mod) {
      c = 1;
      v -= mod;
    } else {
      c = 0;
    }
    num[i] = v;
  }
  if (c != 0) {
    num.push_back(c);
  }
}

void add1(std::vector<int>& num) {
  for (int i = 0; i < num.size(); i++) {
    num[i]++;
    if (num[i] < mod) return;
    num[i] = 0;
  }
  num.push_back(1);
}

void run(std::istream& in, std::ostream& out) {
  int n;
  in >> n;
  std::vector<std::pair<std::string, int>> input(n);
  for (int i = 0; i < n; i++) {
    in >> input[i].first >> input[i].second;
  }
  std::array<std::pair<int, int>, 2001> info = {};
  for (int i = 0; i < n; i++) {
    if (input[i].first == "sell") {
      info[input[i].second].second = i + 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (input[i].first == "win") {
      if (i + 1 < info[input[i].second].second) {
        info[input[i].second].first = std::max(info[input[i].second].first, i + 1);
      }
    }
  }
  std::vector<std::pair<int, int>> pairs;
  std::vector<int> num = {0};
  for (int i = 2000; i >= 0; i--) {
    mul2(num);
    if (info[i].first == 0 || info[i].second == 0) {
      continue;
    }
    if (info[i].first > info[i].second) {
      continue;
    }
    bool good = true;
    for (int j = 0; j < pairs.size(); j++) {
      if (pairs[j].second > info[i].first && pairs[j].first < info[i].second) {
        good = false;
        break;
      }
    }
    if (!good) {
      continue;
    }
    pairs.push_back(info[i]);
    add1(num);
  }
  out << num.back();
  if (num.size() > 1) {
    out.fill('0');
    for (int i = num.size() - 2; i >= 0; i--) {
      out << std::setw(9) << num[i];
    }
  }
  out << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}