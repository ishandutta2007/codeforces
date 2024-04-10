// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int x, y, k;
    cin >> x >> y >> k;
    long long need = 1LL * k * y;
    need += k - 1;  
    --x;
    cout << need / x + bool(need % x) + k << '\n'; 
  }
}