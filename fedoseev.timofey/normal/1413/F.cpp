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
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
#include <bitset>
#include <chrono>
 
using namespace std;
 
typedef long long ll;
const int N = 5e5 + 7;
 
vector <int> g[N];
int par[N];
int h1[N], h2[N];
int v1[N], v2[N];
 
int ph[N];
 
void dfs(int u, int p) {
    h2[u] = -1e9;
    par[u] = p;
    for (auto v : g[u]) {
        if (v != p) {
            dfs(v, u);
            if (h1[v] + 1 > h1[u]) {
                h2[u] = h1[u];
                h1[u] = h1[v] + 1;
            } else {
                h2[u] = max(h2[u], h1[v] + 1);
            }
        }
    }
}
 
void jhfs(int u, int p) {
    v1[u] = v2[u] = -1;
    for (auto v : g[u]) {
        if (v != p) {
            ph[v] = max(ph[v], ph[u] + 1);
            if (h1[u] == h1[v] + 1) {
                ph[v] = max(ph[v], h2[u] + 1);
            } else {
                ph[v] = max(ph[v], h1[u] + 1);
            }
            if (h1[v] + 1 == h1[u]) {
                v1[u] = v;
            } else if (h1[v] + 1 == h2[u]) {
                v2[u] = v;
            }
            jhfs(v, u);
        }
    }
}
 
int get(int u, int ban) {
    int res = 0;
    if (ban != par[u]) res = max(res, ph[u]);
    if (v1[u] != ban) res = max(res, h1[u]);
    if (v2[u] != ban) res = max(res, h2[u]);
    return res; 
}
 
pair <int, int> best;
 
void dfsD(int u, int d, int p) {
    best = max(best, {d, u});
    for (auto v : g[u]) {
        if (v != p) {
            dfsD(v, d + 1, u);
        }
    }
}
 
vector <int> curPath;
vector <int> path;
 
void dfsP(int u, int finish, int p) {
    curPath.push_back(u);
    if (u == finish) path = curPath;
    for (auto v : g[u]) {
        if (v != p) dfsP(v, finish, u);
    }
    curPath.pop_back();
}
 
vector <int> getPath(int u, int v) {
    dfsP(u, v, -1);
    return path;
}
 
vector <int> getDiam() {
    best = {-1, 0};
    dfsD(0, 0, -1);
    int u = best.second;
    best = {-1, 0};
    dfsD(u, 0, -1);
    int v = best.second;
    return getPath(u, v);
}
 
struct Edge {
  int u, v, t;
};
 
const int Inf = 1e9;

