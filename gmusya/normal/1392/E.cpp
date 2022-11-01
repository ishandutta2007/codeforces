#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  int n;
  cin >> n;
  vector <vector <ll>> a(n, vector <ll>(n));
  for (int i = 1; i < n; i += 2)
    for (int j = 0; j < n; j++)
      a[i][j] = (1ll << (i + j));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << a[i][j] << ' ';
    cout << endl;
  }
  int q;
  cin >> q;
  while (q--) {
    ll k;
    cin >> k;
    int x = n - 1, y = n - 1;
    vector <pair <int, int>> ans;
    while (x > 0 && y > 0) {
      ans.push_back({x, y});
      if (a[x][y] == 0) {
        if (k & a[x - 1][y])
          x--;
        else
          y--;
      } else {
        if (k & a[x][y - 1])
          y--;
        else
          x--;
      }
    }
    while (x > 0) {
      ans.push_back({x, y});
      x--;
    }
    while (y > 0) {
      ans.push_back({x, y});
      y--;
    }
    ans.push_back({0, 0});
    reverse(ans.begin(), ans.end());
    for (auto &now : ans)
      cout << now.first + 1 << ' ' << now.second + 1 << endl;
  }
  return 0;
}