// author: erray
#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
      cin >> grid[i];
    }
    for (char c = '0'; c < '2'; ++c) {
      vector<pair<int, int>> res;
      if (grid[0][1] != c) {
        res.emplace_back(0, 1);
      }
      if (grid[1][0] != c) {
        res.emplace_back(1, 0);
      }
      if (grid[n - 1][n - 2] == c) {
        res.emplace_back(n - 1, n - 2);
      }
      if (grid[n - 2][n - 1] == c) {
        res.emplace_back(n - 2, n - 1);
      }
      if ((int) res.size() < 3) {
        cout << (int) res.size() << '\n'; 
        for (auto[x, y] : res) {
          cout << x + 1 << ' ' << y + 1 << '\n';
        }
        break;
      }
    }
  }
}