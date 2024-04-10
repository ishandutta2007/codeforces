#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> p(n), l(n), r(n);
  for (int i = 1; i < n; ++i) {
    cin >> p[i];
    --p[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
  }
  int ans = 0;
  vector<long long> sum(n); 
  for (int v = n-1; v >= 0; --v) {
    if (sum[v] < l[v]) {
      sum[v] = r[v];
      ++ans;
    }
    if (sum[v] > r[v])
      sum[v] = r[v];
    if (v)
      sum[p[v]] += sum[v];
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