// April 26, 2020
// https://codeforces.com/contest/1342/problem/A

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
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    if (x < y) {
      swap(x, y);
    }
    cout << min((x + y) * a, (x - y) * a + y * b) << '\n';
  }


  return 0;
}