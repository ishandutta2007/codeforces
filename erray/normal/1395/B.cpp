#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  cout << x << ' ' << y << '\n';
  cout << 1 << ' ' << y << '\n';
  cout << 1 << ' ' << 1 << '\n';
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      for (int j = m - 1; j >= 0; --j) {
        if (i == x - 1 && j == y - 1) continue;
        cout << i + 1 << ' ' << j + 1 << '\n';
      }
    } else {
      for (int j = 0; j < m; ++j) {
        if (i == x - 1 && j == y - 1) continue;      
        if (i == 0 && (j == 0 || j == y - 1)) continue;
        cout << i + 1 << ' ' << j + 1 << '\n';
      }
    }
  }
}