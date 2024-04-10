/*
 * author:  ADMathNoob
 * created: 07/18/21 23:52:47
 * problem: https://codeforces.com/contest/1399/problem/F
 */

/*
g++ 1399F.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -ggdb && gdb a

g++ 1399F.cpp -std=c++17 -D_DEBUG -D_GLIBCXX_DEBUG -Wl,--stack=268435456 -Wall -Wextra -Wfatal-errors -Wshadow -O3



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
    vector<pair<int, int>> s(n);
    for (auto& [L, R] : s) {
      cin >> L >> R;
    }
    s.emplace_back(-1, 1e9);
    vector<int> xs;
    for (const auto [L, R] : s) {
      xs.push_back(L);
      xs.push_back(R);
    }
    sort(xs.begin(), xs.end());
    xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
    const int X = (int) xs.size();
    for (auto& [L, R] : s) {
      L = (int) (lower_bound(xs.begin(), xs.end(), L) - xs.begin());
      R = (int) (lower_bound(xs.begin(), xs.end(), R) - xs.begin());
    }
    sort(s.begin(), s.end(), [&](const auto& a, const auto& b) {
      return a.second - a.first < b.second - b.first;
    });
    vector<vector<int>> Ls(X);
    for (int i = 0; i < n; i++) {
      const auto [L, R] = s[i];
      Ls[R].push_back(i);
    }
    vector<int> dp(n + 1);
    for (int i = 0; i <= n; i++) {
      const auto [L, R] = s[i];
      vector<int> best(X + 1, 0);
      for (int r = 0; r < X; r++) {
        for (int j : Ls[r]) {
          const auto [l, _] = s[j];
          if (L <= l && r <= R && (l != L || r != R)) {
            best[r + 1] = max(best[r + 1], best[l] + dp[j]);
          }
        }
        best[r + 1] = max(best[r + 1], best[r]);
      }
      dp[i] = 1 + best[X];
    }
    cout << dp[n] - 1 << '\n';
  }
  return 0;
}