#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

int N, K, M;
int G[80][80];
int dp[81][81][81][2];

int rec(int left, int right, int times, bool type)
{
  if(times == K) return (0);
  if(right < 0 || left >= N) return (INF);
  if(~dp[left][right][times][type]) return (dp[left][right][times][type]);
  int now = type ? right + 1 : left - 1;
  int ret = INF;
  for(int i = left; i <= right; i++) {
    if(G[now][i] == INF) continue;
    if(type) {
      ret = min(ret, rec(i + 1, right, times + 1, 0) + G[now][i]);
      ret = min(ret, rec(left, i - 1, times + 1, 1) + G[now][i]);
    } else {
      ret = min(ret, rec(left, i - 1, times + 1, 1) + G[now][i]);
      ret = min(ret, rec(i + 1, right, times + 1, 0) + G[now][i]);
    }
  }
  return (dp[left][right][times][type] = ret);
}

int main()
{

  fill_n(*G, 80 * 80, INF);
  memset(dp, -1, sizeof(dp));

  cin >> N >> K;
  cin >> M;
  for(int i = 0; i < M; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    --u, --v;
    G[u][v] = min(G[u][v], c);
  }
  int ret = INF;
  for(int i = 0; i < N; i++) {
    ret = min(ret, rec(i + 1, N - 1, 1, 0));
    ret = min(ret, rec(0, i - 1, 1, 1));
  }
  if(ret == INF) cout << -1 << endl;
  else cout << ret << endl;
}