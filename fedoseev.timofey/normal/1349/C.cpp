#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 1e6 + 7;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m, t;
  cin >> n >> m >> t;
  vector <vector <int>> a(n, vector <int> (m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }
  vector <vector <int>> when(n, vector <int> (m, -1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (i + 1 < n && a[i][j] == a[i + 1][j]) {
        when[i][j] = 0;
        when[i + 1][j] = 0;
      }
      if (j + 1 < m && a[i][j] == a[i][j + 1]) {
        when[i][j] = 0;
        when[i][j + 1] = 0;
      }
    }
  }
  queue <pair <int, int>> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (when[i][j] != -1) {
        q.push({i, j});
      }
    }
  }
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    int i = p.first, j = p.second;

    for (int dx = -1; dx <= 1; ++dx) {
      for (int dy = -1; dy <= 1; ++dy) {
        if (dx * dx + dy * dy == 1) {
          int x = i + dx, y = j + dy;
          if (0 <= x && x < n && 0 <= y && y < m) {
            if (when[x][y] == -1) {
              when[x][y] = when[i][j] + 1;
              q.push({x, y});
            }
          }
        }
      }
    }
  }
  while (t--) {
    int x, y; ll p;
    cin >> x >> y >> p;
    --x, --y;
    if (when[x][y] == -1 || when[x][y] >= p) {
      cout << a[x][y] << '\n';
    } else {
      cout << (a[x][y] ^ ((p - when[x][y]) % 2)) << '\n';
    }
  }
}