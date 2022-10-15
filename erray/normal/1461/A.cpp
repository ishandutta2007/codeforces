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
    int cur = 0;
    while (n > 0) {
      cout << string(min(n, k), (cur % 3) + 'a');
      n -= min(n, k);
      ++cur;
    }
    cout << '\n';
  }
}