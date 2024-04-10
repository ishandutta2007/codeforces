// June 11, 2020
// https://codeforces.com/contest/1366/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
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
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> cnt(n + m - 2, 0);
    vector<int> sum(n + m - 2, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        int s = i + j;
        if (s * 2 >= n + m - 2) {
          s = n + m - 2 - s;
        }
        cnt[s] += 1;
        sum[s] += a[i][j];
      }
    }
    int ans = 0;
    for (int s = 0; s * 2 < n + m - 2; s++) {
      ans += min(sum[s], cnt[s] - sum[s]);
    }
    cout << ans << '\n';
  }
  
  
  return 0;
}