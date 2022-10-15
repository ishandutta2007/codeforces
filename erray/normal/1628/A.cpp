// author: erray
#include <bits/stdc++.h>

#ifdef DEBUG
  #include "debug.h"
#else
  #define debug(...) void(37)
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
    vector<vector<int>> pos(N + 1);
    for (int i = 0; i < N; ++i) {
      int X;
      cin >> X;
      pos[X].push_back(i);
      
    }
    for (auto&e : pos) {
      reverse(e.begin(), e.end());
    }
    debug(pos);

    vector<int> ans;
    int p = -1;
    while (!pos[0].empty() && pos[0][0] > p) {
      int v = 0;
      int np = p;
      while (v <= N && !pos[v].empty() && pos[v][0] > np) {
        while (pos[v].back() <= np) {
          pos[v].pop_back();
        }
        p = max(p, pos[v].back());
        ++v;
      }
      ans.push_back(v);
    }
    while (p < N - 1) {
      ans.push_back(0);
      ++p;
    }
    cout << int(ans.size()) << '\n';
    for (auto e : ans) {
      cout << e << ' ';
    }
    cout << '\n';
  }
}