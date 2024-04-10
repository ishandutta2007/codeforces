#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int a[211][211], sol[211][211], n, m;

bool ok(int r, int c) {
  for (int dr = -1; dr <= +1; dr++) {
    for (int dc = -1; dc <= +1; dc++) {
      if (1 <= r + dr && r + dr <= n && 1 <= c + dc && c + dc <= m && a[r + dr][c + dc] == 1) {
        return 0;
      }
    }
  }
  return 1;
}

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int cntsol = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        a[i][j] = 0;
        sol[i][j] = 0;
      }
    }
    vector<pair<int, int>> ord;
    for (int j = 2; j <= m; j++) {
      ord.push_back({1, j});
    }
    for (int i = 2; i <= n; i++) {
      ord.push_back({i, m});
    }
    for (int j = m - 1; j >= 1; j--) {
      ord.push_back({n, j});
    }
    for (int i = n - 1; i >= 1; i--) {
      ord.push_back({i, 1});
    }
    for (int go = 0; go < (int) ord.size(); go++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          a[i][j] = 0;
        }
      }
      int cnt = 0;
      for (int i = 0; i < (int) ord.size(); i++) {
        auto it = ord[(go + i) % (int) ord.size()];
        if (ok(it.first, it.second)) {
          cnt++;
          a[it.first][it.second] = 1;
        }
      }
      if (cnt > cntsol) {
        cntsol = cnt;
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) {
            sol[i][j] = a[i][j];
          }
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << sol[i][j];
      }
      cout << "\n";
    }
    cout << "\n";
  }
}


/**

**/