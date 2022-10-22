#include <bits/stdc++.h>

using namespace std;


void solve() {
  int n;
  string s, t;
  cin >> n;
  cin >> s;
  cin >> t;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      ans += 2;
      continue;
    }
    if (s[i] == '0') {
      if (i + 1 < n && s[i+1] == '1' && t[i+1] == '1') {
        ans += 2;
        ++i;
      } else {
        ans += 1;
      }
    } else {
      if (i + 1 < n && s[i+1] == '0' && t[i+1] == '0') {
        ans += 2;
        ++i;
      } else {
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    solve();
  }
  return 0;
}