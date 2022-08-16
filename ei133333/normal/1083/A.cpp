#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

struct edge {
  int to, cost;
};

int N, W[300000];
vector< edge > g[300000];
int64 ret;

int64 dfs(int idx, int par) {
  vector< int64 > dist;
  for(auto &e : g[idx]) {
    if(e.to == par) continue;
    dist.emplace_back(dfs(e.to, idx) - e.cost);
  }
  sort(dist.rbegin(), dist.rend());
  int64 dump = W[idx];
  if(dist.size() >= 1) dump = max(dump, dist[0] + W[idx]);
  if(dist.size() >= 2) ret = max(ret, dist[0] + dist[1] + W[idx]);
  ret = max(ret, dump);
  return dump;
}

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &W[i]);
  }
  for(int i = 1; i < N; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    --u, --v;
    g[u].push_back((edge) {v, c});
    g[v].push_back((edge) {u, c});
  }
  dfs(0, -1);
  cout << ret << endl;
}