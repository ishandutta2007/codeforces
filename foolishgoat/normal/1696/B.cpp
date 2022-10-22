#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int ans = 0;
  int last = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (last == 0 && a[i] > 0) {
      ++ans;
    }
    last = a[i];
  }
  ans = min(ans, 2);
  cout << ans << endl;
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