#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

int main() {
  int nt;
  scanf("%d", &nt);
  for (int t = 0; t < nt; ++t) {
    int n;
    scanf("%d", &n);
    vector<array<int, 5>> ranks(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
        scanf("%d", &ranks[i][j]);
      }
    }
    auto is_superior = [&](int a, int b) {
      int score_a = 0;
      for (int j = 0; j < 5; ++j) {
        if (ranks[a][j] < ranks[b][j]) {
          ++score_a;
        }
      }
      return score_a >= 3;
    };
    int cand = 0;
    for (int i = 1; i < n; ++i)
      if (is_superior(i, cand))
        cand = i;
    bool win = true;
    for (int i = 0; i < n; ++i)
      if (i != cand && !is_superior(cand, i)) {
        win = false;
        break;
      }
    if (!win) cand = -1;
    printf("%d\n", cand == -1 ? -1 : cand + 1);
  }
  return 0;
}