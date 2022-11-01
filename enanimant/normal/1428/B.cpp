// October 16, 2020
// https://codeforces.com/contest/1428/problem/B

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1428B.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1428B.cpp -ggdb && gdb a
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
    string s;
    cin >> s;
    bool all_cw = true, all_ccw = true;
    for (int i = 0; i < n; i++) {
      all_cw &= (s[i] != '<');
      all_ccw &= (s[i] != '>');
    }
    if (all_cw || all_ccw) {
      cout << n << '\n';
      continue;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int j = (i + 1) % n;
      if (s[i] == '-' || s[j] == '-') {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }


  return 0;
}