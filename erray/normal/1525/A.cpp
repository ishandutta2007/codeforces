// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int k;
    cin >> k;
    int ot = 100 - k;
    int g = gcd(ot, k);
    cout << ot / g + k / g << '\n';
  } 
}