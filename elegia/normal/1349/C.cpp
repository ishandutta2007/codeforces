#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, Q;
  cin >> n >> m >> Q;
  vector<string> grid(n);
  cin >> grid;
  vector<vector<int>> dis(n, vector<int>(m, -1));
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j < m; ++j) {
      if (grid[i][j] == grid[i][j - 1])
        dis[i][j] = dis[i][j - 1] = 0;
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < m; ++j)
      if (grid[i][j] == grid[i - 1][j])
        dis[i][j] = dis[i - 1][j] = 0;
  }
  vector<int> dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
  queue<pair<int, int>> q;

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (dis[i][j] == 0)
        q.emplace(i, j);
  while (!q.empty()) {
    int x, y; tie(x, y) = q.front(); q.pop();
    for (int i = 0; i < 4; ++i) {
      int px = x + dx[i], py = y + dy[i];
      if (px >= 0 && px < n && py >= 0 && py < m)
        if (dis[px][py] == -1) {
          dis[px][py] = dis[x][y] + 1;
          q.emplace(px, py);
        }
    }
  }
  while (Q--) {
    int x, y; ll p;
    cin >> x >> y >> p;
    --x; --y;
    if (dis[x][y] == -1 || p < dis[x][y])
      cout << grid[x][y] << '\n';
    else
      cout << char(grid[x][y] ^ ((p - dis[x][y]) & 1)) << '\n';
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}