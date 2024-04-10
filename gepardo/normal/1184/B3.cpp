#pragma GCC optimize("O3")

#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
int s, b, k;
const int N = 101;
const int M = 100001;
const ll inf = 1e14;
int a[N][N];

ll cost[M];
int vertex[M], fuel[M], damage[M];
vector<pair<ll, ll> > bases[N];
int st[M], dist[M];

struct edge {
    int to, lnk;
    ll flow;
};

vector<edge> ed[M];

void add_edge(int u, int v, ll flow) {
  ed[u].push_back(edge{v, (int)ed[v].size(), flow});
  ed[v].push_back(edge{u, (int)ed[u].size() - 1, 0});
}

bool bfs(int s, int t) {
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  bool fnd = false;
  while (!q.empty()) {
    int v = q.front();
    if (v == t) {
      fnd = true;
    }
    for (auto to : ed[v]) {
      if (to.flow == 0) {
        continue;
      }
      if (dist[to.to] <= dist[v] + 1) {
        continue;
      }
      dist[to.to] = dist[v] + 1;
      q.push(to.to);
    }
    q.pop();
  }
  return fnd;
}

ll dfs(int v, int t, ll p) {
  if (v == t) {
    return p;
  }
  for (; st[v] < ed[v].size(); st[v]++) {
    auto& to = ed[v][st[v]];
    if (to.flow == 0) {
      continue;
    }
    if (dist[to.to] != dist[v] + 1) {
      continue;
    }
    ll q = dfs(to.to, t, min(p, to.flow));
    if (q == 0) {
      continue;
    }
    to.flow -= q;
    ed[to.to][to.lnk].flow += q;
    return q;
  }
  return 0;
}

ll flow() {
  ll ans = 0;
  while (1) {
    for (int i = 0; i <= s + 1; i++) {
      st[i] = 0;
      dist[i] = s + 3;
    }
    if (!bfs(0, s + 1)) {
      break;
    }
    ll p = dfs(0, s + 1, inf);
    while (p != 0) {
      ans += p;
      p = dfs(0, s + 1, inf);
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  //freopen("input.txt", "r", stdin);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    a[u][v] = 1;
    a[v][u] = 1;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i][k] == 0) {
          continue;
        }
        if (a[k][j] == 0) {
          continue;
        }
        if (a[i][j] == 0) {
          a[i][j] = a[i][k] + a[k][j];
        }
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
      }
    }
  }
  cin >> s >> b >> k;
  for (int i = 1; i <= s; i++) {
    cin >> vertex[i] >> damage[i] >> fuel[i] >> cost[i];
  }

  for (int i = 0; i < b; i++) {
    int v, d, g;
    cin >> v >> d >> g;
    bases[v].emplace_back(d, g);
  }

  for (int i = 1; i <= n; i++) {
    sort(bases[i].begin(), bases[i].end());
    ll cur_mx = -inf;
    for (auto& it : bases[i]) {
      cur_mx = max(it.second, cur_mx);
      it.second = cur_mx;
    }
  }

  for (int i = 1; i <= s; i++) {
    cost[i] = -cost[i];
    ll mx = -inf;
    for (int v = 1; v <= n; v++) {
      if (a[vertex[i]][v] > fuel[i]) {
        continue;
      }
      auto it = lower_bound(bases[v].begin(), bases[v].end(), make_pair(ll(damage[i] + 1), -1ll));
      if (it == bases[v].begin()) {
        continue;
      }
      it--;
      mx = max(mx, it->second);
    }
    cost[i] += mx;
  }
  ll positive_sum = 0;
  for (int i = 1; i <= s; i++) {
    positive_sum += abs(max(cost[i], 0ll));
    if (cost[i] > 0) {
      add_edge(0, i, cost[i]);
    } else if (cost[i] < 0) {
      add_edge(i, s + 1, -cost[i]);
    }
  }
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    add_edge(u, v, inf);
  }
  cout << positive_sum - flow() << "\n";
  return 0;
}