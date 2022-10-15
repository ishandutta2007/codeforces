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
    if (n % 3 == 0) {
      cout << n / 3 << ' ' << 0 << ' ' << 0;
    } else if (n % 3 == 2) {
      if (n < 5) {
        cout << -1;
      } else {
        cout << (n - 5) / 3 << ' ' << 1 << ' ' << 0; 
      }     
    } else {
      if (n < 7) {
        cout << -1;
      } else {
        cout << (n - 7) / 3 << ' ' << 0 << ' ' << 1; 
      }     
    }
    cout << '\n';
  }
}