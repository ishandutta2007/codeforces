/*
 * author:  ADMathNoob
 * created: 04/03/21 10:33:29
 * problem: https://codeforces.com/contest/1503/problem/A
 */

/*
g++ 1503A.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -Wall -Wfatal-errors -ggdb && gdb a
g++ 1503A.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ones = count(s.begin(), s.end(), '1');
    if (ones % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    vector<int> low_delta(n);
    int k0 = 0, k1 = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        if (k0 % 2 == 0) {
          low_delta[i] = -1;
        } else {
          low_delta[i] = 1;
        }
        k0 += 1;
      } else {
        if (k1 < ones / 2) {
          low_delta[i] = 1;
        } else {
          low_delta[i] = -1;
        }
        k1 += 1;
      }
    }
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + low_delta[i];
    }
    if (*min_element(pref.begin(), pref.end()) < 0) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << (low_delta[i] == 1 ? '(' : ')');
      }
      cout << '\n';
      for (int i = 0; i < n; i++) {
        int x = (s[i] == '1' ? low_delta[i] : -low_delta[i]);
        cout << (x == 1 ? '(' : ')');
      }
      cout << '\n';
    }
  }
  return 0;
}