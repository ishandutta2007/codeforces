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
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == n - 1 && j == 0) {
          cout << 1 << ' ';
        } else {
          cout << (i == j || j - 1 == i ? 1 : 0) << ' ';
        }
      }
      cout << '\n';
    } 
  }
}