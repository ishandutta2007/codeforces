// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      swap(x1, y1);
      swap(x2, y2);
    }
    cout << abs(x2 - x1) + (y1 == y2 ? 0 : 2) + abs(y2 - y1) << '\n';
  }
}