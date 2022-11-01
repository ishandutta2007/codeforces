// October 10, 2020
// https://codeforces.com/contest/1427/problem/C

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1427C.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1427C.cpp -ggdb && gdb a
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


  int n, m;
  cin >> n >> m;
  vector<int> x(m + 1), y(m + 1), t(m + 1);
  x[0] = y[0] = t[0] = 0;
  for (int i = 1; i <= m; i++) {
    cin >> t[i] >> x[i] >> y[i];
    --x[i]; --y[i];
  }
  vector<int> dp(m + 1, -m);
  dp[0] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = max(i - 4 * n, 0); j < i; j++) {
      if (t[j] + abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i]) {
        // cerr << "from " << j << " to " << i << '\n';
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << '\n';


  return 0;
}