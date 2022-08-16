#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int N, M, K, x[200000], y[200000];
  set< pair< int, int > > g[200000];
  scanf("%d %d %d", &N, &M, &K);
  for(int i = 0; i < M; i++) {
    scanf("%d %d", &x[i], &y[i]);
    --x[i], --y[i];
    g[x[i]].emplace(y[i], i);
    g[y[i]].emplace(x[i], i);
  }
  queue< int > que;
  bool erased[200000] = {};
  int ans = N, ret[200000];
  for(int i = 0; i < N; i++) {
    if(g[i].size() < K) {
      que.emplace(i);
      erased[i] = true;
      --ans;
    }
  }
  for(int i = M - 1; i >= 0; i--) {
    while(que.size()) {
      int idx = que.front();
      que.pop();
      for(auto e : g[idx]) g[e.first].erase({idx, e.second});
      for(auto e : g[idx]) {
        if(!erased[e.first] && g[e.first].size() < K) {
          erased[e.first] = true;
          --ans;
          que.emplace(e.first);
        }
      }
      g[idx].clear();
    }
    ret[i] = ans;
    if(g[x[i]].count({y[i], i})) {
      g[x[i]].erase({y[i], i});
      g[y[i]].erase({x[i], i});
      if(!erased[x[i]] && g[x[i]].size() < K) {
        erased[x[i]] = true;
        --ans;
        que.emplace(x[i]);
      }
      if(!erased[y[i]] && g[y[i]].size() < K) {
        erased[y[i]] = true;
        --ans;
        que.emplace(y[i]);
      }
    }
  }

  for(int i = 0; i < M; i++) {
    printf("%d\n", ret[i]);
  }
}