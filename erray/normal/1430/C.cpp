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
    if (n == 2) {
      cout << 2 << '\n';
      cout << "1 2\n";
      continue;
    }
    cout << 2 << '\n';
    for (int i = n; i >= 3;  --i) {
      cout << i << ' ' << i - 2 << '\n';
      if (i == n) cout << i - 1 << ' ' << i - 1 << '\n';
    }
  }
}