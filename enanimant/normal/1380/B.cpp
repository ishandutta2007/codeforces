// July 12, 2020
// https://codeforces.com/contest/1380/problem/B

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
    string t;
    cin >> t;
    int n = (int) t.size();
    int r = 0, p = 0, s = 0;
    for (char c : t) {
      if (c == 'R') {
        r++;
      } else if (c == 'P') {
        p++;
      } else {
        s++;
      }
    }
    int mx = max({r, p, s});
    char best = (r == mx ? 'P' : p == mx ? 'S' : 'R');
    for (int i = 0; i < n; i++) {
      cout << best;
    }
    cout << '\n';
  }
  
  
  return 0;
}