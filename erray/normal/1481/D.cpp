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
    vector<string> mat(n);
    for (int i = 0; i < n; ++i) {
      cin >> mat[i];
    }

    int a = -1, b = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (mat[i][j] == mat[j][i]) {
          a = i, b = j;
        }
      }
    }

    if (a != -1) {
      cout << "YES\n";
      for (int i = 0; i < m + 1; ++i) {
        cout << (i % 2 ? a : b) + 1 << ' ';
      } 
      cout << '\n';
      continue;
    }

    if (m % 2 == 1) {
      cout << "YES\n";
      for (int i = 0; i < m + 1; ++i) {
        cout << 1 + (i % 2) << ' ';
      }

      cout << '\n';
      continue;
    }

    if (n == 2) {
      cout << "NO\n";
      continue;
    }

    vector<int> ans(4, -1);
    for (int i = 0; i < n; ++i) {
      vector<vector<int>> ct(256);
      for (int j = 0; j < n; ++j) {
        ct[mat[i][j]].push_back(j); 
      }
      if (ct['a'].empty() || ct['b'].empty()) {
        continue;
      }

      ans[1] = ans[3] = i;
      ans[0] = ct['a'].back();
      ans[2] = ct['b'].back();
    }

    assert(ans[0] != -1);

    cout << "YES\n";
    for (int i = 0; i < m + 1; ++i) {
      cout << ans[(i + (m % 4 == 0)) % 4] + 1 << ' '; 
    }

    cout << '\n';
  }
}