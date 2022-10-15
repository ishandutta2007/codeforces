// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<string> t1(n, string(m, '.'));
    vector<string> t2(n, string(m, '.'));
    bool ok1 = true;
    bool ok2 = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        t1[i][j] = ((i + j) % 2 ? 'R' : 'W');
        t2[i][j] = ((i + j) % 2 ? 'W' : 'R');
        if (a[i][j] == '.') {
          continue;
        }
        ok1 &= t1[i][j] == a[i][j];
        ok2 &= t2[i][j] == a[i][j];
      }
    }
    if (!ok1 && !ok2) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if (!ok1) {
      swap(t1, t2);
    }
    for (int i = 0; i < n; ++i) {
      cout << t1[i] << '\n';
    }
  }
}