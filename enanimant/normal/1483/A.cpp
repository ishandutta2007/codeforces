/*
 * author:  ADMathNoob
 * created: 03/21/21 09:12:46
 * problem: https://codeforces.com/contest/1483/problem/A
 */

/*
g++ 1483A.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors && a
g++ 1483A.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -g -Wall -Wfatal-errors -ggdb && gdb a
g++ 1483A.cpp -D_DEBUG -std=c++11 -Wl,--stack=268435456 -O3 -Wall -Wfatal-errors && a


*/

#include "bits/stdc++.h"

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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> f(m);
    vector<int> take(m);
    vector<int> cnt(n, 0);
    for (int i = 0; i < m; i++) {
      int k;
      cin >> k;
      f[i].resize(k);
      for (int j = 0; j < k; j++) {
        cin >> f[i][j];
        --f[i][j];
      }
      take[i] = 0;
      cnt[f[i][take[i]]] += 1;
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
      if (cnt[i] > cnt[mx]) {
        mx = i;
      }
    }
    const int M = (m + 1) / 2;
    for (int i = 0; i < m; i++) {
      if (cnt[f[i][take[i]]] > M && (int) f[i].size() >= 2) {
        cnt[f[i][take[i]]] -= 1;
        take[i]++;
        cnt[f[i][take[i]]] += 1;
      }
    }
    if (*max_element(cnt.begin(), cnt.end()) <= M) {
      cout << "YES\n";
      for (int i = 0; i < m; i++) {
        if (i > 0) {
          cout << ' ';
        }
        cout << f[i][take[i]] + 1;
      }
      cout << '\n';
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}