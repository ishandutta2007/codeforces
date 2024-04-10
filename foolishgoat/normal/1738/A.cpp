#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> b(2);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    b[a[i]].push_back(x);
  }
  long long ans = 0;
  for (int i = 0; i < 2; ++i) {
    sort(b[i].begin(), b[i].end());
    reverse(b[i].begin(), b[i].end());
  }
  for (int k = 0; k < 2; ++k) {
    if (!b[0].empty()) {
      long long cur = 0;
      int u = b[0].size(), v = b[1].size();
      int p = min(u-1, v), q = min(u, v);
      for (int i = 0; i < u; ++i) {
        cur += b[0][i] * (1 + (i < p));
      }
      for (int i = 0; i < v; ++i) {
        cur += b[1][i] * (1 + (i < q));
      }
      ans = max(ans, cur);
    }
    b[0].swap(b[1]);
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