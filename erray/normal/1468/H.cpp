// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k, m;
    cin >> n >> k >> m;

    vector<bool> take(n);
    for (int i = 0; i < m; ++i) {
      int x;
      cin >> x;
      take[x - 1] = true;    
    }

    if ((n - m) % (k - 1) != 0) {
      cout << "NO\n";
      continue;
    }

    int ct = 0;
    bool ok = false;
    int tot = n - m;
    
    for (int i = 0; i < n; ++i) {
      if (!take[i]) {
        ++ct;
      } else {
        ok |= (ct >= k / 2 && (tot - ct) >= k / 2);
      }
    }

    cout << (ok ? "YES" : "NO") << '\n';
  }
}