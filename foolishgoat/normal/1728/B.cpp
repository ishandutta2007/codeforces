#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> ans(n);
  ans[n-2] = n-1;
  ans[n-1] = n;
  if (n & 1) {
    ans[0] = 1;
    for (int i = 0; i < n-3; ++i) {
      ans[i+1] = n-2 - i;
    }
  } else {
    for (int i = 0; i < n-2; ++i) {
      ans[i] = n-2 - i;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << (i+1 == n ? '\n' : ' ');
  }
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