// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string ans = string(n, '(') + string(n, ')');
    for (int i = 0; i < n; ++i) {
      cout << ans << '\n';
      ans.pop_back();
      ans.insert(ans.begin() + 1 + (i * 2), ')');  
    } 
  }
}