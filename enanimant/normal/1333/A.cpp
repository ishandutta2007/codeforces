// April 8, 2020
// https://codeforces.com/contest/1333/problem/A

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
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (m % 2 == 0 && i == 0 && j == m - 1) {
          cout << 'B';
          continue;
        }
        if (m % 2 == 1 && n % 2 == 0 && i == n - 1 && j == 0) {
          cout << 'B';
          continue;
        }
        cout << ((i + j) % 2 == 0 ? 'B' : 'W');
      }
      cout << '\n';
    }
  }


  return 0;
}