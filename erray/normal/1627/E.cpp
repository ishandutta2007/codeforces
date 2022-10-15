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
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
      cin >> X[i];
    }

    vector<vector<array<int, 4>>> g(N);
    vector<vector<int>> act(N);
    for (int i = 0; i < K; ++i) {
      int A, B, C, D, H;
      cin >> A >> B >> C >> D >> H;
      --A, --B, --C, --D;
      g[A].push_back({B, C, D, H});
      act[C].push_back(D);
      act[A].push_back(B);
    }
    act[0].push_back(0);
    act[N - 1].push_back(M - 1);
    debug(act);
    const long long inf = (long long) 1e18;
    debug(inf); 
    vector<vector<long long>> cost(N);
    int ind = 0;
    for (auto& e : act) {
      sort(e.begin(), e.end());
      e.erase(unique(e.begin(), e.end()), e.end());
      cost[ind].resize(int(e.size()), inf);
      ++ind;
    }
    debug(act);
    debug(cost);
    cost[0][0] = 0;
    for (int i = 0; i < N; ++i) {
      debug(i, act[i], cost[i]);
      for (int j = 1; j < int(act[i].size()); ++j) {
        cost[i][j] = min(cost[i][j], cost[i][j - 1] + 1LL * (act[i][j] - act[i][j - 1]) * X[i]);
      }
      for (int j = int(act[i].size()) - 2; j >= 0; --j) {
        cost[i][j] = min(cost[i][j], cost[i][j + 1] + 1LL * (act[i][j + 1] - act[i][j]) * X[i]);
      }
      debug(cost[i]);
      for (auto[B, C, D, H] : g[i]) {
        debug(B, C, D, H);
        int id = int(lower_bound(act[i].begin(), act[i].end(), B) - act[i].begin());
        int next = int(lower_bound(act[C].begin(), act[C].end(), D) - act[C].begin());
        debug(id, next, act[C]);
        cost[C][next] = min(cost[C][next], cost[i][id] - H);
      }
    }
    long long ans = cost[N - 1].back();
    if (ans >= (long long) 1e17) {
      cout << "NO ESCAPE\n";
    } else {
      cout << ans << '\n';
    }
  }
}