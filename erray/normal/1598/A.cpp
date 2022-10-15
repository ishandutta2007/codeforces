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
    string a, b;
    cin >> a >> b;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      ok &= (a[i] != '1' || b[i] != '1');
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}