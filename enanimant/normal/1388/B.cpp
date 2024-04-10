// July 31, 2020
// https://codeforces.com/contest/1388/problem/B

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
    int n;
    cin >> n;
    int eights = (n + 3) / 4;
    for (int i = 0; i < n; i++) {
      if (i < n - eights) {
        cout << "9";
      } else {
        cout << "8";
      }
    }
    cout << '\n';
  }
  
  
  return 0;
}