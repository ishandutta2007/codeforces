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

  vector<int> dx = {0, 0, -1, 1};
  vector<int> dy = {-1, 1, 0, 0};

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    cin >> grid;
    bool ans = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 'B') {
          for (int d = 0; d < 4; ++d) {
            int x = i + dx[d], y = j + dy[d];
            if (x >= 0 && x < n && y >= 0 && y < m) {
              if (grid[x][y] == '.')
                grid[x][y] = '#';
            }
          }
        }
      }
    }
    vector<vector<int>> vis(n, vector<int>(m));
    queue<pair<int, int>> q;
    auto ins = [&](int x, int y) {
      if (grid[x][y] != '#' && !vis[x][y]) {
        q.emplace(x, y);
        vis[x][y] = 1;
      }
    };
    ins(n - 1, m - 1);
    while (!q.empty()) {
      int x, y;
      tie(x, y) = q.front();
      q.pop();
      for (int d = 0; d < 4; ++d) {
        int gx = x + dx[d], gy = y + dy[d];
        if (gx >= 0 && gx < n && gy >= 0 && gy < m)
          ins(gx, gy);
      }
    }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (grid[i][j] == 'G' && !vis[i][j] || grid[i][j] == 'B' && vis[i][j])
          ans = false;
    cout << (ans ? "Yes\n" : "No\n");
  }

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}