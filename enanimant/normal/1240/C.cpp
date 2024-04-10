// October 6, 2019
// http://codeforces.com/contest/1240/problem/C

/*

*/


#include <bits/stdc++.h>

using namespace std;


const int N = 500000;


int n, k;
vector<pair<int, int>> g[N];
long long dp[N][2];

void dfs(int v, int p) {
  dp[v][0] = dp[v][1] = 0;
  vector<pair<int, int>> join; // node, cost of edge to that node
  long long res = 0;
  for (const auto &pp : g[v]) {
    int to = pp.first;
    int cost = pp.second;
    if (to == p) {
      continue;
    }
    dfs(to, v);
    res += dp[to][0];
    if (dp[to][0] < dp[to][1] + cost) {
      join.emplace_back(to, cost);
    }
  }
  sort(join.begin(), join.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
    int da = dp[a.first][1] + a.second - dp[a.first][0];
    int db = dp[b.first][1] + b.second - dp[b.first][0];
    return da > db;
  });
  int ch = (int) join.size();
  for (int i = 0; i < min(ch, k - 1); i++) {
    int to = join[i].first;
    int cost = join[i].second;
    res -= dp[to][0];
    res += dp[to][1] + cost;
  }
  dp[v][0] = dp[v][1] = res;
  if (ch >= k) {
    int to = join[k - 1].first;
    int cost = join[k - 1].second;
    dp[v][0] += dp[to][1] + cost - dp[to][0];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("debug_output.txt", "w", stderr);
#endif


  int tt;
  cin >> tt;
  while (tt--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      g[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      u--;
      v--;
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
    }
    dfs(0, -1);
    cout << dp[0][0] << '\n';
  }


  return 0;
}