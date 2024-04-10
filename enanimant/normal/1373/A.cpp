// June 25, 2020
// https://codeforces.com/contest/1373/problem/A

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
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a < c ? 1 : -1) << ' ';
    cout << (c < (long long) a * b ? b : -1) << '\n';
  }
  
  
  return 0;
}