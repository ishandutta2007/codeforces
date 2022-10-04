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
  int n, m;
  cin >> n >> m;
  vector <vector <char>> a(n, vector <char> (m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }
  vector <vector <int>> vis(n, vector <int> (m, -1));
  int cur = -1;
  function <void(int, int)> dfs = [&] (int i, int j) {
    vis[i][j] = cur;
    if (a[i][j] == '.') {
      if (i + 1 < n && vis[i + 1][j] == -1) {
        dfs(i + 1, j);
      }
      if (j + 1 < m && vis[i][j + 1] == -1) {
        dfs(i, j + 1);
      }
    }
  };
  cur = 0;

  for (int j = 0; j < m; ++j) {
    if (vis[0][j] == -1) {
      dfs(0, j);
    }
  }

  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      cur = j;
      if (vis[i][j] == -1) dfs(i, j);
    }
  }
  vector <int> need(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      need[j] = max(need[j], vis[i][j]);
    }
  }
  for (int j = 1; j < m; ++j) {
    need[j] = max(need[j], need[j - 1]);
  }

  int q;
  cin >> q;
  while (q--) {
    int x1, x2;
    cin >> x1 >> x2;
    --x1, --x2;
    if (need[x2] <= x1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}