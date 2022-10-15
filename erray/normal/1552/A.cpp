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
    string s;
    cin >> n >> s;
    string t = s;
    sort(t.begin(), t.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += t[i] != s[i];
    }
    cout << ans << '\n';
  }
}