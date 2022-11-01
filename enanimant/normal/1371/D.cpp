// July 1, 2020
// https://codeforces.com/contest/1371/problem/D

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
    int n, k;
    cin >> n >> k;
    int f = (k % n == 0 ? 0 : 2);
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int d = 0; d < n; d++) {
      for (int i = 0; i < n; i++) {
        if (k == 0) {
          break;
        }
        k--;
        a[i][(i + d) % n] = 1;
      }
      if (k == 0) {
        break;
      }
    }
    cout << f << '\n';
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << a[i][j];
      }
      cout << '\n';
    }
  }
  
  
  return 0;
}