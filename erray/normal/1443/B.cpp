// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, n;
    string s;
    cin >> a >> b >> s;
    n = (int) s.size();
    vector<int> pl;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        pl.push_back(i);
      }
    }
    int ans = 0;
    for (int i = 0; i < (int) pl.size(); ++i) {
      if (i == 0 || (b * (pl[i] - pl[i - 1] - 1)) > a) {
        ans += a;
      } else {
        ans += b * (pl[i] - pl[i - 1] - 1);
      }
    }
    cout << ans << '\n';
  }
}