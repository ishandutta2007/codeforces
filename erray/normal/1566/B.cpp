// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    int ans = s[0] == '0';
    for (int i = 1; i < int(s.size()); ++i) {
      ans += (s[i] == '0' && s[i - 1] == '1');
    }
    cout << min(2, ans) << '\n';
  }
}