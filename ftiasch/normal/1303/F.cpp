#include <bits/stdc++.h>

const int N = 300;
const int C = 1001;
const int Q = 2000001;

struct Event {
  int t, x, y;
};

struct DSU {
  int find(int u) {
    if (parent[u] != u) {
      parent[u] = find(parent[u]);
    }
    return parent[u];
  }

  void add(int u) { size++, parent[u] = u; }

  void merge(int a, int b) {
    if (find(a) != find(b)) {
      size--, parent[find(a)] = find(b);
    }
  }

  int size, parent[N * N];
} dsu;

int n, m, q, color[N][N], now, timestamp[N][N], result[Q];
std::set<int> cs;
std::map<int, std::vector<Event>> enters, leaves;

int id(int x, int y) { return x * m + y; }

void add(int x, int y) {
  static int DELTA_X[] = {-1, 0, 0, 1};
  static int DELTA_Y[] = {0, -1, 1, 0};

  timestamp[x][y] = now;
  dsu.add(id(x, y));
  for (int k = 0; k < 4; ++k) {
    int xx = x + DELTA_X[k];
    int yy = y + DELTA_Y[k];
    if (0 <= xx && xx < n && 0 <= yy && yy < m && timestamp[xx][yy] == now) {
      dsu.merge(id(x, y), id(xx, yy));
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  cs.insert(0);
  for (int i = 0, x, y, c; i < q; ++i) {
    scanf("%d%d%d", &x, &y, &c);
    x--, y--;
    if (color[x][y] != c) {
      cs.insert(c);
      enters[c].push_back(Event{i, x, y});
      leaves[color[x][y]].push_back(Event{i, x, y});
      color[x][y] = c;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      leaves[color[i][j]].push_back(Event{q, i, j});
    }
  }
  now = 0;
  for (int c : cs) {
    now++, dsu.size = 0;
    int pre_size_fwd = 0;
    for (int i = 0; i + 1 < static_cast<int>(enters[c].size()); ++i) {
      auto e = enters[c][i];
      add(e.x, e.y);
      result[e.t] += dsu.size - pre_size_fwd;
      pre_size_fwd = dsu.size;
    }
    if (!leaves[c].empty()) {
      now++, dsu.size = 0;
      int pre_size_bwd = 0;
      for (int i = leaves[c].size(); i--;) {
        auto e = leaves[c][i];
        add(e.x, e.y);
        result[e.t] += pre_size_bwd - dsu.size;
        pre_size_bwd = dsu.size;
      }
      result[c ? enters[c].back().t : 0] += pre_size_bwd - pre_size_fwd;
    }
  }
  for (int i = 0, sum = 0; i < q; ++i) {
    sum += result[i];
    printf("%d\n", sum);
  }
}