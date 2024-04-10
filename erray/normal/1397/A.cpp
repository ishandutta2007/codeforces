// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector<int> ct(256);
    for (int i = 0; i < n; ++i) {
      for (auto c : a[i]) {
        ct[c]++;
      }
    }
    bool ok = true;
    for (int i = 0; i < 256; ++i) {
      ok &= (ct[i] % n == 0);
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}