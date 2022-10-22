#include <bits/stdc++.h>

using namespace std;
vector<int> a, pre;

vector<vector<int>> dp;

int rec(int l, int r) {
  if (l >= r)
    return 0;
  int & ret = dp[l][r];
  if (ret != -1)
    return ret;
  ret = max(rec(l+1, r), rec(l, r-1));
  int bef = pre[r];
  while (bef >= l) {
    ret = max(ret, rec(l, bef) + rec(bef+1, r-1) + 1);
    bef = pre[bef];
  }
  return ret;
}

void solve() {
  int n;
  cin >> n;
  a.resize(n);
  vector<int> last(n+1, -1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  a.erase(unique(a.begin(), a.end()), a.end());
  n = a.size();
  dp.assign(n, vector<int>(n, -1));
  pre.assign(n, -1);
  for (int i = 0; i < n; ++i) {
    pre[i] = last[a[i]];
    last[a[i]] = i;
  }
  cout << (n - 1) - rec(0, n-1) << '\n';
}

int main() {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}