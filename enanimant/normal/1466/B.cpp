// December 30, 2020
// https://codeforces.com/contest/1466/problem/B

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1466B.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1466B.cpp -ggdb && gdb a
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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (i == n - 1 || a[i + 1] > a[i] + 1) {
        a[i] += 1;
      }
      if (i == n - 1 || a[i] != a[i + 1]) {
        ans += 1;
      }
    }
    cout << ans << '\n';
  }


  return 0;
}