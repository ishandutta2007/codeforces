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

int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};

int main() {
  int len, n;
  scanf("%d %d", &len, &n);
  vector<pair<int, int>> init(n);
  for (int i = 0; i < n; ++i) {
    int y, x;
    scanf("%d %d", &y, &x), --y, --x;
    init[i] = {y, x};
  }
  struct cube_t {
    int ty = -1, tx = -1;
    int id = -1;
  };
  vector<vector<cube_t>> field(len, vector<cube_t>(len));
  vector<int> line_nt(len, 0);
  for (int i = 0; i < n; ++i) {
    int ty, tx;
    scanf("%d %d", &ty, &tx), --ty, --tx;
    field[init[i].first][init[i].second] = {ty, tx, i};
    line_nt[ty] += 1;
  }
  int mid_line = -1;
  for (int i = 0; i < len; ++i)
    if (line_nt[i] <= 1) {
      mid_line = i;
      break;
    }
  assert(mid_line != -1);

  struct op_t {
    int y0, x0, y1, x1;
  };
  vector<op_t> result;

  auto move = [&](int y, int x, int ty, int tx) {
    assert(abs(y - ty) + abs(x - tx) == 1);
    assert(field[ty][tx].id == -1);
    swap(field[y][x], field[ty][tx]);
    result.push_back({y, x, ty, tx});
  };

  auto greedy_move_x = [&](int y, int x, int ty, int tx) {
    while (x < tx) {
      move(y, x, y, x + 1);
      ++x;
    }
    while (x > tx) {
      move(y, x, y, x - 1);
      --x;
    }
    while (y < ty) {
      move(y, x, y + 1, x);
      ++y;
    }
    while (y > ty) {
      move(y, x, y - 1, x);
      --y;
    }
  };

  while (true) {
    queue<pair<int, int>> q;
    vector<vector<int>> mark(len, vector<int>(len, -1));
    for (int x = 0; x < len; ++x) {
      if (field[mid_line][x].id == -1) {
        mark[mid_line][x] = x;
        q.emplace(mid_line, x);
      } else {
        mark[mid_line][x] = -2;
      }
    }
    int closest_y = -1, closest_x = -1;
    while (!q.empty()) {
      pair<int, int> yx = q.front();
      q.pop();
      int y, x;
      tie(y, x) = yx;
      if (y != mid_line && field[y][x].id != -1) {
        closest_y = y;
        closest_x = x;
        break;
      }
      for (int d = 0; d < 4; ++d) {
        int y2 = y + dy[d], x2 = x + dx[d];
        if (0 <= min(y2, x2) && max(y2, x2) < len && mark[y2][x2] == -1) {
          mark[y2][x2] = mark[y][x];
          q.emplace(y2, x2);
        }
      }
    }
    if (closest_y == -1) break;

    greedy_move_x(closest_y, closest_x, mid_line, mark[closest_y][closest_x]);
  }

  const int mid = mid_line;

  auto sort_mid_by_tx = [&](int aux) {
    for (int rep = 0; rep < 50; ++rep)
      for (int x = 0; x + 1 < len; ++x) {
        bool want_lr =
        field[mid][x].id != -1 && field[mid][x].tx > x;
        bool want_rl =
        field[mid][x + 1].id != -1 && field[mid][x + 1].tx < x + 1;

        if (want_lr && field[mid][x + 1].id == -1) {
          move(mid, x, mid, x + 1);
        } else if (want_rl && field[mid][x].id == -1) {
          move(mid, x + 1, mid, x);
        } else if (field[mid][x].id != -1 &&
                   field[mid][x + 1].id != -1 &&
                   field[mid][x].tx > field[mid][x + 1].tx) {
          move(mid, x, aux, x);
          move(mid, x + 1, mid, x);
          move(aux, x, aux, x + 1);
          move(aux, x + 1, mid, x + 1);
        }
      }
  };

  if (mid - 1 >= 0) {
    for (int x = 0; x < len; ++x)
      if (field[mid][x].id != -1 && field[mid][x].ty < mid) {
        move(mid, x, mid - 1, x);
      }
  }

  int special = -1;

  for (int x = 0; x < len; ++x) {
    cube_t cube = field[mid][x];
    if (cube.id != -1) {
      if (cube.ty == mid) {
        special = cube.id;
      }
    }
  }

  if (mid + 1 < len) {
    for (int ty = len - 1; ty >= mid + 2; --ty) {
      for (int x = 0; x < len; ++x) {
        cube_t cube = field[mid][x];
        if (cube.id != -1 && cube.ty == ty) {
          move(mid, x, mid + 1, x);
          greedy_move_x(mid + 1, x, cube.ty, cube.tx);
        }
      }
    }

    int special_tx = -1;
    if (line_nt[mid] == 1) {
      vector<bool> x_free(len, true);
      for (int x = 0; x < len; ++x) {
        cube_t cube = field[mid][x];
        if (cube.id != -1) {
          if (cube.ty == mid) {
            special = cube.id;
          } else {
            x_free[cube.tx] = false;
          }
        }
      }

      int first_free = -1;
      for (int x = 0; x < len; ++x)
        if (x_free[x]) {
          first_free = x;
          break;
        }
      assert(first_free != -1);

      for (int x = 0; x < len; ++x)
        if (field[mid][x].id == special) {
          special_tx = field[mid][x].tx;
          field[mid][x].tx = first_free;
          break;
        }
    }

    sort_mid_by_tx(mid + 1);

    for (int x = 0; x < len; ++x)
      if (field[mid][x].id != -1) {
        if (field[mid][x].id == special) {
          field[mid][x].tx = special_tx;
        } else {
          move(mid, x, mid + 1, x);
        }
      }
  }

  if (mid - 1 >= 0) {
    vector<bool> x_free(len, true);
    for (int x = 0; x < len; ++x)
      if (field[mid - 1][x].id != -1)
        x_free[x] = false;

    int first_free = -1;
    for (int x = 0; x < len; ++x)
      if (x_free[x]) {
        first_free = x;
        break;
      }

    for (int x = 0; x < len; ++x)
      if (field[mid][x].id != -1 && field[mid][x].id == special) {
        greedy_move_x(mid, x, mid, first_free);
        break;
      }

    for (int x = 0; x < len; ++x)
      if (field[mid - 1][x].id != -1)
        move(mid - 1, x, mid, x);
  }

  {
    for (int ty = 0; ty <= mid - 2; ++ty)
      for (int x = 0; x < len; ++x) {
        cube_t cube = field[mid][x];
        if (cube.id != -1 && cube.ty == ty) {
          move(mid, x, mid - 1, x);
          greedy_move_x(mid - 1, x, cube.ty, cube.tx);
        }
      }

    int special_tx = -1;
    if (line_nt[mid] == 1) {
      vector<bool> x_free(len, true);
      for (int x = 0; x < len; ++x) {
        cube_t cube = field[mid][x];
        if (cube.id != -1) {
          if (cube.ty == mid) {
            special = cube.id;
          } else {
            x_free[cube.tx] = false;
          }
        }
      }

      int first_free = -1;
      for (int x = 0; x < len; ++x)
        if (x_free[x]) {
          first_free = x;
          break;
        }
      assert(first_free != -1);

      for (int x = 0; x < len; ++x)
        if (field[mid][x].id == special) {
          special_tx = field[mid][x].tx;
          field[mid][x].tx = first_free;
          break;
        }
    }

    sort_mid_by_tx(mid - 1);

    for (int x = 0; x < len; ++x)
      if (field[mid][x].id != -1) {
        if (field[mid][x].id == special) {
          field[mid][x].tx = special_tx;
        } else {
          move(mid, x, mid - 1, x);
        }
      }
  }

  for (int x = 0; x < len; ++x)
    if (field[mid][x].id != -1 && field[mid][x].id == special) {
      greedy_move_x(mid, x, mid, field[mid][x].tx);
      break;
    }

  printf("%d\n", (int)result.size());
  for (op_t &op : result) {
    printf("%d %d %d %d\n", op.y0 + 1, op.x0 + 1, op.y1 + 1, op.x1 + 1);
  }

  return 0;
}