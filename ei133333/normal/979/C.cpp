#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

int N, X, Y;
vector< int > g[300000];
int sz[300000], dp[300000];

int main() {
  scanf("%d %d %d", &N, &X, &Y);
  --X, --Y;
  for(int i = 1; i < N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x, --y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
    sz[x]++;
    sz[y]++;
  }
  int64 all = 1LL * N * (N - 1);

  queue< int > q;
  for(int i = 0; i < N; i++) {
    dp[i] = 1;
    if(sz[i] == 1) {
      q.emplace(i);
    }
  }
  while(q.size()) {
    int p = q.front();
    q.pop();
    --sz[p];
    if(p == X || p == Y) continue;
    for(auto &to : g[p]) {
      --sz[to];
      if(sz[to] == 0) continue;
      dp[to] += dp[p];
      if(sz[to] == 1) q.emplace(to);
    }
  }

  printf("%lld\n", all - 1LL * dp[X] * dp[Y]);
}