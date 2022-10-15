// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    long long cur = 1;
    int ans = 0;
    for (long long i = 2; cur <= n; i *= 2) {
      ++ans;
      n -= cur;
      cur *= 2;
      cur += i * i;
    }       
    cout << ans << '\n';
  }
}