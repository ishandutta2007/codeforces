#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 INF = 1LL << 60;

int N;
vector< int > g[200000];
int64 dp[200000][2];

int64 dfs(int idx, int par = -1, int depth = 0) {
  dp[idx][0] = 1;
  dp[idx][1] = 0;
  int64 ret = (depth + 1) / 2;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    ret += dfs(to, idx, depth + 1);
    dp[idx][0] += dp[to][1];
    dp[idx][1] += dp[to][0];
  }
  return ret;
}

int64 dfs2(int idx, int64 cost, int root, int par = -1) {
  int64 ret = cost;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    for(auto &toto : g[to]) {
      if(toto == idx) continue;
      ret += dfs2(toto, cost + (-dp[toto][0]+(dp[root][0]-dp[to][1])) + (-dp[toto][1]+(dp[root][1]-dp[to][0])), root, to);
    }
  }
  return ret;
}

int main() {

  cin >> N;
  for(int i = 1; i < N; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int other = -1;
  for(auto &p : g[0]) other = p;

  int64 ret = 0;

  {
    int64 all = dfs(0);
    ret += dfs2(0, all, 0);
  }
  {
    int64 all = dfs(other);
    ret += dfs2(other, all, other);
  }

  cout << ret / 2 << endl;
}