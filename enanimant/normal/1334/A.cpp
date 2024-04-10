// April 10, 2020
// https://codeforces.com/contest/1334/problem/A

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
    int fails = 0, clears = 0;
    bool ok = true;
    while (n--) {
      int p, c;
      cin >> p >> c;
      if (c > p) {
        ok = false;
      }
      int f = p - c;
      if (f < fails || c < clears) {
        ok = false;
      }
      fails = f;
      clears = c;
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }


  return 0;
}