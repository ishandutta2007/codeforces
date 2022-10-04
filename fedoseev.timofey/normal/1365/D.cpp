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

vector <int> dx = {0, 0, -1, 1};
vector <int> dy = {-1, 1, 0, 0};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <vector <char>> a(n, vector <char> (m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }
    auto ok = [&] (int x, int y) {
      return 0 <= x && x < n && 0 <= y && y < m;
    }; 
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] == 'B') {
          for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (ok(x, y) && a[x][y] == '.') {
              a[x][y] = '#';
            }
          }
        }
      }
    }
    vector <vector <int>> vis(n, vector <int> (m));
    queue <pair <int, int>> q;
    if (a[n - 1][m - 1] != '#') {
      vis[n - 1][m - 1] = 1;
      q.push({n - 1, m - 1});
    }
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      int x = p.first, y = p.second;
      for (int k = 0; k < 4; ++k) {
        int tx = x + dx[k], ty = y + dy[k];
        if (ok(tx, ty) && a[tx][ty] != '#' && !vis[tx][ty]) {
          vis[tx][ty] = 1;
          q.push({tx, ty});
        }
      }
    }
    bool good = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (a[i][j] == 'G') good &= vis[i][j];
        if (a[i][j] == 'B') good &= !vis[i][j];
      }
    }
    cout << (good ? "Yes" : "No") << '\n';
  }
}