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
  int tt;
  cin >> tt;
  while (tt--) {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    } 

    auto C = [&](int x, int y) {
      if (x < 0 || x >= N || y < 0 || y >= M) {
        return -1;
      }
      return x * M + y;
    };

    vector<int> e(N * M, -1);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        int res = -1;
        if (A[i][j] == 'L') {
          res = C(i, j - 1);
        } else if (A[i][j] == 'R') {
          res = C(i, j + 1);
        } else if (A[i][j] == 'U') {
          res = C(i - 1, j);
        } else {
          res = C(i + 1, j);
        }
        e[C(i, j)] = res;
      }
    }

    debug(e);	

    int n = N * M;
    vector<int> size(n, 1);
    vector<int> vis(n, -1);
    vector<int> from(n, -1);
    for (int i = 0; i < n; ++i) {
      int v = i;
      int t = 0;
      while (v != -1 && vis[v] == -1) {
        vis[v] = t++;
        from[v] = i;
        v = e[v];
      }

      if (v != -1 && from[v] == i) {
        int u = v;
        do {
          size[u] = t - vis[v];
          int bu = u;
          u = e[u];
          e[bu] = -1;             
        } while (u != v);
      }
    }
    debug(size, e);
    
    vector<vector<int>> rg(n);
    queue<int> que;    
    for (int i = 0; i < n; ++i) {
      if (e[i] != -1) {
        rg[e[i]].push_back(i);
      } else {
        que.push(i);
      }
    }

    vector<int> ans(n);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      ans[v] += size[v];
      for (auto u : rg[v]) {
        ans[u] = ans[v];
        que.push(u);
      } 
    }
    auto mx = max_element(ans.begin(), ans.end());
    int res = int(mx - ans.begin());
    cout << 1 + res / M << ' ' << 1 + res % M << ' ' << *mx << '\n';
  }
}