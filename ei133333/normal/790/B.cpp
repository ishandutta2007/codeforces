#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int N, K;
vector< int > g[200000];
int64 sum[200000][5];
int64 que[200000][5];

int64 dfs(int idx, int par = -1)
{
  int64 ret = 0;
  sum[idx][0]++;
  for(auto &to : g[idx]) {
    if(par == to) continue;
    ret += dfs(to, idx);
    for(int j = 0; j < K; j++) {
      for(int k = 0; k < K; k++) {
        ret += que[to][j] * sum[idx][k];
        ret += sum[to][j] * que[idx][k];
        if(j + k >= K) ret += sum[idx][k] * sum[to][j];
        ret += sum[idx][k] * sum[to][j];
      }
    }
    for(int j = 0; j < K; j++) {
      sum[idx][(j + 1) % K] += sum[to][j];
      que[idx][(j + 1) % K] += que[to][j] + (j == K - 1 ? sum[to][j] : 0);
    }
  }
  return (ret);
}

int main()
{
  cin >> N >> K;
  for(int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  cout << dfs(0) << endl;
}