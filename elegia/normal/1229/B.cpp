#include <cstdio>

#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 100010, P = 1000000007;

int n, ans;
ll x[N];
vector<int> g[N];
bool vis[N];

void dfs(int u, vector<pair<ll, int>> vec) {
  vis[u] = true;
  pair<ll, int> cur(x[u], 1);
  vector<pair<ll, int>> res;
  for (int i = (int)vec.size() - 1; i >= 0; --i) {
    ll g = __gcd(vec[i].first, cur.first);
    if (g == cur.first)
      cur.second += vec[i].second;
    else {
      res.push_back(cur);
      cur = make_pair(g, vec[i].second);
    }
  }
  res.push_back(cur);
  reverse(res.begin(), res.end());
  vec.clear();
  for (const auto& pr : res)
    ans = (ans + pr.first % P * pr.second) % P;
  for (int v : g[u])
    if (!vis[v])
      dfs(v, res);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%lld", &x[i]);
  for (int rep = 1; rep < n; ++rep) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, vector<pair<ll, int>>());
  printf("%d\n", ans);
  return 0;
}