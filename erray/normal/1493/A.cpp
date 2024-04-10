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
    cout << n - k + (k / 2) << '\n';
    for (int i = (k + 1) / 2; i <= n; ++i) {
      if (i != k) {
        cout << i << ' ';
      }
    }
    cout << '\n';
  }
}