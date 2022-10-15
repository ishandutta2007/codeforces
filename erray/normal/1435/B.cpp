// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> col(n * m + 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int x;
        cin >> x;
        col[x] = j;
      }
    }
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int x;
        cin >> x;
        ans[j][col[x]] = x;
      }
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cout << ans[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}