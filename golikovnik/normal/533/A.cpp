//  Copyright 2021 Nikita Golikov

#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#ifdef GOLIKOV
    #define debug(x) cerr << (#x) << ":\t" << (x) << endl
#else
    #define debug(x) 238;
#endif

template <class A, class B>
bool smin(A &x, B &&y) {
  if (y < x) {
    x = y;
    return true;
  }
  return false;
}

template <class A, class B>
bool smax(A &x, B &&y) {
  if (x < y) {
    x = y;
    return true;
  }
  return false;
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  vector<int> h(n);
  for (int& x : h) cin >> x;
  vector<vector<int>> graph(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  int k; cin >> k;
  vector<int> a(k);
  for (auto& x : a) cin >> x;
  sort(a.rbegin(), a.rend());
  
  static int const INF = int(1e9 + 20);
  vector<int> up(n, INF);
  vector<int> par(n, -1);
  auto dfs = [&](auto&& self, int v, int p = -1) -> void {
    par[v] = p;
    smin(up[v], h[v]);
    auto it = find(graph[v].begin(), graph[v].end(), p);
    if (it != graph[v].end()) {
      graph[v].erase(it);
    }
    for (int u : graph[v]) {
      smin(up[u], up[v]);
      self(self, u, v);
    }
  };
  dfs(dfs, 0);
  priority_queue<pair<int, int>> pq;
  pq.emplace(up[0], 0);

  int match = 0;
  while (match < k) {
    auto[d, v] = pq.top();
    if (a[match] <= d) {
      pq.pop();
      for (int u : graph[v]) {
        pq.emplace(up[u], u);
      }
      ++match;
    } else {
      break;
    }
  }

  if (match == k) {
    cout << 0 << '\n';
    return 0;
  }

  struct node {
    int mn = INF;
    int add{};

    node() = default;
    node(int x) : mn(x) {}

    node operator+(node const& other) const {
      return node{min(mn, other.mn)};
    }

    void apply(int d) {
      mn += d;
      add += d;
    }
  };

  int pw = 1;
  while (pw < k) pw *= 2;
  vector<node> tree(2 * pw);
  for (int i = 0; i < k; ++i) {
    tree[pw + i] = node(-(i + 1));
  }
  auto pull = [&](int v) {
    tree[v] = tree[2 * v] + tree[2 * v + 1];
  };
  for (int i = pw - 1; i > 0; --i) {
    pull(i);
  }
  auto push = [&](int v) {
    tree[2 * v].apply(tree[v].add);
    tree[2 * v + 1].apply(tree[v].add);
    tree[v].add = 0;
  };
  auto modify = [&](int ql, int qr, int delta) {
    auto rec = [&](auto&& self, int v, int l, int r) -> void {
      if (ql >= r || l >= qr) return;
      if (ql <= l && r <= qr) {
        tree[v].apply(delta);
        return;
      }
      int m = (l + r) / 2;
      push(v);
      self(self, 2 * v, l, m);
      self(self, 2 * v + 1, m, r);
      pull(v);
    };
    rec(rec, 1, 0, pw);
  };
  auto add = [&](int x, int d) {
    int i = int(lower_bound(a.begin(), a.end(), x, greater<>{}) - a.begin());
    modify(i, k, d);
  };
  for (int v = 0; v < n; ++v) {
    add(up[v], 1);
  }
  assert(tree[1].mn < 0);

  int ans = INT_MAX;
  int mval = a[match];

  auto nup = up;
  auto dfs2 = [&](auto&& self, int v, int d) -> void {
    add(up[v], -d);
    add(nup[v], d);
    for (int u : graph[v]) {
      nup[u] = min(nup[v], h[u]);
      self(self, u, d);
    }
  };

  while (!pq.empty()) {
    int v = pq.top().second;
    pq.pop();
    nup[v] = min(par[v] < 0 ? INF : up[par[v]], mval);
    dfs2(dfs2, v, 1);
    if (tree[1].mn >= 0) {
      smin(ans, mval - h[v]);
    }
    dfs2(dfs2, v, -1);
  }

  cout << (ans == INT_MAX ? -1 : ans) << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}