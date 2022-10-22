#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> b(n+1);
  vector<vector<int>> ib(n+2);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    ib[b[i]].push_back(i);
  }
  vector<int> ans;
  int root = 0;
  bool low = true;
  if (ib[root].empty()) {
    root = n+1;
    low = false;
  }
  int k = 0, cnt = 0;
  // assert(ib[root].size() > 0);
  while (true) {
    int nxt = -1;
    low = !low;
    for (int x : ib[root]) {
      if (low) {
        ++cnt;
        k = max(k, x);
      }
      if (ib[x].size() > 0) {
        nxt = x;
      } else {
        ans.push_back(x);
      }
    }
    if (nxt != -1) {
      ans.push_back(nxt);
      root = nxt;
    } else {
      break;
    }
  }
  // assert(k == cnt);
  cout << k << "\n";
  for (int i = 0; i < (int)ans.size(); ++i) {
    cout << ans[i] << ((i+1 == (int)ans.size()) ? '\n' : ' ');
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