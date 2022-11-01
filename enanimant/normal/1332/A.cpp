// March 29, 2020
// https://codeforces.com/contest/1332/problem/A

/*

*/


#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    int a, b, c, d, x, y, x1, y1, x2, y2;
    cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
    bool can = true;
    if (a + b > 0 && x1 == x2) {
      can = false;
    }
    if (c + d > 0 && y1 == y2) {
      can = false;
    }
    x += b - a;
    y += d - c;
    if (x < x1 || x > x2 || y < y1 || y > y2) {
      can = false;
    }
    cout << (can ? "YES" : "NO") << '\n';
  }


  return 0;
}