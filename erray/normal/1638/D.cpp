// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> A[i][j];
    }
  }

  vector<vector<vector<array<int, 2>>>> act(N - 1, vector<vector<array<int, 2>>>(M - 1));
  for (int i = 0; i < N - 1; ++i) {
    for (int j = 0; j < M - 1; ++j) {
      for (int ai = 0; ai < 2; ++ai) {
        for (int aj = 0; aj < 2; ++aj) {
          act[i][j].push_back({i + ai, j + aj});
        }
      }
    }
  }
  debug(act);
  
 	vector<array<int, 3>> que;
  vector<vector<bool>> used(N - 1, vector<bool>(M - 1));
  auto Check = [&](int x, int y) {
    if (used[x][y] || act[x][y].empty()) {
      return;
    }
    int first = -1;
    for (auto[i, j] : act[x][y]) {
      if (first == -1) {
        first = A[i][j];
      } else if (first != A[i][j]) {
        return;
      }
    }
    used[x][y] = true;  
    que.push_back({x, y, first});
  };

  for (int i = 0; i < N - 1; ++i) {
    for (int j = 0; j < M - 1; ++j) {
      Check(i, j);
    }
  }
  for (int it = 0; it < int(que.size()); ++it) {
    auto[x, y, c] = que[it];
    vector<array<int, 2>> check;
    for (int ax = 0; ax < 2; ++ax) {
      for (int ay = 0; ay < 2; ++ay) {
        int nx = x + ax;
        int ny = y + ay;
        if (A[nx][ny] != -1) {
          A[nx][ny] = -1;
          for (int anx : {0, -1}) {
            for (int any : {0, -1}) {
              int cnx = nx + anx;
              int cny = ny + any;
              if (cnx < 0 || cny < 0 || cnx == N - 1 || cny == M - 1) {
                continue;
              }
              act[cnx][cny].erase(find(act[cnx][cny].begin(), act[cnx][cny].end(), array{nx, ny}));
              check.push_back({cnx, cny});
            }
          }
        }
      }
    }
    for (auto[i, j] : check) {
      Check(i, j);
    }
  }
  reverse(que.begin(), que.end());
  bool ok = true;
  for (int i = 0; i < N - 1; ++i) {
    for (int j = 0; j < M - 1; ++j) {
      ok &= (A[i][j] == -1);
    }
  }
  if (ok) {
    cout << int(que.size()) << '\n';
    for (auto[i, j, c] : que) {
      cout << i + 1 << ' ' << j + 1 << ' ' << c << '\n';
    }
  } else {
    cout << -1 << '\n';
  }
}