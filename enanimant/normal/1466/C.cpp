// December 30, 2020
// https://codeforces.com/contest/1466/problem/C

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1466C.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1466C.cpp -ggdb && gdb a
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
    string s;
    cin >> s;
    int n = (int) s.size();
    int ans = 0;
    vector<int> CHECKS = {-2, -1};
    for (int i = 1; i < n; i++) {
      bool change = false;
      auto Check = [&](int d) {
        int j = i + d;
        if (0 <= j && j < n && s[i] == s[j]) {
          change = true;
        }
      };
      for (int d : CHECKS) {
        Check(d);
      }
      if (change) {
        s[i] = '.';
        ans += 1;
      }
    }
    cout << ans << '\n';
  }


  return 0;
}