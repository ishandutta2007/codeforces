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
#include <array>

std::pair<int, int> cmp(const std::array<int, 4>& left, const std::array<int, 4>& right) {
  std::pair<int, int> result{0, 0};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (left[i] == right[j]) {
        if (i == j) {
          result.first++;
        } else {
          result.second++;
        }
      }
    }
  }
  return result;
};

int score(const std::array<int, 4>& comb, const std::vector<std::array<int, 4>>& combs) {
  std::array<std::array<int, 5>, 5> stat = {};
  for (const std::array<int, 4>& elem : combs) {
    std::pair<int, int> res = cmp(comb, elem);
    stat[res.first][res.second]++;
  }
  int maxV = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      maxV = std::max(maxV, stat[i][j]);
    }
  }
  return maxV;
}

std::array<int, 4> getGuess(const std::vector<std::array<int, 4>>& combs, const std::vector<std::array<int, 4>>& allCombs) {
  std::array<int, 4> result = combs[0];
  int opt = score(result, combs);
  for (size_t i = 1; i < 32u && i < combs.size(); i++) {
    int cur = score(combs[i], combs);
    if (cur < opt) {
      opt = cur;
      result = combs[i];
    }
  }
  for (size_t i = 1; i < 32u && i < allCombs.size(); i++) {
    int cur = score(allCombs[i], combs);
    if (cur < opt) {
      opt = cur;
      result = allCombs[i];
    }
  }
  return result;
}

void applyGuess(const std::array<int, 4>& guess, const std::pair<int, int>& result, std::vector<std::array<int,4>>& combs) {
  auto it = std::stable_partition(combs.begin(), combs.end(), [&guess, &result](const std::array<int, 4>& var) {
    return cmp(var, guess) == result;
  });
  combs.erase(it, combs.end());
}

std::vector<std::array<int, 4>> generateCombs() {
  std::vector<std::array<int, 4>> combs;
  for (int i1 = 0; i1 <= 9; i1++) {
    for (int i2 = 0; i2 <= 9; i2++) {
      if (i2 != i1) {
        for (int i3 = 0; i3 <= 9; i3++) {
          if (i3 != i1 && i3 != i2) {
            for (int i4 = 0; i4 <= 9; i4++) {
              if (i4 != i3 && i4 != i2 && i4 != i1) {
                combs.push_back(std::array<int, 4>{i1, i2, i3, i4});
              }
            }
          }
        }
      }
    }
  }
  size_t j = 124;
  for (size_t i = 1; i < combs.size(); i++) {
    size_t j = (j * 35 + 3) ^ (j >> 2);
    std::swap(combs[i], combs[j % i]);
  }
  return combs;
};

void run(std::istream &in, std::ostream &out) {
  std::vector<std::array<int, 4>> allCombs = generateCombs();
  std::vector<std::array<int, 4>> combs = allCombs;
  while (true) {
    std::array<int, 4> guess = getGuess(combs, allCombs);
    for (size_t i = 0; i < guess.size(); i++) {
      out << guess[i];
    }
    out << std::endl;
    out.flush();
    std::pair<int, int> res;
    in >> res.first >> res.second;
    if (res.first == 4) return;
    applyGuess(guess, res, combs);
  }
}

void totalCheck() {
  std::vector<std::array<int, 4>> allCombs = generateCombs();
  for (size_t i = 0; i < allCombs.size(); i++) {
    std::array<int, 4> ans = allCombs[i];
    for (int j = 0; j < 4; j++) {
      std::cerr << ans[j];
    }
    std::cerr << std::endl;
    std::vector<std::array<int, 4>> curCombs = allCombs;
    int iter = 0;
    while (true) {
      std::array<int, 4> guess = getGuess(curCombs, allCombs);
      std::pair<int, int> res = cmp(guess, ans);
      iter++;
      if (res.first == 4) break;
      applyGuess(guess, res, curCombs);
    }
    if (iter > 7) {
      std::cerr << "failed" << std::endl;
      return;
    }
  }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  //totalCheck();
  run(std::cin, std::cout);
  return 0;
}