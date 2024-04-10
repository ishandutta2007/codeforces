// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    } 
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    } 
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      ok &= (a[i] + b[i] <= x);
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
}