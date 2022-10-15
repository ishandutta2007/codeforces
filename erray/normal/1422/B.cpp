// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        cin >> a[i][j];
      }
    }
    long long ans = 0;
    for (int i = 0; i < (n + 1) / 2; ++i) {
      for (int j = 0; j < (m + 1) / 2; ++j) {
        vector<pair<int, int>> sym;
        int ni = n - i - 1;
        int nj = m - j - 1;
        auto Add = [&](int x, int y) {
          if (count(sym.begin(), sym.end(), make_pair(x, y))) return;
          sym.emplace_back(x, y);
        };
        Add(i, j);
        Add(i, nj);
        Add(ni, j);
        Add(ni, nj);
        auto check = [&](int t) {
          long long res = 0;
          for (auto[x, y] : sym) {
            res += abs(a[x][y] - t);
          }
          return res;
        };
        int low = 0, high = (int) 1e9;
        while (low < high) {
          int mid = (low + high) >> 1;
          if (check(mid) < check(mid + 1)) {
            high = mid;
          } else {
            low = mid + 1;
          }
        }
        ans += check(low);
      }
    }
    cout << ans << '\n';
  }
}