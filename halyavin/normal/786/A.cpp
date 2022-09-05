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
#include <queue>
#include <array>

struct Solution {
  int n;
  std::array<std::vector<int>, 2> s;
  std::vector<int> s2;
  std::vector<std::array<int, 2>> state;
  std::queue<std::pair<int, int>> queue;
  void run(std::istream& in, std::ostream& out) {
    in >> n;
    int k1;
    in >> k1;
    s[0].resize(k1);
    for (int i = 0; i < k1; i++) {
      in >> s[0][i];
    }
    int k2;
    in >> k2;
    s[1].resize(k2);
    for (int i = 0; i < k2; i++) {
      in >> s[1][i];
    }
    state.assign(n, std::array<int, 2>{-k1, -k2});
    state[0] = std::array<int, 2>{0, 0};
    queue.emplace(0, 0);
    queue.emplace(1, 0);
    while (!queue.empty()) {
      auto cur = queue.front();
      queue.pop();
      int flag = state[cur.second][cur.first];
      int other = 1 - cur.first;
      if (flag == 0) {
        for (int move : s[other]) {
          int pos = (move + cur.second) % n;
          if (state[pos][other] < 0) {
            state[pos][other] = 1;
            queue.emplace(other, pos);
          }
        }
      } else {
        for (int move : s[other]) {
          int pos = (move + cur.second) % n;
          if (state[pos][other] < 0) {
            state[pos][other]++;
            if (state[pos][other] == 0) {
              queue.emplace(other, pos);
            }
          }
        }
      }
    }
    for (int player = 0; player < 2; player++) {
      for (int i = n - 1; i > 0; i--) {
        if (state[i][player] == 1) {
          out << "Win ";
        } else if (state[i][player] == 0) {
          out << "Lose ";
        } else {
          out << "Loop ";
        }
      }
      out << std::endl;
    }
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}