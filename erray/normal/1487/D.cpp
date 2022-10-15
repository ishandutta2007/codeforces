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
    long long start = 5;
    int cur = 8;
    int ans = 0;
    while (start <= n) {
      start += cur;
      cur += 4;
      ++ans;
    }

    cout << ans << '\n';
  }
}