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

const int ntask = 5, vasya = 0, petya = 1;

int get_score(int a, int b) {
  if (2*a > b) return 500;
  if (4*a > b) return 1000;
  if (8*a > b) return 1500;
  if (16*a > b) return 2000;
  if (32*a > b) return 2500;
  return 3000;
}

int get_max_diff_for_task(vector<vector<int>> &solved_at, int extra_players,
                          int task) {
  int n = solved_at.size();
  int solved = 0;
  for (int i = 0; i < n; ++i)
    if (solved_at[i][task] != -1)
      ++solved;

  int max_diff = INT_MIN;
  for (int extra_solved = 0; extra_solved <= extra_players; ++extra_solved) {
    if (extra_solved > 0 && solved_at[vasya][task] == -1)
      break;
    int score = get_score(solved + extra_solved, n + extra_players);
    int score_v = 0;
    if (solved_at[vasya][task] != -1)
      score_v = score * (250 - solved_at[vasya][task]);
    int score_p = 0;
    if (solved_at[petya][task] != -1)
      score_p = score * (250 - solved_at[petya][task]);
    max_diff = max(max_diff, score_v - score_p);
  }
  return max_diff;
}

bool can_win(vector<vector<int>> &solved_at, int extra_players) {
  int max_diff = 0;
  for (int task = 0; task < ntask; ++task) {
    max_diff += get_max_diff_for_task(solved_at, extra_players, task);
  }
  return max_diff > 0;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<vector<int>> solved_at(n, vector<int>(ntask));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < ntask; ++j)
      scanf("%d", &solved_at[i][j]);

  for (int extra_players = 0; extra_players <= 32 * n; ++extra_players)
    if (can_win(solved_at, extra_players)) {
      printf("%d\n", extra_players);
      return 0;
    }
  printf("-1\n");
  return 0;
}