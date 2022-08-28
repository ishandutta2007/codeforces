#include <cassert>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

struct Node {
  pair<int, int> a;
  int b;

  Node(const pair<int, int>& a, int b) : a(a), b(b) {}

  bool operator>(const Node& rhs) const { return a > rhs.a; }
};

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int rep = 1; rep < n; ++rep) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<bool> vis(n);
  vector<int> prt(n, -1), dep(n), sz(n, 1), pref(n, -1);
  function<void(int)> dfs = [&](int u) {
    vis[u] = true;
    for (int v : g[u])
      if (!vis[v]) {
        dep[v] = dep[u] + 1;
        prt[v] = u;
        dfs(v);
        sz[u] += sz[v];
        if (pref[u] == -1 || sz[v] > sz[pref[u]])
          pref[u] = v;
      }
  };
  dfs(0);
  vector<int> top(n, -1), dfn(n);
  int t = 0;
  function<void(int)> hld = [&](int u) {
    dfn[u] = t++;
    if (top[u] == -1) top[u] = u;
    if (pref[u] != -1) {
      top[pref[u]] = top[u];
      hld(pref[u]);
      for (int v : g[u])
        if (v != prt[u] && v != pref[u])
          hld(v);
    }
  };
  hld(0);
  function<int(int, int)> lca = [&](int u, int v) {
    int x = top[u], y = top[v];
    while (x != y) {
      if (dep[x] > dep[y]) {
        swap(x, y);
        swap(u, v);
      }
      v = prt[y]; y = top[v];
    }
    return dep[u] < dep[v] ? u : v;
  };
  function<int(int, int)> dist = [&](int u, int v) { return dep[u] + dep[v] - (dep[lca(u, v)] << 1); };

  int q;
  cin >> q;
  stack<int> stk;
  while (q--) {
    int k, m;
    cin >> k >> m;
    vector<int> v(k), s(k), uu(m);
    for (int i = 0; i < k; ++i)
      cin >> v[i] >> s[i];
    cin >> uu;
    vector<pair<int, int>> ver;
    for (int& x : v) {
      --x;
      ver.emplace_back(dfn[x], x);
    }
    for (int& x : uu) {
      --x;
      ver.emplace_back(dfn[x], x);
    }
    sort(ver.begin(), ver.end());
    ver.erase(unique(ver.begin(), ver.end()), ver.end());
    map<int, int> mp;
    t = 0;
    vector<vector<int>> vir;
    vector<int> vu((k + m) * 2);
    vir.resize((k + m) * 2);
    function<int(int)> id = [&](int u) {
      auto it = mp.find(u);
      if (it != mp.end()) return it->second;
      vu[t] = u;
      mp.insert(make_pair(u, t));
      return t++;
    };
    function<void(int, int)> link = [&](int u, int v) {
      int x = id(u), y = id(v);
      vir[x].push_back(y);
      vir[y].push_back(x);
      //cerr << "link " << u << ' ' << v << '\n';
    };
    for (const auto& pr : ver) {
      int u = pr.second;
      if (stk.empty()) {
        stk.push(u);
        id(u);
        continue;
      }
      int prv = -1;
      int lc = lca(u, stk.top());
      while (!stk.empty() && dep[stk.top()] > dep[lc]) {
        if (prv != -1)
          link(prv, stk.top());
        prv = stk.top();
        stk.pop();
      }
      if (prv != -1) link(prv, lc);
      if (stk.empty() || stk.top() != lc) stk.push(lc);
      if (stk.top() != u) stk.push(u);
    }
    int prv = -1;
    while (!stk.empty()) {
      if (prv != -1)
        link(prv, stk.top());
      prv = stk.top();
      stk.pop();
    }
    vector<pair<int, int>> occ(t, make_pair(numeric_limits<int>::max(), numeric_limits<int>::max()));
    priority_queue<Node, vector<Node>, greater<Node>> que;
    for (int i = 0; i < k; ++i)
      que.emplace(occ[id(v[i])] = make_pair(0, i), id(v[i]));
    while (!que.empty()) {
      Node tmp = que.top(); que.pop();
      if (occ[tmp.b] != tmp.a) continue;
      int i = tmp.a.second;
      for (int x : vir[tmp.b]) {
        pair<int, int> di = make_pair((dist(v[i], vu[x]) + s[i] - 1) / s[i], tmp.a.second);
        //cerr << v[i] << " => " << vu[x] << " = (" << di.first << ", " << di.second << ")\n";
        if (di < occ[x])
          que.emplace(occ[x] = di, x);
      }
    }
//    for (int i = 0; i < m; ++i)
//      cerr << occ[id(uu[i])].first << ' ';
//    cerr << '\n';
    for (int i = 0; i < m; ++i)
      cout << (occ[id(uu[i])].second + 1) << ' ';
    cout << '\n';
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}