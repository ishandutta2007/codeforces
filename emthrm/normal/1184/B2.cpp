#include <bits/stdc++.h>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;

struct HopcroftKarp {
  vector<int> match;

  HopcroftKarp(int left, int right) : left(left), graph(left), match(left + right, -1), level(left), used(left, -1) {}

  void add_edge(int u, int v) { graph[u].emplace_back(left + v); }

  int solve() {
    int res = 0;
    while (true) {
      bfs();
      int tmp = 0;
      REP(i, left) if (match[i] == -1) {
        if (dfs(i)) ++tmp;
        ++timestamp;
      }
      if (tmp == 0) return res;
      res += tmp;
    }
  }

private:
  int left, timestamp = 0;
  vector<vector<int> > graph;
  vector<int> level, used;

  void bfs() {
    fill(ALL(level), -1);
    queue<int> que;
    REP(i, left) {
      if (match[i] == -1) {
        que.emplace(i);
        level[i] = 0;
      }
    }
    while (!que.empty()) {
      int ver = que.front(); que.pop();
      for (int e : graph[ver]) if (match[e] != -1 && level[match[e]] == -1) {
        level[match[e]] = level[ver] + 1;
        que.emplace(match[e]);
      }
    }
  }

  bool dfs(int ver) {
    used[ver] = timestamp;
    for (int e : graph[ver]) {
      int tmp = match[e];
      if (tmp == -1 || (used[tmp] < timestamp && level[tmp] == level[ver] + 1 && dfs(tmp))) {
        used[ver] = timestamp;
        match[e] = ver;
        match[ver] = e;
        return true;
      }
    }
    return false;
  }
};

void WarshallFloyd(vector<vector<int> > &graph) {
  int n = graph.size();
  REP(k, n) REP(i, n) REP(j, n) {
    if (graph[i][k] != INF && graph[k][j] != INF && graph[i][j] > graph[i][k] + graph[k][j]) {
      graph[i][j] = graph[i][k] + graph[k][j];
    }
  }
}

int main() {
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<vector<int> > graph(n, vector<int>(n, INF));
  REP(i, n) graph[i][i] = 0;
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    if (u != v) graph[u][v] = graph[v][u] = 1;
  }
  WarshallFloyd(graph);
  int s, b; long long k, h; cin >> s >> b >> k >> h;
  vector<int> x(s), a(s), f(s);
  REP(i, s) {
    cin >> x[i] >> a[i] >> f[i]; --x[i];
  }
  HopcroftKarp hk(s, b);
  REP(i, b) {
    int xi, d; cin >> xi >> d; --xi;
    REP(j, s) if (d <= a[j]) {
      if (graph[x[j]][xi] <= f[j]) hk.add_edge(j, i);
    }
  }
  int match = hk.solve();
  long long ans = LINF;
  REP(i, s + 1) ans = min(ans, k * min(match, s - i) + h * i);
  cout << ans << '\n';
  return 0;
}