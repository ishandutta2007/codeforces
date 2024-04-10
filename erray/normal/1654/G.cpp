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
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; ++i) {
    cin >> L[i];
  }

  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }
  
  vector<int> h(N, -1);
  {
    queue<int> que;
    for (int i = 0; i < N; ++i) {
      if (L[i]) {
        que.push(i);
        h[i] = 0;
      }
    }
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (auto u : g[v]) {
        if (h[u] == -1) {
          h[u] = h[v] + 1;
          que.push(u);
        }
      }
    }
  }

  vector<vector<int>> base(N);
  for (int i = 0; i < N; ++i) {
    bool is = false;
    for (auto u : g[i]) {
      is |= h[u] == h[i];
    }  
    if (is) {
      base[h[i]].push_back(i);
    }
  }

  debug(h);
  debug(base);
  {
    int diff = 0;
    for (int i = 0; i < N; ++i) {
      diff += !base[i].empty();
    }
    assert(diff <= 1000);
  }
  
  vector<vector<int>> vs(N);
  for (int i = 0; i < N; ++i) {
    vs[h[i]].push_back(i);
  }

  vector<int> mn(N, N);
  for (int t = N - 1; t >= 0; --t) {
    if (base[t].empty()) {
      continue;
    }
    vector<int> best(N, N + 5);
    for (auto v : base[t]) {
      best[v] = 0;
    }

    vector<bool> used(N);
    for (int c = 0; c < N; ++c) {
      if (!base[c].empty()) {
        sort(base[c].begin(), base[c].end(), [&](int x, int y) {
          return best[x] < best[y];
        });  
        int p = 0;
        vector<int> que;
        for (int d = 0; d < N; ++d) {
          while (p < int(base[c].size()) && best[base[c][p]] <= d) {
            int v = base[c][p];
            if (!used[v]) {
              used[v] = true;
              que.push_back(v);
            }
            ++p;
          }

          if (que.empty()) {
            if (p == int(base[c].size())) {
              break;
            }
            d = best[base[c][p]] - 1;
          } else {
            vector<int> new_que;
            for (auto v : que) {
              for (auto u : g[v]) {
                if (h[u] == h[v] && best[u] > best[v] + 1) {
                  best[u] = best[v] + 1;
                  new_que.push_back(u);
                  used[u] = true;
                }
              }
            }
            swap(que, new_que);
          }
        }
      }

      for (auto v : vs[c]) {
        for (auto u : g[v]) {
          if (h[u] == h[v] + 1) {
            best[u] = min(best[u], max(0, best[v] - 1));
          }
        }
      }
    }


    for (int i = 0; i < N; ++i) {
      if (best[i] == 0) {
        mn[i] = t;
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    cout << 2 * h[i] - min(mn[i], h[i]) << ' ';
  }
}