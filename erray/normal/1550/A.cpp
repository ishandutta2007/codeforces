// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int s;
    cin >> s;
    int sum = 0;
    int cur = 1;
    int res = 0;
    while (sum + cur <= s) {
      sum += cur;
      cur += 2;
      ++res;
    }  
    cout << res + (sum != s) << '\n';
  }
}