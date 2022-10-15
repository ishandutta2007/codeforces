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
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
      cin >> B[i];
    }
    vector<long long> pref(N + 1);
    for (int i = 0; i < N; ++i) {
      pref[i + 1] = pref[i] + A[i] - B[i];
    }

    vector<vector<int>> g(N + 1);
    for (int i = 0; i < M; ++i) {
      int X, Y;
      cin >> X >> Y;
      --X;
      g[X].push_back(Y);
      g[Y].push_back(X);
    }

    set<int> act;
    vector<int> que;
    for (int i = 0; i <= N; ++i) {
      act.insert(i);
      if (pref[i] == 0) {
        que.push_back(i); 
        act.erase(i);
      } 
    }

    for (int ii = 0; ii < int(que.size()); ++ii) {
      int v = que[ii];
      for (auto u : g[v]) {
        if (pref[u] != 0) {
          continue;
        }
        int l = u, r = v;
        if (l > r) {
          swap(l, r);
        }
        auto it = act.lower_bound(l);
        while (it != act.lower_bound(r + 1)) {
          que.push_back(*it);
          pref[*it] = 0;
          it = act.erase(it);  
        }
      }
    }
    cout << (act.empty() ? "YES" : "NO") << '\n';
  }
}