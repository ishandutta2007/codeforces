// August 7, 2019
// https://codeforces.com/contest/1202/problem/A

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
    string x, y;
    cin >> x >> y;
    int lx = -1, ly = -1;
    for (int i = 0; i < y.size(); i++) {
      if (y[i] == '1') {
        ly = i;
      }
    }
    ly = y.size() - 1 - ly;
    for (int i = 0; i < x.size() - ly; i++) {
      if (x[i] == '1') {
        lx = i;
      }
    }
    lx = x.size() - 1 - lx;
    cout << max(0, lx - ly) << '\n';
  }


  return 0;
}