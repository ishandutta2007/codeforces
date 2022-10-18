#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

vector<pair<int, int> > q;
char f[505][505];
bool used[505][505];
int n, m;

int dx[] = {-1, 0, 0, 1},
    dy[] = {0, -1, 1, 0};

bool in(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
  int k;
  scanf("%d%d%d\n", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    gets(f[i]);
  }
  for (int i = 0; i < n && q.size() == 0; ++i) {
    for (int j = 0; j < m && q.size() == 0; ++j) {
      if (f[i][j] == '.') {
        q.push_back(make_pair(i, j));
        used[i][j] = true;
      }
    }
  }
  for (int i = 0; i < q.size(); ++i) {
    int x = q[i].first, y = q[i].second;
    for (int t = 0; t < 4; ++t) {
      int nx = x + dx[t], ny = y + dy[t];
      if (in(nx, ny) && !used[nx][ny] && f[nx][ny] == '.') {
        q.push_back(make_pair(nx, ny));
        used[nx][ny] = true;
      }
    }
  }
  for (int i = 1; i <= k; ++i) {
    f[q[q.size() - i].first][q[q.size() - i].second] = 'X';
  }
  for (int i = 0; i < n; ++i)
    puts(f[i]);
  return 0;
}