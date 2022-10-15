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
    int nw = max(n, k);
    cout << min(abs(n - k), max(0, k - n) + (nw % 2 != k % 2)) << '\n';
  }
}