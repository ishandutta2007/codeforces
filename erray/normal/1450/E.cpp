// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<long long>> mat(n, vector<long long>(n, 2 * n));
  while (m--) {
    int x, y, w;
    cin >> x >> y >> w;
    --x, --y;
    mat[x][y] = 1;
    mat[y][x] = (w ? -1 : 1);
  }
  bool ok = true;
  vector<int> sp(n);
  vector<bool> vis(n);

  function<void(int)> dfs = [&](int v) {
    vis[v] = true;
    for (int i = 0; i < n; ++i) {
      if (mat[v][i] == 2 * n) {
        continue;
      }
      if (vis[i]) {
        ok &= (sp[v] != sp[i]);
        continue;
      }

      sp[i] = sp[v] ^ 1;
      dfs(i);
    }
  };

  dfs(0);  
  
  for (int q = 0; q < n; ++q) {
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < n; ++i) {
        mat[i][j] = min(mat[i][j], mat[i][q] + mat[q][j]);
        if (mat[i][j] < (int) -1e9) {
          return cout << "NO\n", 0;
        }
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int q = 0; q < n; ++q) {
        ok &= (mat[i][j] <= mat[i][q] + mat[q][j]); 
      }
    }
  }

  int v = 0;
  long long mx = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        continue;
      }

      if (mat[i][j] > mx) {
        mx = mat[i][j];
        v = i;  
      }
    }  
  }

  if (!ok) {
    return cout << "NO\n", 0;
  }
  
  cout << "YES\n";
  cout << mx << '\n';
  for (int i = 0; i < n; ++i) {
    cout << mat[v][i] * (i != v) << ' ';
  }
  cout << '\n';
}