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
  int N, K;
  cin >> N >> K;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; ++i) {
    int X, Y;
    cin >> X >> Y;
    --X, --Y;
    g[X].push_back(Y);
    g[Y].push_back(X);
  }

  vector<int> par(N);
  vector<int> d(N);
  int l = 0;
  vector<int> ord;
  function<void(int)> Dfs = [&](int v) {
    l += g[v].empty();
    for (auto u : g[v]) {
      g[u].erase(find(g[u].begin(), g[u].end(), v));
      d[u] = d[v] + 1;
      par[u] = v;
      Dfs(u);
    }
    ord.push_back(v);
  };
  Dfs(0);
  if (l <= K) {
    K = min(K, max(l, N / 2));
    cout << 1LL * (N - K) * K << '\n';
    return 0;
  }

  vector<int> mx = d;
  for (auto v : ord) {
    for (auto u : g[v]) {
      mx[v] = max(mx[v], mx[u] + 1);
    }
  }
  reverse(ord.begin(), ord.end());
  vector<int> add(N);  
  vector<int> all;
  for (auto v : ord) {
    if (g[v].empty()) {
      all.push_back(add[v] + 1);
    } else {
      array<int, 2> yx = {-1, -1};
      for (auto u : g[v]) {
        yx = max(yx, array{mx[u], u});
      }
      add[yx[1]] = add[v] + 1;
    }
  }

  sort(all.rbegin(), all.rend());
  int used = 0;
  for (int i = 0; i < K; ++i) {
    used += all[i];
  }

  long long ans = 1LL * N * N;
  for (int i = 0; i <= N - used; ++i) {
    ans = min(ans, 1LL * (N - K - i) * (K - i));
  }
  cout << ans << '\n';
}