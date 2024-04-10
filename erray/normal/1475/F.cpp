// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < n; ++j) {
        a[i][j] = (s[j] == '1');
      }
    }
    
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      for (int j = 0; j < n; ++j) {
        a[i][j] ^= (s[j] == '1');
      }
    }

    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (a[i][0] != a[0][0]) {
        for (int j = 0; j < n; ++j) {
          a[i][j] ^= 1;
        }
      }

      ok &= (a[i] == a[0]);
    }

    cout << (ok ? "YES" : "NO") << '\n';
  }
}