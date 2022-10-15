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
  string S;  
  cin >> N >> K >> S;
  vector<int> L(N), R(N);
  for (int i = 0; i < N; ++i) {
    cin >> L[i] >> R[i];
    --L[i], --R[i];
  }

  vector<int> r;
  function<void(int)> Pre = [&](int v) {
    if (v == -1) {
      return;
    }
    Pre(L[v]);
    r.push_back(v);
    Pre(R[v]);
  };
  Pre(0);
  string next(N, '*');
  for (int i = N - 2; i >= 0; --i) {
    next[r[i]] = (S[r[i + 1]] == S[r[i]] ? next : S)[r[i + 1]];
  }
  debug(r);
  debug(next);
  vector<int> need(N, 1);
  vector<int> vis(N);
  function<void(int)> Dfs = [&](int v) {
    debug(v, need[v]);
    if (L[v] != -1) {
      need[L[v]] = need[v] + 1;
      Dfs(L[v]);
      vis[v] |= vis[L[v]];
    } 
    if (!vis[v] && need[v] <= K && next[v] > S[v]) {
      vis[v] = true;
      K -= need[v];
    }

    if (vis[v] && R[v] != -1) {   
      Dfs(R[v]);
    }
  };
  Dfs(0);
  string res;
  for (auto v : r) {
    res += string(1 + vis[v], S[v]);
  }
  cout << res << '\n';
}