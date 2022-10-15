// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> x >> y;
    if (x < y) {
      swap(x, y);
    }
    cout << x + y + max(0, min(x - y, x - 1 - y)) << '\n';
  }
}