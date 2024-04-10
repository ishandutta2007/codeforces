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
 
struct Edge {
  int u, v, t;
  bool operator <(const Edge &other) const {
    return t > other.t;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m, q;
  cin >> n >> m >> q;
  vector <int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  vector <Edge> E;
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    E.push_back({u, v, q});
  }
  vector <pair <int, int>> qr;
  vector <int> ku(q, -1), kv(q, -1);
  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      --x;
      qr.push_back({i, x});
    } else {
      int x;
      cin >> x;
      --x;
      ku[i] = E[x].u;
      kv[i] = E[x].v;
      E[x].t = i;
    }
  }
  vector <int> cmp_num(q, -1);
  sort(E.begin(), E.end());
  vector <int> par(n); 
  vector <int> sz(n);
  for (int i = 0; i < n; ++i) {
    par[i] = i;
    sz[i] = 1;
  }
  function <int(int)> get = [&] (int u) {
    return (u == par[u] ? u : par[u] = get(par[u]));
  };
  int uk = 0;
  vector <int> cmpu(q, -1), cmpv(q, -1);
  vector <int> gou(q);
  int pt = qr.size() - 1;
  vector <set <int>> g(n);
  for (int tm = q; tm >= 0; --tm) {
    while (uk < (int)E.size() && E[uk].t > tm) {
      int u = E[uk].u, v = E[uk].v;
      int cu = get(u), cv = get(v);
      if (cu == cv) {
        ++uk;
        continue;
      }
      g[u].insert(v);
      g[v].insert(u);
      int del_t = E[uk].t;
      if (del_t < q) {
        cmpu[del_t] = cu;
        cmpv[del_t] = cv;
      }
      if (sz[cu] < sz[cv]) {
        par[cu] = cv;
        sz[cv] += sz[cu];
        if (del_t < q) {
          gou[del_t] = 1;
        }
      } else {
        par[cv] = cu;
        sz[cu] += sz[cv];
      }
      ++uk;
    } 
    if (pt >= 0 && qr[pt].first == tm) {
      cmp_num[tm] = get(qr[pt].second);
      --pt;
    }
  } 
  vector <priority_queue <int, vector <int>, less <int>>> have(n);
  vector <int> where(n + 1, -1);

  for (int i = 0; i < n; ++i) {
    have[get(i)].push(p[i]);
    where[p[i]] = get(i);
  }
  vector <int> ans;
  vector <int> used(n, -1);
  for (int i = 0; i < q; ++i) {
    if (cmp_num[i] != -1) {
      int c = cmp_num[i];
      bool fnd = false;
      while (!have[c].empty()) {
        int x = have[c].top();
        have[c].pop();
        if (where[x] == c) {
          ans.push_back(x);
          fnd = true;
          where[x] = -1;
          break;
        }
      }
      if (!fnd) ans.push_back(0);
    } else if (cmpu[i] != -1) {
      int u = ku[i], v = kv[i]; 
      g[u].erase(v);
      g[v].erase(u);
      if (!gou[i]) {
        swap(u, v);
        swap(cmpu[i], cmpv[i]);
      }
      vector <int> qq;
      qq.push_back(u);
      used[u] = i;
      for (int tt = 0; tt < (int)qq.size(); ++tt) {
        int w = qq[tt];
        if (where[p[w]] == cmpv[i]) {
          where[p[w]] = cmpu[i];
          have[cmpu[i]].push(p[w]);
        }   
        for (auto to : g[w]) {
          if (used[to] != i) {
            used[to] = i;
            qq.push_back(to);
          }
        }
      }
    }
  }
  for (auto x : ans) {
    cout << x << '\n';
  }
}