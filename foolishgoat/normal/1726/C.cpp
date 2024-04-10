#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  string s;
  cin >> n >> s;
  int ans = n;
  for (int i = 0; i + 1 < 2 * n; ++i) {
    ans -= (s[i] == ')' && s[i+1] == '(');
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}