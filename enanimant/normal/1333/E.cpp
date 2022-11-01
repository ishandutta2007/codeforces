// April 8, 2020
// https://codeforces.com/contest/1333/problem/E

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


  int n;
  cin >> n;
  if (n <= 2) {
    cout << "-1\n";
    return 0;
  }
  const vector<vector<int>> THREE = {
    {4, 3, 1},
    {7, 2, 9},
    {8, 5, 6}
  };
  vector<vector<int>> a(n, vector<int>(n, -1));
  int r, c, dr, dc;
  if (n % 2 == 0) {
    r = n - 1;
    c = 0;
    dr = 0;
    dc = 1;
  } else {
    r = 0;
    c = n - 1;
    dr = 1;
    dc = 0;
  }
  int x = 1;
  if (n > 3) {
    a[r][c] = x++;
    r += dr;
    c += dc;
    while (true) {
      a[r][c] = x++;
      if (r == 0) {
        c--;
        if (c == 2) {
          break;
        }
        a[r][c] = x++;
        dr = 1;
        dc = 0;
      } else if (c == 0) {
        r--;
        a[r][c] = x++;
        dr = 0;
        dc = 1;
      }
      r += dr;
      c += dc;
      if (r >= n || c >= n || a[r][c] != -1) {
        r -= dr;
        c -= dc;
        swap(dr, dc);
        dr = -dr;
        dc = -dc;
        r += dr;
        c += dc;
      }
    }
  }
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a[i][j] = THREE[i][j] + x - 1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j > 0) {
        cout << ' ';
      }
      cout << a[i][j];
    }
    cout << '\n';
  }


  return 0;
}