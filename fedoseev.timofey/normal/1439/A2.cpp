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
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
 
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
    vector <vector <int>> a(n, vector <int> (m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        char c;
        cin >> c;
        a[i][j] = c - '0';
      }
    }
    vector <pair <int, int>> op;
    function <void(int, int)> make_zero = [&] (int x, int y) {
      int cnt = 0;
      for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
          cnt += a[x + i][y + j];
        }
      }
      if (cnt == 0) return;
      if (cnt == 3) {
        for (int i = 0; i < 2; ++i) {
          for (int j = 0; j < 2; ++j) {
            if (a[x + i][y + j]) {
              op.push_back({x + i, y + j});
            }
          }
        }
        for (int k = 0; k < 3; ++k) {
          int x = op[(int)op.size() - k - 1].first, y = op[(int)op.size() - k - 1].second;
          a[x][y] ^= 1;
        }
        return;
      }
      if (cnt == 4) {
        for (int i = 0; i < 2; ++i) {
          for (int j = 0; j < 2; ++j) {
            if (i == 0 && j == 0) continue;
            if (a[x + i][y + j]) {
              op.push_back({x + i, y + j});
            }
          }
        }
        for (int k = 0; k < 3; ++k) {
          int x = op[(int)op.size() - k - 1].first, y = op[(int)op.size() - k - 1].second;
          a[x][y] ^= 1;
        }
        make_zero(x, y);
        return;
      }
      if (cnt == 2) {
        for (int i = 0; i < 2; ++i) {
          for (int j = 0; j < 2; ++j) {
            if (!a[x + i][y + j]) {
              op.push_back({x + i, y + j});
            }
          }
        }
        int have = 0;
        for (int i = 0; i < 2; ++i) {
          for (int j = 0; j < 2; ++j) {
            if (!have && a[x + i][y + j]) {
              op.push_back({x + i, y + j});
              ++have;
            }
          }
        }
        for (int k = 0; k < 3; ++k) {
          int x = op[(int)op.size() - k - 1].first, y = op[(int)op.size() - k - 1].second;
          a[x][y] ^= 1;
        }
        make_zero(x, y);
        return;
      }
      if (cnt == 1) {
        for (int i = 0; i < 2; ++i) {
          for (int j = 0; j < 2; ++j) {
            if (a[x + i][y + j]) {
              op.push_back({x + i, y + j});
            }
          }
        }
        int have = 0;
        for (int i = 0; i < 2; ++i) {
          for (int j = 0; j < 2; ++j) {
            if (have < 2 && !a[x + i][y + j]) {
              op.push_back({x + i, y + j});
              ++have;
            }
          }
        }
        for (int k = 0; k < 3; ++k) {
          int x = op[(int)op.size() - k - 1].first, y = op[(int)op.size() - k - 1].second;
          a[x][y] ^= 1;
        }
        make_zero(x, y);
        return;
      }
      assert(false);
    };
    for (int i = 0; i + 1 < n; ++i) {
      for (int j = 0; j + 1 < m; ++j) {
        if (i == n - 2 && j == m - 2) continue;
        if (a[i][j]) {
          op.push_back({i, j});
          op.push_back({i, j + 1});
          op.push_back({i + 1, j});
          for (int k = 0; k < 3; ++k) {
            int x = op[(int)op.size() - k - 1].first, y = op[(int)op.size() - k - 1].second;
            a[x][y] ^= 1;
          }
        }
      }
    }
    for (int i = 0; i + 2 < n; ++i) {
      if (a[i][m - 1] == 1 || a[i][m - 2] == 1) {
        int cnt = 0;
        if (a[i][m - 1] == 1) {
          ++cnt;
          op.push_back({i, m - 1});
        }
        if (a[i][m - 2] == 1) {
          ++cnt;
          op.push_back({i, m - 2});
        }
        for (int d : {m - 2, m - 1}) {
          if (cnt < 3) {
            ++cnt;
            op.push_back({i + 1, d});
          }
        }
        for (int k = 0; k < 3; ++k) {
          int x = op[(int)op.size() - k - 1].first, y = op[(int)op.size() - k - 1].second;
          a[x][y] ^= 1;
        }
      }
    }
    for (int j = 0; j + 2 < m; ++j) {
      if (a[n - 1][j] == 1 || a[n - 2][j] == 1) {
        int cnt = 0;
        if (a[n - 1][j] == 1) {
          ++cnt;
          op.push_back({n - 1, j});
        }
        if (a[n - 2][j] == 1) {
          ++cnt;
          op.push_back({n - 2, j});
        }
        for (int d : {n - 2, n - 1}) {
          if (cnt < 3) {
            ++cnt;
            op.push_back({d, j + 1});
          }
        }
        for (int k = 0; k < 3; ++k) {
          int x = op[(int)op.size() - k - 1].first, y = op[(int)op.size() - k - 1].second;
          a[x][y] ^= 1;
        }
      }
    }
    make_zero(n - 2, m - 2);
    assert(op.size() / 3 <= n * m);
    cout << op.size() / 3 << '\n';
    for (int i = 0; i < (int)op.size(); i += 3) {
      for (int j = 0; j < 3; ++j) {
        cout << op[i + j].first + 1 << ' ' << op[i + j].second + 1 << ' ';
      }
      cout << '\n';
    }
  }
}