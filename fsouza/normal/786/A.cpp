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

enum result_t {
  LOOP = -1,
  LOSE = 0,
  WIN = 1,
};

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> deltas(2);
  for (int j = 0; j < 2; ++j) {
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
      int delta;
      scanf("%d", &delta);
      deltas[j].push_back(delta);
    }
  }
  vector<vector<result_t>> result(2, vector<result_t>(n, LOOP));
  vector<vector<int>> next_non_win_count = {
    vector<int>(n, deltas[0].size()),
    vector<int>(n, deltas[1].size())};

  queue<pair<int, int>> q;
  result[0][0] = result[1][0] = LOSE;
  q.emplace(0, 0);
  q.emplace(1, 0);
  while (!q.empty()) {
    int player, pos;
    tie(player, pos) = q.front(); q.pop();
    int other_player = player ^ 1;
    if (result[player][pos] == LOSE) {
      for (int d : deltas[other_player]) {
        int other_pos = pos - d;
        if (other_pos < 0) other_pos += n;
        if (result[other_player][other_pos] == LOOP) {
          result[other_player][other_pos] = WIN;
          q.emplace(other_player, other_pos);
        }
      }
    } else {
      assert(result[player][pos] == WIN);
      for (int d : deltas[other_player]) {
        int other_pos = pos - d;
        if (other_pos < 0) other_pos += n;
        --next_non_win_count[other_player][other_pos];
        if (next_non_win_count[other_player][other_pos] == 0 &&
            result[other_player][other_pos] == LOOP) {
          result[other_player][other_pos] = LOSE;
          q.emplace(other_player, other_pos);
        }
      }
    }
  }
  for (int j = 0; j < 2; ++j) {
    for (int i = 1; i < n; ++i) {
      if (i > 1) printf(" ");
      if (result[j][i] == LOOP) printf("Loop");
      else if (result[j][i] == LOSE) printf("Lose");
      else printf("Win");
    }
    printf("\n");
  }
  return 0;
}