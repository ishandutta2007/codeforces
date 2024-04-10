#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <cassert>
 
using namespace std;

typedef long long ll;
typedef long double ld;

struct Edge {
  int u, v, w;
  Edge() {}
  Edge(int u, int v, int w) : u(u), v(v), w(w) {}
  bool operator <(const Edge &other) const {
    if (u != other.u) return u < other.u;
    if (v != other.v) return v < other.v;
    return w < other.w;
  }
};

const ll Inf = 1e18;

vector <ll> dijkstra(vector <vector <Edge>> g, int st) {
  int n = g.size();
  vector <ll> d(n, Inf);
  d[st] = 0;
  set <pair <ll, int>> q;
  q.insert({0, st});
  while (!q.empty()) {
    int u = q.begin()->second;
    q.erase(q.begin());
    for (auto [v, w, i] : g[u]) {
      if (d[v] > d[u] + w) {
        q.erase({d[v], v});
        d[v] = d[u] + w;
        q.insert({d[v], v});
      }
    }
  }
  return d;
}

vector <int> process(vector <vector <Edge>> g, vector <int> path, int st) {
  int n = g.size();
  vector <int> ptr(n);
  vector <ll> d(n, Inf);
  set <pair <ll, int>> q;
  ptr[st] = 1;
  d[st] = 1;
  q.insert({0, st});
  while (!q.empty()) {
    int u = q.begin()->second;
    q.erase(q.begin());
    for (auto [v, w, i] : g[u]) {
      if (d[v] > d[u] + w) {
        q.erase({d[v], v});
        d[v] = d[u] + w;
        q.insert({d[v], v});
        ptr[v] = ptr[u];
        if (ptr[v] < (int)path.size() && path[ptr[v]] == v) {
          ++ptr[v];
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) --ptr[i];
  return ptr;
}

struct SegmentTree {
  int n;
  vector <ll> t;

  SegmentTree(int _n) {
    n = _n;
    t.resize(2 * n, Inf);
  }
  
  void modify(int l, int r, ll x) {
    ++r;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        t[l] = min(t[l], x);
        ++l;
      }
      if (r & 1) {
        --r;
        t[r] = min(t[r], x);
      }
    }
  }

  ll get(int id) {
    ll res = Inf;
    for (id += n; id >= 1; id >>= 1) {
      res = min(res, t[id]);
    }
    return res;
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m, q;
  cin >> n >> m >> q;
  vector <vector <Edge>> g(n);
  vector <Edge> edges;
  map <Edge, int> num;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    g[u].emplace_back(v, w, i);
    g[v].emplace_back(u, w, i);
    edges.push_back({u, v, w});
  }
  vector <ll> d = dijkstra(g, 0);
  vector <ll> rd = dijkstra(g, n - 1);
  vector <int> path;
  vector <int> in_path(m, -1);
  {
    int u = n - 1;
    bool ch = true;
    while (ch) {
      path.push_back(u);
      ch = false;
      for (auto [v, w, i] : g[u]) {
        if (d[u] == d[v] + w) {
          in_path[i] = (int)path.size();
          u = v;
          ch = true;
          break;
        }
      }
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < m; ++i) {
      if (in_path[i] != -1) {
        in_path[i] = (int)path.size() - in_path[i] - 1;
      }
    }
  }
  vector <int> l = process(g, path, 0);
  reverse(path.begin(), path.end());
  vector <int> r = process(g, path, n - 1);
  reverse(path.begin(), path.end());
  for (int i = 0; i < n; ++i) {
    r[i] = (int)path.size() - r[i] - 1;
  }
  auto get = [&] (int id) {
    return make_pair(min(l[edges[id].u], l[edges[id].v]), max(r[edges[id].u], r[edges[id].v]));
  };

  int k = path.size() - 1;
  SegmentTree tr(k);
  for (int i = 0; i < m; ++i) {
    if (in_path[i] == -1) {
      int u = edges[i].u, v = edges[i].v, w = edges[i].w;
      tr.modify(get(i).first, get(i).second - 1, min(d[u] + rd[v] + w, d[v] + rd[u] + w));
    }
  }
  for (int i = 0; i < q; ++i) {
    int id, x;
    cin >> id >> x;
    --id;
    int u = edges[id].u, v = edges[id].v;
    ll ans = min(d[u] + x + rd[v], d[v] + x + rd[u]);
    if (in_path[id] == -1) {
      ans = min(ans, d[n - 1]);
    } else {
      ans = min(ans, tr.get(in_path[id]));
    }
    cout << ans << '\n';
  } 
}