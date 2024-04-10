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
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<vector<int>> pref(n, vector<int>(m + 1));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        pref[i][j + 1] = pref[i][j] + (a[i][j] == '*');
      }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int l = 0; l < n - i; ++l) {
          if (j - l < 0 || j + l >= m || pref[i + l][j + l + 1] - pref[i + l][j - l] != l * 2 + 1) {
            break;
          }        
          ++ans;
        }
      }
    }

    cout << ans << '\n';
  }
}