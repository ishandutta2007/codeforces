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
  int TT;
  cin >> TT;
  while (TT--) {
    int N, K;
    cin >> N >> K;
    vector<array<int, 4>> A(N);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < 4; ++j) {
        cin >> A[i][j];
        --A[i][j];
      }
    }

    auto Solve = [&](vector<array<int, 4>> inp) {
      vector<array<int, 4>> no;
      auto Add = [&](int x1, int y1, int x2, int y2) {
        assert(x1 == x2 || y1 == y2);
        if (min(x1, x2) >= K / 2) {
          x1 = K - x1;
          x2 = K - x2;
          y1 = K - y1;
          y2 = K - y2;
        }
        no.push_back({x1, y1, x2, y2});
        no.push_back({x2, y2, x1, y1});
      };

      for (auto[R1, C1, R2, C2] : inp) {
        if (R1 == R2) {
          if (C1 > C2) {
            swap(C1, C2);
          }
          debug(C1, C2, R1);
          Add(R1, C1 + 1, R1 + 1, C1 + 1);
        } else {
          if (R1 > R2) {
            swap(R1, R2);
          }
          debug(R1, R2, C1);
          if (R1 == K / 2 - 1) {
            debug("middle");
            Add(R1 + 1, C1, R1 + 1, C1 + 1);
            Add(R1 + 1, K - C1, R1 + 1, K - C1 - 1);          
          } else {
            Add(R1 + 1, C1, R1 + 1, C1 + 1);
          }
        }
      }
      sort(no.begin(), no.end());

      debug(no);
      vector<vector<int>> dist(K / 2 + 1, vector<int>(K + 1, N));
      vector<vector<array<int, 2>>> que(N);
      que[0].push_back({0, 0});
      dist[0][0] = 0;
      const int dx[] = {0, 0, -1, +1}, dy[] = {1, -1, 0, 0};
      vector<vector<bool>> vis(K / 2 + 1, vector<bool>(K + 1, false));
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < int(que[i].size()); ++j) {
          auto[x, y] = que[i][j];
          if (vis[x][y]) {
            continue;
          }
          debug(x, y, i); 
          vis[x][y] = true;
          for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || nx > K / 2 || ny < 0 || ny > K) {
              continue;
            }

            int add = int(lower_bound(no.begin(), no.end(), array{x, y, nx, ny + 1}) - lower_bound(no.begin(), no.end(), array{x, y, nx, ny}));
            int ndist = dist[x][y] + add;
            debug(nx, ny, ndist, add);
            if (ndist < dist[nx][ny]) {
              dist[nx][ny] = ndist;
              que[ndist].push_back({nx, ny});
            }
          }
        }
      }
      debug(dist);
      return N - dist[K / 2][K / 2];
    };
    int ans = Solve(A);
    for (auto& e : A) {
      swap(e[0], e[1]);
      swap(e[2], e[3]);
    }
    ans = max(ans, Solve(A));
    cout << ans << '\n';

  }
}