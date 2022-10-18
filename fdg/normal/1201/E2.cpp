#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2},
    dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int n, m, x1, y1, x2, y2;

bool can(int x, int y, int t) {
  return 1 <= x + dx[t] && x + dx[t] <= n
      && 1 <= y + dy[t] && y + dy[t] <= m;
}

int distB[1002][1002], distW[1002][1002];

void bfs(int f[1002][1002], int x, int y) {
  memset(f, -1, sizeof(int) * 1002 * 1002);
  f[x][y] = 0;

  vector<pair<int, int>> q(1, {x, y});
  for (int i = 0; i < q.size(); ++i) {
    x = q[i].first, y = q[i].second;
    for (int t = 0; t < 8; ++t) {
      if (can(x, y, t) && f[x + dx[t]][y + dy[t]] == -1) {
        f[x + dx[t]][y + dy[t]] = f[x][y] + 1;
        q.push_back({x + dx[t], y + dy[t]});
      }
    }
  }
}

int getDist(int x, int y, int x2, int y2) {
  int f[1001][1001] = {0};
  memset(f, -1, sizeof(f));
  f[x][y] = 0;

  vector<pair<int, int>> q(1, {x, y});
  for (int i = 0; i < q.size(); ++i) {
    x = q[i].first, y = q[i].second;
    for (int t = 0; t < 8; ++t) {
      if (can(x, y, t) && f[x + dx[t]][y + dy[t]] == -1) {
        f[x + dx[t]][y + dy[t]] = f[x][y] + 1;
        q.push_back({x + dx[t], y + dy[t]});
      }
    }
  }
  return f[x2][y2];
}

bool canKill(int x1, int y1, int x2, int y2) {
  return (abs(x1 - x2) == 1 && abs(y1 - y2) == 2)
      || (abs(x1 - x2) == 2 && abs(y1 - y2) == 1);
}

pair<int, int> findW(int x, int y, int x2, int y2) {
  pair<int, int> ret = {-1, -1};
  int bestD = 1e+9, best2;

  for (int t = 0; t < 8; ++t) {
    if (can(x, y, t) && !canKill(x + dx[t], y + dy[t], x2, y2)) {
      if (bestD > distW[x + dx[t]][y + dy[t]]
        || (bestD == distW[x + dx[t]][y + dy[t]] && best2 > distB[x + dx[t]][y + dy[t]])) {
        bestD = distW[x + dx[t]][y + dy[t]];
        best2 = distB[x + dx[t]][y + dy[t]];
        ret = {x + dx[t], y + dy[t]};
      }
    }
  }

  return ret;
}

pair<int, int> findB(int x1, int y1, int x, int y) {
  pair<int, int> ret = {-1, -1};
  int bestD = 1e+9, best2;

  for (int t = 0; t < 8; ++t) {
    if (can(x, y, t) && !canKill(x + dx[t], y + dy[t], x1, y1)) {
      if (bestD > distB[x + dx[t]][y + dy[t]]
        || (bestD == distB[x + dx[t]][y + dy[t]] && best2 > distW[x + dx[t]][y + dy[t]])) {
        bestD = distB[x + dx[t]][y + dy[t]];
        best2 = distW[x + dx[t]][y + dy[t]];
        ret = {x + dx[t], y + dy[t]};
      }
    }
  }

  return ret;
}

void goWhite(int target, bool isTerminal, bool announce = true) {
  if (announce) cout << "WHITE" << endl;

  while (true) {
    if (canKill(x1, y1, x2, y2)) {
      cout << x2 << " " << y2 << endl;
      exit(0);
    }

    pair<int, int> mv = findW(x1, y1, x2, y2);
    x1 = mv.first, y1 = mv.second;
    cout << x1 << " " << y1 << endl;

    if (distW[x1][y1] == target && isTerminal) exit(0);
    cin >> x2 >> y2;
    if (distW[x1][y1] == target) return;
  }
}

void goBlack(int target, bool isTerminal, bool announce = true) {
  if (announce) {
    cout << "BLACK" << endl;
    cin >> x1 >> y1;
  }

  while (true) {
    if (canKill(x1, y1, x2, y2)) {
      cout << x1 << " " << y1 << endl;
      exit(0);
    }

    pair<int, int> mv = findB(x1, y1, x2, y2);
    x2 = mv.first, y2 = mv.second;
    cout << x2 << " " << y2 << endl;

    if (distB[x2][y2] == target && isTerminal) exit(0);
    cin >> x1 >> y1;
    if (distB[x2][y2] == target) return;
  }
}

const bool PRINT_DEBUG = false;

int main() {
  cin >> n >> m >> x1 >> y1 >> x2 >> y2;

  bfs(distW, n / 2, m / 2);
  bfs(distB, n / 2 + 1, m / 2);

  if (PRINT_DEBUG) {
    cout << distW[x1][y1] << "  " << distB[x1][y1] << endl;
    cout << distW[x2][y2] << "  " << distB[x2][y2] << endl;
  }

  if (distW[x1][y1] < distB[x2][y2] && distW[x1][y1] + 1 < distW[x2][y2]) {
    if (PRINT_DEBUG) cout << "A" << endl;
    goWhite(0, true);
  }

  if (distW[x1][y1] - 1 > distB[x2][y2] && distB[x1][y1] > distB[x2][y2] + 1) {
    if (PRINT_DEBUG) cout << "B" << endl;
    goBlack(0, true);
  }

  if (distW[x1][y1] < distW[x2][y2] && distW[x1][y1] < distB[x2][y2]) {
    if (PRINT_DEBUG) cout << "C" << endl;
    bool hasGood = false;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (distW[i][j] == 1 && getDist(i, j, x2, y2) > getDist(i, j, x1, y1) + 1) {
          bfs(distW, i, j);
          distW[n / 2][m / 2] = -1;

          goWhite(-1, true);
        }
  }

  if (distB[x1][y1] - 1 > distB[x2][y2] && distB[x2][y2] < distW[x1][y1]) {
    if (PRINT_DEBUG) cout << "D" << endl;
    bool hasGood = false;
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (distB[i][j] == 1 && getDist(i, j, x2, y2) + 1 < getDist(i, j, x1, y1)) {
          bfs(distB, i, j);
          distB[n / 2 + 1][m / 2] = -1;

          goBlack(-1, true);
        }
  }

  if ((x1 + y1) % 2 != (x2 + y2) % 2) {
    if (PRINT_DEBUG) cout << "E" << endl;
    if (distW[x1][y1] <= distB[x2][y2]) goWhite(0, true);

    bfs(distW, n / 2 + 1, m / 2);
    goWhite(0, false);

    bfs(distW, n / 2, m / 2);
    goWhite(0, true, false);
  } else {
    if (PRINT_DEBUG) cout << "F" << endl;
    if (distW[x1][y1] > distB[x2][y2]) goBlack(0, true);

    bfs(distB, n / 2, m / 2);
    goBlack(0, false);

    bfs(distB, n / 2 + 1, m / 2);
    goBlack(0, true, false);
  }

  return 0;
}