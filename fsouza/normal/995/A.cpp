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

struct move_t {
  int i, y, x;
};

bool greedy(vector<vector<int>> &field, vector<move_t> &moves) {
  int n = field[0].size();
  bool result = false;

  for (int x = 0; x < n; ++x)
    if (field[1][x] != -1 && field[0][x] == field[1][x]) {
      moves.push_back({field[1][x], 0, x});
      field[1][x] = -1;
      result = true;
    }

  for (int x = 0; x < n; ++x)
    if (field[2][x] != -1 && field[3][x] == field[2][x]) {
      moves.push_back({field[2][x], 3, x});
      field[2][x] = -1;
      result = true;
    }

  return result;
}

vector<pair<int, int>> seq;

bool rotate(vector<vector<int>> &field, vector<move_t> &moves) {
  bool ok = false;
  for (int i = 0; i < (int)seq.size(); ++i)
    if (field[seq[i].first][seq[i].second] == -1) {
      rotate(seq.begin(), seq.begin() + i, seq.end());
      ok = true;
      break;
    }
  if (!ok) return false;

  for (int i = 1; i < (int)seq.size(); ++i) {
    int car = field[seq[i].first][seq[i].second];
    if (car != -1) {
      moves.push_back({car, seq[i - 1].first, seq[i - 1].second});
      field[seq[i].first][seq[i].second] = -1;
      field[seq[i - 1].first][seq[i - 1].second] = car;
    }
  }

  return true;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<vector<int>> field(4, vector<int>(n));
  for (int y = 0; y < 4; ++y)
    for (int x = 0; x < n; ++x)
      scanf("%d", &field[y][x]), --field[y][x];

  for (int x = 0; x < n; ++x)
    seq.emplace_back(1, x);
  for (int x = n - 1; x >= 0; --x)
    seq.emplace_back(2, x);

  vector<move_t> moves;
  while (greedy(field, moves));

  int since_last = 0;
  while (rotate(field, moves)) {
    while (greedy(field, moves))
      since_last = 0;
    since_last += 1;

    if (since_last >= 500)
      break;
  }

  bool ok = true;
  for (int y = 1; y <= 2; ++y)
    for (int x = 0; x < n; ++x)
      if (field[y][x] != -1)
        ok = false;

  if (!ok) {
    printf("-1\n");
  } else {
    printf("%d\n", (int)moves.size());
    for (move_t move : moves) {
      printf("%d %d %d\n", move.i + 1, move.y + 1, move.x + 1);
    }
  }

  return 0;
}