// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  vector<vector<int>> ans(n, vector<int>(n, -1));
  for (int i = 0; i < n; ++i) {
    ans[i][i] = p[i];
  }
  vector<int> left(n);
  iota(left.begin(), left.end(), 1);

  function<void(int, int, int)> Dfs = [&](int x, int y, int c) {
    if (left[c] == 0) {
      return;
    }  
    --left[c];
    ans[x][y] = c;
    if (x < n - 1 && ans[x + 1][y] == -1) {
      Dfs(x + 1, y, c); 
    } else if (y > 0 && ans[x][y - 1] == -1) {
      Dfs(x, y - 1, c); 
    }
  };
  for (int i = n - 1; i >= 0; --i) {
    Dfs(i, i, p[i]);
  }
  if (accumulate(left.begin(), left.end(), 0LL) != 0) {
    cout << -1 << '\n';
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j) {
        cout << ans[i][j] + 1 << ' ';
      }
      cout << '\n';
    }
  }
}