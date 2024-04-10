// author: erray
#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
  #include "/home/eagle/debug.h"
#else
  #define debug(...) void(37)
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<int> P(N);
  for (int i = 0; i < N; ++i) {
    cin >> P[i];
  }
  vector<int> C(N);
  for (int i = 0; i < N; ++i) {
    cin >> C[i];
    --C[i];
  }
  int D;
  cin >> D;
  vector<int> K(D);
  vector<bool> in(N, true);
  for (int i = 0; i < D; ++i) {
    cin >> K[i];
    --K[i];
    in[K[i]] = false;
  }
  reverse(K.begin(), K.end());
  vector<vector<int>> g(N + M);
  vector<int> match(N + M, -1);
  int mex = 0;
  auto Add = [&](int x) {
    debug(x, P[x], C[x]);
    if (P[x] < N) {
      g[M + P[x]].push_back(C[x]);
    }
    while (true) {
      vector<bool> vis(N + M, false);
      function<bool(int)> F = [&](int v) {
        if (vis[v]) {
          return false;
        }
        vis[v] = true;
        for (auto u : g[v]) {
          if (match[u] == -1 || F(match[u])) {
            match[u] = v, match[v] = u;
            return true;
          }
        }
        return false;
      };

      if (mex < N && F(M + mex)) {
        ++mex;  
      } else {
        break;
      }
    }
    debug(mex, match);
  };
  for (int i = 0; i < N; ++i) {
    if (in[i]) {
      Add(i);
    } 
  }
  vector<int> ans(D);
  for (int i = 0; i < D; ++i) {
    ans[D - i - 1] = mex;
    Add(K[i]);
  }
  for (int i = 0; i < D; ++i) {
    cout << ans[i] << '\n';
  }
}