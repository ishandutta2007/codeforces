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
    vector <pair <int, int>> ord;
    for (int j = 0; j < m; ++j) ord.push_back({0, j});
    for (int i = 1; i < n; ++i) {
      ord.push_back({i, m - 1});
    }
    for (int j = m - 2; j >= 0; --j) {
      ord.push_back({n - 1, j});
    } 
    for (int i = n - 2; i > 0; --i) {
      ord.push_back({i, 0});
    }
    int best = 0;
    vector <vector <int>> ans(n, vector <int> (m));
    int sz = (int)ord.size();
    for (int i = 0; i < sz; ++i) {
      vector <vector <int>> cur(n, vector <int> (m));
      cur[ord[i].first][ord[i].second] = 1;
      int cnt = 1;
      for (int j = 1; j < sz; ++j) {
        bool bad = false;
        int x = ord[(i + j) % sz].first, y = ord[(i + j) % sz].second;
        for (int dx = -1; dx <= 1; ++dx) {
          for (int dy = -1; dy <= 1; ++dy) {
            if (0 <= x + dx && x + dx < n && 0 <= y + dy && y + dy < m && cur[x + dx][y + dy] == 1) {
              bad = 1;
            }
          }
        }
        if (!bad) {
          cur[x][y] = 1;
          ++cnt;
        }
      }
      if (cnt > best) {
        best = cnt;
        ans = cur;
      }
    }   
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << ans[i][j];
      }
      cout << '\n';
    }
    cout << '\n';
  }
}