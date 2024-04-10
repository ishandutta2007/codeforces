#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) cin >> a[i]; 
  for (int i = 0; i < m; ++i) cin >> b[i];
  for (int cur = 0; cur < (1 << 9); ++cur) {
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      bool pos = false;
      for (int j = 0; j < m; ++j) {
        int mv = a[i] & b[j];
        pos |= (mv - (mv & cur) == 0);
      }
      ok &= pos;
    }
    if (ok) return cout << cur, 0;
  }
}