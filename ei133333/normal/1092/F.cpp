#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int N, A[200000];
vector< int > g[200000];
int64 cost[200000], sum[200000];

void dfs(int idx, int par) {
  cost[idx] = A[idx];
  for(auto to : g[idx]) {
    if(to == par) continue;
    dfs(to, idx);
    cost[idx] += cost[to];
    sum[idx] += sum[to] + cost[to];
  }
}

int64 dfs2(int idx, int par, int64 C, int64 S) {
  C += cost[idx];
  S += sum[idx];
  int64 ret = S;
  for(auto to : g[idx]) {
    if(to == par) continue;
    ret = max(ret, dfs2(to, idx, C - cost[to], (S - sum[to])+(C-2*cost[to])));
  }
  return ret;
}


int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for(int i = 1; i < N; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(0, -1);
  cout << dfs2(0, -1, 0, 0) << endl;
}