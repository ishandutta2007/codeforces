/*
 * author:  ADMathNoob
 * created: 03/17/21 15:20:30
 * problem: https://codeforces.com/contest/1497/problem/C2
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1497C2.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1497C2.cpp -ggdb && gdb a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors 1497C2.cpp && a


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
    int n, k;
    cin >> n >> k;
    vector<int> ans(k - 3, 1);
    n -= (k - 3);
    vector<int> add;
    if (n % 2 == 1) {
      add = {1, n / 2, n / 2};
    } else if (n % 4 == 2) {
      add = {2, n / 2 - 1, n / 2 - 1};
    } else {
      add = {n / 4, n / 4, n / 2};
    }
    for (int x : add) {
      ans.push_back(x);
    }
    for (int i = 0; i < k; i++) {
      if (i > 0) {
        cout << ' ';
      }
      cout << ans[i];
    }
    cout << '\n';
  }

  return 0;
}