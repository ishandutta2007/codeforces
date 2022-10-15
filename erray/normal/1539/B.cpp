// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  string s;
  cin >> n >> q >> s;
  array<vector<int>, 26> ct;
  for (int j = 0; j < 26; ++j) {
    ct[j].resize(n + 1);
    for (int i = 0; i < n; ++i) {
      ct[j][i + 1] = ct[j][i] + ((s[i] - 'a') == j);
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int j = 0; j < 26; ++j) {
      ans += (j + 1) * (ct[j][r] - ct[j][l - 1]);
    }
    cout << ans << '\n';
  }
}