// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    vector<int> ct(n);
    vector<int> one(n);
    for (int i = 0; i < m; ++i) {
      int k;
      cin >> k;
      a[i].resize(k);
      for (int j = 0; j < k; ++j) {
        cin >> a[i][j];
        --a[i][j];
        ++ct[a[i][j]];
      }
      if (k == 1) {
        ++one[a[i][0]];
      }
    }
    
    int need = (m + 1) / 2;
    int big = -1;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      if (ct[i] >= need) {
        big = i;
        if (one[i] > need) {
          ok = false;
        }
      }
    }
    if (!ok) {
      cout << "NO\n";
      continue;
    }
    vector<int> use(n);
    vector<int> ans(m, -1);
    for (int i = 0; i < m; ++i) {
      if ((int) a[i].size() == 1) {
        ans[i] = a[i][0];
        ++use[a[i][0]];
      }
    }

    for (int i = 0; i < m; ++i) {
      if (ans[i] != -1) {
        continue;
      }
      bool found = false;
      int ot = -1;
      for (auto e : a[i]) {
        found |= (e == big); 
        if (e != big) {
          ot = e;
        }
      }
      int res = ot; 
      if (found && use[big] < need) {
        res = big;
      }
      ans[i] = res;
      ++use[res];
    }
    cout << "YES\n";
    for (auto e : ans) {
      cout << e + 1 << ' ';
    }
    cout << '\n';
  }
}