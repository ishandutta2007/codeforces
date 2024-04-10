// October 16, 2020
// https://codeforces.com/contest/1428/problem/C

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1428C.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1428C.cpp -ggdb && gdb a
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
    vector<int> stk;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == 'B') {
        stk.push_back(i);
      } else {
        if (!stk.empty()) {
          stk.pop_back();
        } else {
          ans += 1;
        }
      }
    }
    ans += (int) stk.size() % 2;
    cout << ans << '\n';
  }


  return 0;
}