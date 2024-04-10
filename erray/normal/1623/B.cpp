// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
  #define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while (TT--) {
    int N;
    cin >> N;
    vector<array<int, 2>> A(N);
    vector<vector<int>> p(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i][0] >> A[i][1];
      --A[i][0], --A[i][1];
      p[A[i][0]].push_back(A[i][1]);
    }
    for (auto& e : p) {
      sort(e.begin(), e.end());
    }

    vector<array<int, 3>> ans;
    for (int i = 0; i < N; ++i) {
      if (p[i].empty()) {
        continue;
      }
      ans.push_back({i, p[i][0], i});
      for (int j = 1; j < int(p[i].size()); ++j) {
        ans.push_back({i, p[i][j], p[i][j - 1] + 1});
      }
    }
    for (auto[l, r, d] : ans) {
      cout << l + 1 << ' ' << r + 1 << ' ' << d + 1 << '\n';
    }
    cout << '\n';
  }
}