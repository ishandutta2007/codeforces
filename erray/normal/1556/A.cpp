// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int c, d;
    cin >> c >> d;
    if (c > d) {
      swap(c, d);
    }
    if ((c ^ d) & 1) {
      cout << -1 << '\n';
    } else {
      cout << (d > 0) + (c != d) << '\n';
    }
  }
}