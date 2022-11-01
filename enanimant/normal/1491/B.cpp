/*
 * author:  ADMathNoob
 * created: 02/28/21 08:33:49
 * problem: https://codeforces.com/contest/1491/problem/B
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1491B.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1491B.cpp -ggdb && gdb a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors 1491B.cpp && a


*/

#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long) 1e18;

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
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool free = false;
    for (int i = 0; i < n - 1; i++) {
      if (abs(a[i] - a[i + 1]) >= 2) {
        free = true;
      }
    }
    if (free) {
      cout << "0\n";
      continue;
    }
    bool all_equal = true;
    for (int i = 1; i < n; i++) {
      if (a[i] != a[0]) {
        all_equal = false;
      }
    }
    int ans;
    if (all_equal) {
      ans = v + min(u, v);
    } else {
      ans = min(u, v);
    }
    cout << ans << '\n';
  }

  return 0;
}