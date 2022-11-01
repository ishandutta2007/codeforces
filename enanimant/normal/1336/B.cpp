// April 15, 2020
//

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
    vector<int> n(3);
    vector<vector<int>> a(3);
    for (int i = 0; i < 3; i++) {
      cin >> n[i];
    }
    for (int i = 0; i < 3; i++) {
      a[i].resize(n[i]);
      for (int j = 0; j < n[i]; j++) {
        cin >> a[i][j];
      }
      sort(a[i].begin(), a[i].end());
    }
    long long ans = 9e18;
    for (int mid = 0; mid < 3; mid++) {
      for (int lo = 0; lo < 3; lo++) {
        if (lo == mid) {
          continue;
        }
        int hi = 3 - lo - mid;
        for (int i = 0; i < n[mid]; i++) {
          int y = a[mid][i];
          auto it = upper_bound(a[lo].begin(), a[lo].end(), y);
          if (it == a[lo].begin()) {
            continue;
          }
          it--;
          int x = *it;
          it = lower_bound(a[hi].begin(), a[hi].end(), y);
          if (it == a[hi].end()) {
            continue;
          }
          int z = *it;
          long long dx = x - y;
          long long dy = y - z;
          long long dz = z - x;
          ans = min(ans, dx * dx + dy * dy + dz * dz);
        }
      }
    }
    cout << ans << '\n';
  }


  return 0;
}