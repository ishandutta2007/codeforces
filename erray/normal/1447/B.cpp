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
    vector<vector<int>> mat(n, vector<int>(m));
    vector<int> all;
    bool neg = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> mat[i][j];
        all.push_back(abs(mat[i][j]));
        neg ^= (mat[i][j] < 0);
      }
    }
    sort(all.begin(), all.end());
    int ans = accumulate(all.begin(), all.end(), 0);
    cout << ans - neg * (all[0] * 2) << '\n';
  }
}