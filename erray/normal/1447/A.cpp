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
    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
      cout << i + 1 << ' ';
    }
    cout << '\n';
  }
}