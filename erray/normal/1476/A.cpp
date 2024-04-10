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
    if (n > k) {
      int add = (k - (n % k));
      k = n + (add == k ? 0 : add);
    }

    cout << k / n + !!(k % n) << '\n';
  }
}