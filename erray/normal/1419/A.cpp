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
    string s;
    cin >> n >> s;
    vector<int> ct(2);
    bool cur = n & 1 ^ 1;
    for (int i = 0; i < n; ++i) {
      if (i % 2 != cur) continue;
      ct[(s[i] - '0') % 2]++;    
    }
    int ans = (cur ? 2 : 1);
    if (ct[cur ^ 1] == 0) ans = (ans == 1 ? 2 : 1);
    cout << ans << '\n';
  }
}