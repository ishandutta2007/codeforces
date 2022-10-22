#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> vs(n);
  for (int i = 0; i < n; ++i)
    cin >> vs[i];
  int ans = 0;
  vector<int> weight(n);
  for (char c = 'a'; c <= 'e'; ++c) {
    for (int i = 0; i < n; ++i) {
      int score = 0;
      for (char x : vs[i]) {
        if (x == c)
          ++score;
        else
          --score;
      }
      weight[i] = score;
    }
    sort(weight.rbegin(), weight.rend());
    int cur = 0;
    int tot = 0;
    for (int i = 0; i < n; ++i) {
      if (tot + weight[i] <= 0) {
        break;
      }
      ++cur;
      tot += weight[i];
    }
    ans = max(ans, cur);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}