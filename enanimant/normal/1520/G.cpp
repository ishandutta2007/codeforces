/*
 * author:  ADMathNoob
 * created: 05/05/21 12:07:44
 * problem: https://codeforces.com/contest/1520/problem/G
 */

/*
g++ 1520G.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1520G.cpp -std=c++11 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wfatal-errors -O3


*/

#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
const int N = 2005;
const int di[4] = {1, 0, -1, 0};
const int dj[4] = {0, 1, 0, -1};

int n, m, w;
int a[N][N];

long long dist_start[N][N];
long long dist_end[N][N];

bool InRange(int i, int j) {
  return (0 <= i && i < n && 0 <= j && j < m);
}

void Bfs(int si, int sj, long long (&dist)[N][N]) {
  memset(dist, -1, sizeof dist);
  dist[si][sj] = 0;
  vector<pair<int, int>> que(1, {si, sj});
  for (int b = 0; b < (int) que.size(); b++) {
    int i, j;
    tie(i, j) = que[b];
    for (int d = 0; d < 4; d++) {
      int ni = i + di[d];
      int nj = j + dj[d];
      if (!InRange(ni, nj) || a[ni][nj] == -1 || dist[ni][nj] != -1) {
        continue;
      }
      dist[ni][nj] = dist[i][j] + 1;
      que.emplace_back(ni, nj);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> w;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  Bfs(0, 0, dist_start);
  Bfs(n - 1, m - 1, dist_end);

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cerr << dist_start[i][j] << ' ';
  //   }
  //   cerr << '\n';
  // }
  // cerr << '\n';
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     cerr << dist_end[i][j] << ' ';
  //   }
  //   cerr << '\n';
  // }
  // cerr << '\n';
  
  long long best_from_start = inf;
  long long best_from_end = inf;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (dist_start[i][j] != -1 && a[i][j] > 0) {
        best_from_start = min(best_from_start, dist_start[i][j] * w + a[i][j]);
      }
      if (dist_end[i][j] != -1 && a[i][j] > 0) {
        best_from_end = min(best_from_end, dist_end[i][j] * w + a[i][j]);
      }
    }
  }
  long long ans = best_from_start + best_from_end;
  if (dist_start[n - 1][m - 1] != -1) {
    ans = min(ans, dist_start[n - 1][m - 1] * w);
  }
  cout << (ans < inf ? ans : -1) << '\n';
  return 0;
}