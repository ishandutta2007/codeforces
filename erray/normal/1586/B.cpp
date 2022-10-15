// author: erray
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<bool> can(n, true);
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      can[b - 1] = false;
    }

    int p = 0;
    while (!can[p]) {
      ++p;
    }

    for (int i = 0; i < n; ++i) {
      if (i != p) {
        cout << i + 1 << ' ' << p + 1 << '\n';
      }
    }
  }
}