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
    double n;
    cin >> n;
    double y = 0.5 / sin(PI / (2 * n));
    double a = y * sqrt(1 - cos((n - 1) / (2 * n) * PI));
    double b = y * sqrt(1 - cos((n + 1) / (2 * n) * PI));
    cout << a + b << '\n';
  }
  
  
  return 0;
}