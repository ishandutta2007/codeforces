/*
 * author:  ADMathNoob
 * created: 02/28/21 19:23:23
 * problem: https://codeforces.com/contest/1491/problem/C
 */

/*
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1491C_linear.cpp && a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors 1491C_linear.cpp -ggdb && gdb a
g++ -D _DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors 1491C_linear.cpp && a


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
    vector<int> add(n + 1, 0);
    auto Do = [&](int ll, int rr, int v) {
      // cerr << "Do " << ll << ' ' << rr << ' ' << v << '\n';
      if (ll < n) {
        add[ll] += v;
      }
      if (rr + 1 < n) {
        add[rr + 1] -= v;
      }
    };
    long long ans = 0;
    int cnt = 0;
    int to_add = 0;
    for (int i = 0; i < n; i++) {
      // cerr << "at " << i << '\n';
      to_add += add[i];
      cnt += to_add;
      int s;
      cin >> s;
      int x = min(s - 1, cnt);
      Do(i + s - x + 1, i + s, 1);
      cnt -= x;
      s -= x;
      if (s > 1) {
        assert(cnt == 0);
        int ll = i + 2;
        int rr = i + s;
        Do(ll, rr, 1);
        ans += s - 1;
        // cerr << "add " << s - 1 << '\n';
      }
    }
    cout << ans << '\n';
  }

  return 0;
}