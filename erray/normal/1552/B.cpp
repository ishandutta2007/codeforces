// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;

    vector<array<int, 5>> a(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 5; ++j) {
        cin >> a[i][j];
      }
    }
    int cur = 0;
    for (int i = 1; i < n; ++i) {
      int ct = 0;
      for (int j = 0; j < 5; ++j) {
        ct += (a[cur][j] < a[i][j]);
      }
      if (ct < 3) {
        cur = i;
      }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      int ct = 0;
      for (int j = 0; j < 5; ++j) {
        ct += (a[cur][j] <= a[i][j]);
      }
      ok &= (ct >= 3);
    }
    cout << (!ok ? -1 : cur + 1) << '\n';
  }
}