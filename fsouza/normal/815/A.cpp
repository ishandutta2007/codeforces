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
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> target(n, vector<int>(m));
  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      scanf("%d", &target[y][x]);
    }
  }
  int best_result = INT_MAX;
  vector<tuple<int, int, int>> best_movements;
  vector<int> col_add(m);
  for (int row0 = 0; row0 <= target[0][0]; ++row0) {
    int cost = 0;
    static vector<tuple<int, int, int>> movements;
    movements.clear();

    cost += row0;
    movements.emplace_back(0, 0, row0);

    bool ok = true;
    for (int x = 0; x < m; ++x) {
      col_add[x] = target[0][x] - row0;
      if (col_add[x] < 0) {
        ok = false;
        break;
      }
      cost += col_add[x];
      movements.emplace_back(1, x, col_add[x]);
    }
    if (!ok) continue;

    for (int y = 1; y < n; ++y) {
      int line_add = target[y][0] - col_add[0];
      if (line_add < 0) {
        ok = false;
        break;
      }
      cost += line_add;
      movements.emplace_back(0, y, line_add);
      for (int x = 1; x < m; ++x) {
        int check_line_add = target[y][x] - col_add[x];
        if (check_line_add != line_add) {
          ok = false;;
          break;
        }
      }
      if (!ok) break;
    }
    if (!ok) continue;

    if (cost < best_result) {
      best_result = cost;
      best_movements = movements;
    }
  }

  if (best_result == INT_MAX) printf("-1\n");
  else {
    printf("%d\n", best_result);
    for (tuple<int, int, int> movement : best_movements) {
      int kind, pos, many;
      tie(kind, pos, many) = movement;
      for (int rep = 0; rep < many; ++rep) {
        if (kind == 0) printf("row %d\n", pos + 1);
        else printf("col %d\n", pos + 1);
      }
    }
  }

  return 0;
}