struct SegmentTree {
  vector <vector <int>> best;
  vector <int> mod;
  void update(int v) {
    swap(best[v][0], best[v][1]);
    mod[v] ^= 1;
  }
  void push(int v) {
    if (mod[v]) {
      update(2 * v + 1);
      update(2 * v + 2);
      mod[v] = 0;
    }
  }
  void pull(int v) {
    for (int i = 0; i < 2; ++i) {
      best[v][i] = max(best[2 * v + 1][i], best[2 * v + 2][i]);
    }
  }
  void modify(int ql, int qr, int l, int r, int v) {
    if (r < ql || qr < l) return;
    if (ql <= l && r <= qr) {
      update(v);
    } else {
      push(v);
      int m = (l + r) / 2;
      modify(ql, qr, l, m, 2 * v + 1);
      modify(ql, qr, m + 1, r, 2 * v + 2);
      pull(v);
    }
  }
  pair <int, int> get(int ql, int qr, int l, int r, int v) {
     if (r < ql || qr < l) return make_pair(-Inf, -Inf);
     if (ql <= l && r <= qr) {
       return make_pair(best[v][0], best[v][1]);
     }
     push(v);
     int m = (l + r) >> 1;
     auto p1 = get(ql, qr, l, m, 2 * v + 1);
     auto p2 = get(ql, qr, m + 1, r, 2 * v + 2);
     return make_pair(max(p1.first, p2.first), max(p1.second, p2.second));
  }
  void build(int l, int r, int v, vector <int> &xr, vector <int> &h) {
    if (l == r) {
      best[v][xr[l]] = h[l];
    } else {
      int m = (l + r) / 2;
      build(l, m, 2 * v + 1, xr, h);
      build(m + 1, r, 2 * v + 2, xr, h);
      pull(v);
    }
  }
  SegmentTree(int n) {
    best.resize(4 * n, vector <int> (2, -Inf));
    mod.resize(4 * n, 0);
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int n;
  cin >> n;
  vector <Edge> E;
  for (int i = 0; i + 1 < n; ++i) {
    int u, v, t;
    cin >> u >> v >> t;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    E.push_back({u, v, t});
  }
  dfs(0, -1);
  jhfs(0, -1);
  int can = 0;
  for (int i = 0; i < n; ++i) {
    vector <int> cur;
    cur.push_back(max(0, h1[i]));
    cur.push_back(max(0, h2[i]));
    cur.push_back(max(0, ph[i]));
    sort(cur.begin(), cur.end());
    can = max(can, cur[0] + cur[1]);
  }
  int rt = -1;
  {
    vector <int> D = getDiam();
    rt = D[(int)D.size() / 2];
  }
  vector <vector <pair <int, int>>> cg(n);
  for (auto e : E) {
    cg[e.u].push_back(make_pair(e.v, e.t));
    cg[e.v].push_back(make_pair(e.u, e.t));
  }
  vector <int> l(n), r(n);
  vector <int> xr(n);
  vector <int> hh(n);
  vector <int> e;
  vector <int> who(n);
  function <void(int, int)> zhfs = [&] (int u, int p) {
    par[u] = p;
    e.push_back(u);
    l[u] = (int)e.size() - 1;
    for (auto [v, t] : cg[u]) {
      if (v != p) {
        hh[v] = hh[u] + 1;
        xr[v] = xr[u] ^ t;
        zhfs(v, u);
      }
    }
    r[u] = (int)e.size() - 1;
  };
  zhfs(rt, -1);

  function <void(int, int)> hs = [&] (int u, int p) {
    for (auto [v, t] : cg[u]) {
      if (v != p) {
        if (u == rt) {
          who[v] = v;
        } else {
          who[v] = who[u];
        }
        hs(v, u);
      }
    }
  };

  hs(rt, -1);

  SegmentTree tr(n);
  {
    vector <int> nxr(n);
    vector <int> nh(n);
    for (int i = 0; i < n; ++i) {
      nxr[l[i]] = xr[i];
      nh[l[i]] = hh[i];
    }
    tr.build(0, n - 1, 0, nxr, nh);
    
  }

  multiset <int> he, ho;
  auto add = [&] (int v) {
    auto p = tr.get(l[v], r[v], 0, n - 1, 0);
    he.insert(p.first);
    ho.insert(p.second);
  };
  auto del = [&] (int v) {
    auto p = tr.get(l[v], r[v], 0, n - 1, 0);
    he.erase(he.find(p.first));
    ho.erase(ho.find(p.second));
  };
  for (auto v : g[rt]) {
    add(v);
  }
  int m;
  cin >> m;
  while (m--) {
    int id;
    cin >> id;
    --id;
    int u = E[id].u, v = E[id].v;
    if (par[u] != v) {
      swap(u, v);
    }
    del(who[u]);
    tr.modify(l[u], r[u], 0, n - 1, 0);
    add(who[u]);
    int res = 0;
    if (he.size() >= 2) {
      res = max(res, *he.rbegin() + *prev(--he.end()));
    } 
    if (he.size() >= 1) {
      res = max(res, *he.rbegin());
    }
    if (ho.size() >= 2) {
      res = max(res, *ho.rbegin() + *prev(--ho.end()));
    }
    res = max(res, can);
    cout << res << '\n';
  } 
}