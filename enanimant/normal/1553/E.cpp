/*
 * author:  ADMathNoob
 * created: 07/22/21 10:35:08
 * problem: https://codeforces.com/contest/1553/problem/E
 */

/*
g++ 1553E.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1553E.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    vector<int> shift(n);
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      --p[i];
      shift[i] = (i - p[i] + n) % n;
      ++cnt[shift[i]];
    }
    vector<int> ret;
    for (int k = 0; k < n; k++) {
      if (cnt[k] >= n - 2 * m) {
        for (int i = 0; i < n; i++) {
          p[i] = (p[i] + k) % n;
        }
        int need = 0;
        vector<bool> was(n, false);
        for (int start = 0; start < n; start++) {
          if (was[start]) {
            continue;
          }
          int v = start;
          int len = 0;
          do {
            was[v] = true;
            v = p[v];
            ++len;
          } while (v != start);
          need += len - 1;
        }
        if (need <= m) {
          ret.push_back(k);
        }
        for (int i = 0; i < n; i++) {
          p[i] = (p[i] - k + n) % n;
        }
      }
    }
    cout << ret.size();
    for (int k : ret) {
      cout << ' ' << k;
    }
    cout << '\n';
  }
  return 0;
}