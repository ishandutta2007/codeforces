// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      int q = int(sqrt(a[i]));
      ok &= (q * q == a[i]);
    }
    cout << (!ok ? "YES" : "NO") << '\n';
  }
}