// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int j = 0; j < 2; ++j) {
      for (int i = 0; i < n; ++i) {
        cin >> a[j][i];
      }
    }
    vector<vector<int>> sum(2, vector<int>(n + 1));
    for (int i = 0; i < n; ++i) {
      sum[1][i + 1] = sum[1][i] + a[1][i];
    }
    for (int i = n - 1; i >= 0; --i) {
      sum[0][i] = sum[0][i + 1] + a[0][i];
    }
    int ans = int(1e9);
    for (int i = 0; i < n; ++i) {
      ans = min(ans, max(sum[0][i + 1], sum[1][i]));
    }
    cout << ans << '\n';
  }
}