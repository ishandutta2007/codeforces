// July 11, 2020
// https://codeforces.com/contest/1372/problem/A

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
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << 1;
    }
    cout << '\n';
  }
  
  
  return 0;
}