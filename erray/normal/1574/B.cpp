// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    array<int, 3> a;
    int m;
    cin >> a[0] >> a[1] >> a[2] >> m;
    sort(a.begin(), a.end());
    int r = a[0] + a[1] + a[2] - 3;
    int l = max(a[2] - 1 - a[1] - a[0], 0);
    cout << (l <= m && m <= r ? "YES" : "NO") << '\n';
  }
}