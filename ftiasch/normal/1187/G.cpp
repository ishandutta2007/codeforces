#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 50;
const int MAX_LEVELS = N + N - 1;
const int V = N * MAX_LEVELS + 2;

int n, m, l, c, d, a[N], xy[N << 1], levels, head[V], built[1 << 16];

struct Edge {
  int get_cost(int i) const {
    if (info == -2) {
      return 0;
    }
    if (info == -1) {
      return i & 1 ? -c : c;
    }
    int dup = info & 255;
    int cost = c + (2 * dup - 1) * d;
    return i & 1 ? -cost : cost;
  }

  int info, u, v, cap, nxt;
};

// info = -2 | a zero edge
// info = -1 | a edge with cost = c
// info = level | 2*m (8bit) | dup (8bit)

std::vector<Edge> edges;

void add_edge(int u, int v, int info, int cap) {
  int index = edges.size();
  edges.push_back(Edge{info, u, v, cap, head[u]});
  head[u] = index;
}

void add_biedge(int a, int b, int info, int cap) {
  add_edge(a, b, info, cap);
  add_edge(b, a, info, 0);
}

int get_id(int lv, int u) { return lv * n + u; }

void build_more(int i) {
  auto &&e = edges[i];
  int info = e.info;
  if ((~i & 1) && info >= 0) {
    int id = info >> 8;
    int dup = info & 255;
    if (dup == built[id]) {
      built[id]++;
      add_biedge(e.u, e.v, info + 1, 1);
    }
  }
}

int dist[V], back[V];
bool visited[V];

int main() {
  scanf("%d%d%d%d%d", &n, &m, &l, &c, &d);
  for (int i = 0; i < l; ++i) {
    scanf("%d", a + i);
    a[i]--;
  }
  for (int i = 0; i < m << 1; ++i) {
    scanf("%d", xy + i);
    xy[i]--;
  }
  // 0 1 ... (n - 1) | l = 1 | layer = n
  //                 | l = 2 | layer = n + 1
  levels = n - 1 + l;
  memset(head, -1, sizeof(head));
  int source = levels * n;
  int sink = source + 1;
  for (int i = 0; i < l; ++i) {
    add_biedge(source, get_id(0, a[i]), -2, 1);
  }
  for (int lv = 0; lv < levels; ++lv) {
    if (lv + 1 < levels) {
      // stay
      for (int u = 0; u < n; ++u) {
        add_biedge(get_id(lv, u), get_id(lv + 1, u), -1, l);
      }
      for (int f = 0; f < m << 1; ++f) {
        built[lv << 8 | f] = 1;
        add_biedge(get_id(lv, xy[f]), get_id(lv + 1, xy[f ^ 1]),
                   lv << 16 | f << 8 | 1, 1);
      }
    }
    add_biedge(get_id(lv, 0), sink, -2, l);
  }
  int result = 0;
  for (int _ = 0; _ < l; ++_) {
    std::fill(dist, dist + (sink + 1), INT_MAX);
    memset(visited, 0, sizeof(bool) * (sink + 1));
    std::queue<int> queue;
    visited[source] = true;
    dist[source] = 0;
    queue.push(source);
    while (!queue.empty()) {
      int u = queue.front();
      queue.pop();
      visited[u] = false;
      for (int iterator = head[u]; ~iterator;) {
        auto &e = edges[iterator];
        int cost = e.get_cost(iterator);
        int v = e.v;
        if (e.cap > 0 && dist[u] + cost < dist[v]) {
          dist[v] = dist[u] + cost;
          back[v] = iterator;
          if (!visited[v]) {
            visited[v] = true;
            queue.push(v);
          }
        }
        iterator = e.nxt;
      }
    }
    assert(dist[sink] < INT_MAX);
    for (int v = sink; v != source;) {
      int iterator = back[v];
      result += edges[iterator].get_cost(iterator);
      edges[iterator].cap--;
      edges[iterator ^ 1].cap++;
      build_more(iterator);
      v = edges[iterator].u;
    }
  }
  printf("%d\n", result);
}