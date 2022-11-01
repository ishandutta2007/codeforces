// June 11, 2020
// 

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
    int a, b;
    cin >> a >> b;
    if (a < b) {
      swap(a, b);
    }
    if (a > 2 * b) {
      cout << b << '\n';
      continue;
    }
    int x = a - b;
    b -= x;
    int y = b / 3;
    int ans = x + y * 2;
    if (b % 3 == 2) {
      ans += 1;
    }
    cout << ans << '\n';
  }
  
  
  return 0;
}