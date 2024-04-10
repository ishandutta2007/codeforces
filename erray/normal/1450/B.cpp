// author: erray
#include<bits/stdc++.h>
 
using namespace std;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
      cin >> l[i] >> r[i];
    }
    bool ok = false;
    for (int i = 0; i < n; ++i) {
      bool tmp = true;
      for (int j = 0; j < n; ++j) {
        tmp &= (abs(l[i] - l[j]) + abs(r[i] - r[j]) <= k);
      }
      ok |= tmp;
    }
    cout << (ok ? 1 : -1) << '\n';
  }
}