// September 27, 2020
// https://codeforces.com/contest/1416/problem/A

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1416A.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1416A.cpp -ggdb && gdb a
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
    vector<int> a(n);
    vector<vector<int>> pos(n, vector<int>(1, -1));
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i]--;
      pos[a[i]].push_back(i);
    }
    for (int i = 0; i < n; i++) {
      pos[i].push_back(n);
    }
    vector<int> ans(n + 2, n);
    for (int i = 0; i < n; i++) {
      int mx = -1;
      for (int j = 0; j < (int) pos[i].size() - 1; j++) {
        mx = max(mx, pos[i][j + 1] - pos[i][j]);
      }
      ans[mx] = min(ans[mx], i);
    }
    for (int i = 1; i <= n; i++) {
      if (i > 1) {
        cout << ' ';
      }
      cout << (ans[i] != n ? ans[i] + 1 : -1);
      ans[i + 1] = min(ans[i + 1], ans[i]);
    }
    cout << '\n';
  }


  return 0;
}