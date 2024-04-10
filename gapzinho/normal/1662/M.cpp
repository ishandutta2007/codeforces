#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int n, m;
  cin >> n >> m;
  int mr = 0, mw = 0;
  for(int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    mr = max(mr, x);
    mw = max(mw, y);
  }
  if(mr + mw > n) {
    cout << "IMPOSSIBLE\n";
    return;
  }
  for(int i = 0; i < n; ++i) {
    if(i < mr) {
      cout << "R";
    } else {
      cout << "W";
    }
  }
  cout << '\n';
}

 main() {
  int t;
  cin >> t;
  while(t--) {
      solve();
  }
}