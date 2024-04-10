// September 14, 2019
//

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cols(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> cols[j][i];
      }
    }
    sort(cols.begin(), cols.end(), [](const vector<int> &a, const vector<int> &b) {
      int ma = 0;
      for (int i : a) {
        ma = max(ma, i);
      }
      int mb = 0;
      for (int i : b) {
        mb = max(mb, i);
      }
      return ma > mb;
    });
    cols.resize(n, vector<int>(n, 0));
    vector<int> v(n);
    int ans = 0;
    function<void(int)> solve = [&](int k) {
      if (k == n) {
        int res = 0;
        for (int i = 0; i < n; i++) {
          int mx = 0;
          for (int j = 0; j < n; j++) {
            mx = max(mx, cols[j][(i - v[j] + n) % n]);
          }
          res += mx;
        }
        ans = max(ans, res);
        return;
      }
      for (int i = 0; i < n; i++) {
        v[k] = i;
        solve(k + 1);
      }
    };
    solve(0);
    cout << ans << '\n';
  }


  return 0;
}