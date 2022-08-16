#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
#define int long long

int N, M;
vector< int > graph[100000], rgraph[100000];
int sum[100000];
bool used[100000];
vector< int > order;
int dp[100000];

void dfs(int idx)
{
  if(used[idx]++) return;
  for(int i = 0; i < graph[idx].size(); i++) {
    dfs(graph[idx][i]);
  }
  order.push_back(idx);
}
signed main()
{
  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int U, V;
    cin >> U >> V;
    --U, --V;
    if(U > V) swap(U, V);
    graph[U].push_back(V);
    rgraph[V].push_back(U);
    sum[V]++;
    sum[U]++;
  }
  int64 ret = 0;
  queue< int > que;
  for(int i = 0; i < N; i++) {
    dfs(i);
  }
  reverse(order.begin(), order.end());

  for(int i = 0; i < order.size(); i++) {
    int u = order[i];
    dp[u] = 1;
    for(int j = 0; j < rgraph[u].size(); j++) {
      dp[u] = max(dp[u], dp[rgraph[u][j]] + 1);
    }
    ret = max(ret, 1LL * dp[u] * sum[u]);
  }
  cout << ret << endl;
}