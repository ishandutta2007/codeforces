// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    auto sa = a;
    sort(sa.begin(), sa.end());
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      ok &= (i - x >= 0 || i + x < n || a[i] == sa[i]); 
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}