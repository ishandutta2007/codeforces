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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int l = a[0], r = a[0];
    bool ok = true;
    for (int i = 1; i < n; ++i) {
      l = max(a[i], l - k + 1);
      r = min(a[i] + k - 1, r + k - 1);
      ok &= (l <= r); 
    }
    cout << (ok && a.back() >= l && a.back() <= r ? "YES" : "NO") << '\n';
  }
}