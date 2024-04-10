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
  vector<vector<int>> mat(N, vector<int>(M));
  int mx = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cin >> mat[i][j];
      mx = max(mx, mat[i][j]);
      --mat[i][j];
    }
  }

  vector<vector<int>> posX(mx);
  vector<vector<int>> posY(mx);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      posX[mat[i][j]].push_back(i);
      posY[mat[i][j]].push_back(j);
    }
  }

  long long ans = 0;
  for (auto v : {posX, posY}) {
    for (auto e : v) {
      sort(e.begin(), e.end());
      long long sum = 0;
      for (int i = 0; i < int(e.size()); ++i) {
        ans += 1LL * i * e[i] - sum;
        sum += e[i];      
      }
    }
  }
  cout << ans << '\n';
}