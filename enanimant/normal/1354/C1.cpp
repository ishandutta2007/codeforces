// May 17, 2020
// https://codeforces.com/contest/1354/problem/C1

/*

*/


#include <bits/stdc++.h>

using namespace std;


const double PI = 4 * atan(1.0);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif
  
  
  cout.precision(10);
  cout << fixed;
  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    n *= 2;
    cout << 1 / tan(PI / n) << '\n';
  }
  
  
  return 0;
}