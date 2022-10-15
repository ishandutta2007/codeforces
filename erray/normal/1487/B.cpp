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
    --k;
    int cur = k % n;
    if (n % 2 != 0) {
      cur = (cur + (k / (n / 2))) % n;
    }

    cout << 1 + cur << '\n';
  } 
}