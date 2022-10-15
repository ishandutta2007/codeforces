// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }

    array<int, 2> dd[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> deg(N, vector<int>(M, -1));
    array<int, 2> start = {};
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        if (A[i][j] == '.') {
          deg[i][j] = 0;
          for (auto[dx, dy] : dd) {
            int nx = i + dx;
            int ny = j + dy;
            deg[i][j] += (nx >= 0 && nx < N && ny >= 0 && ny < M && A[nx][ny] != '#');
          }                                                                            
        } else if (A[i][j] == 'L') {
          start = {i, j};  
        }
      }
    }
    debug(deg);

    queue<array<int, 2>> que;
    que.push(start);
    while (!que.empty()) {
      auto[x, y] = que.front();
      que.pop();
      if (array{x, y} != start) {
        A[x][y] = '+';
      }
      for (auto[dx, dy] : dd) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && deg[nx][ny] != -1) {
          deg[nx][ny] -= 1;
          if (deg[nx][ny] <= 1) {
            que.push({nx, ny});
            deg[nx][ny] = -1;
          }
        }   
      }
    }    
    for (auto e : A) {
      cout << e << '\n';
    }
  }
}