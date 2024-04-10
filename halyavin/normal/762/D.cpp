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

struct Solution {
  using State = std::vector<int>;
  std::vector<State> states;
  std::vector<std::pair<int, int>> transitions;
  int n;
  std::vector<std::array<int, 3>> data;
  Solution() :
      states{
          {0},
          {0, 1},
          {0, 1, 2},
          {1},
          {0, 1},
          {1, 2},
          {2},
          {1, 2},
          {0, 1, 2},
          {0, 1, 2},
          {0, 1, 2}
      },
      transitions{
          {0, 0},
          {0, 4},
          {0, 8},
          {0, 9},
          {1, 0},
          {1, 4},
          {1, 8},
          {1, 9},
          {2, 0},
          {2, 4},
          {2, 8},
          {2, 9},

          {3, 1},
          {3, 3},
          {3, 7},
          {4, 1},
          {4, 3},
          {4, 7},
          {5, 1},
          {5, 3},
          {5, 7},

          {6, 2},
          {6, 5},
          {6, 6},
          {6, 10},
          {7, 2},
          {7, 5},
          {7, 6},
          {7, 10},
          {8, 2},
          {8, 5},
          {8, 6},
          {8, 10},

          {9, 8},
          {9, 9},

          {10, 10},
          {10, 2}
      } {}

  void run(std::istream& in, std::ostream& out) {
    in >> n;
    data.resize(n);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < n; j++) {
        in >> data[j][i];
      }
    }
    std::vector<std::array<int64_t, 11>> dyn(n);
    std::fill(dyn[0].begin(), dyn[0].end(), -(1LL << 60));
    dyn[0][0] = data[0][0];
    dyn[0][4] = data[0][0] + int64_t(data[0][1]);
    dyn[0][8] = data[0][0] + int64_t(data[0][1]) + data[0][2];
    dyn[0][9] = data[0][0] + int64_t(data[0][1]) + data[0][2];
    std::array<int64_t, 11> sums;
    for (int i = 1; i < n; i++) {
      std::fill(dyn[i].begin(), dyn[i].end(), -(1LL << 60));
      for (size_t j = 0; j < sums.size(); j++) {
        int64_t res = 0;
        for (int k : states[j]) {
          res += data[i][k];
        }
        sums[j] = res;
      }
      for (auto& transition : transitions) {
        int from = transition.first;
        int to = transition.second;
        dyn[i][to] = std::max(dyn[i][to], dyn[i - 1][from] + sums[to]);
      }
    }
    int64_t res = std::max({dyn[n - 1][6], dyn[n - 1][7], dyn[n - 1][8]});
    out << res << std::endl;
  }
};

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  Solution().run(std::cin, std::cout);
  return 0;
}