#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, z;
  cin >> n >> z;
  vector<int> a(n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    ans = max(ans, a[i]|z);
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