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

//  acm.math.spbu.ru/~sk1/algo/matchings/gabow5.cpp.html
struct Edmonds {
  int n, T{};
  vector<vector<int>> graph;
  vector<int> pa, p, used, base;

  vector<int> toJoin;

  explicit Edmonds(int n) : n(n), graph(n), pa(n, -1), p(n), used(n), base(n) {}

  void add_edge(int v, int u) {
    graph[v].push_back(u);
    graph[u].push_back(v);
  }

  int getBase(int i) {
    return base[i] == i ? i : base[i] = getBase(base[i]);
  }

  void mark_path(int v, int x, int b, vector<int>& path) {
    for (; getBase(v) != b; v = p[x]) {
      p[v] = x;
      x = pa[v];
      toJoin.push_back(v);
      toJoin.push_back(x);
      if (!used[x]) {
        used[x] = ++T;
        path.push_back(x);
      }
    }
  }

  bool go(int v) {
    for (int x : graph[v]) {
      int b;
      int bv = getBase(v);
      int bx = getBase(x);
      if (bv == bx) {
        continue;
      }
      if (used[x]) {
        vector<int> path;
        toJoin.clear();
        if (used[bx] < used[bv]) {
          mark_path(v, x, b = bx, path);
        } else {
          mark_path(x, v, b = bv, path);
        }
        for (int z : toJoin) {
          base[getBase(z)] = b;
        }
        for (int z : path) {
          if (go(z)) {
            return true;
          }
        }
      } else if (p[x] < 0) {
        p[x] = v;
        if (pa[x] < 0) {
          for (int y; x >= 0; x = v) {
            y = p[x];
            v = pa[y];
            pa[x] = y;
            pa[y] = x;
          }
          return true;
        }
        if (!used[pa[x]]) {
          used[pa[x]] = ++T;
          if (go(pa[x])) {
            return true;
          }
        }
      }
    }
    return false;
  }

  void init_dfs() {
    used.assign(n, 0);
    p.assign(n, -1);
    iota(base.begin(), base.end(), 0);
  }

  bool dfs(int root) {
    used[root] = ++T;
    return go(root);
  }

  int matching() {
    int ans = 0;
    init_dfs();
    for (int i = 0; i < n; ++i) {
      if (pa[i] < 0 && dfs(i)) {
        ans++;
        init_dfs();
      }
    }
    return ans;
    //  i -> pa[i]
  }
};

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x;

  vector<bool> have(n);

  for (int i = 0; i + 1 < n; ++i) {
    if (a[i] > 0 && a[i + 1] > 0 && a[i] == a[i + 1]) {
      have[a[i] - 1] = true;
    }
  }

  vector<pair<int, int>> gaps;

  for (int i = 0; i < n; ++i) {
    if (a[i] != 0) {
      continue;
    }
    int j = i;
    while (j < n && a[j] == 0) {
      ++j;
    }
    gaps.emplace_back(i - 1, j);
    i = j;
  }

  vector<int> vid(n, -1);
  int id = 0;
  for (int i = 0; i < n; ++i) {
    if (!have[i]) {
      vid[i] = id++;
    }
  }

  int ngap = int(gaps.size());
  int nvs = id + ngap + 1;
  Edmonds graph(nvs);

  auto addEdge = [&](int u, int v) {
    assert(0 <= u && u < nvs && 0 <= v && v < nvs && u != v);
    graph.add_edge(u, v);
  };

  int cid = id;
  for (auto[l, r] : gaps) {
    int len = r - l - 1;
    if (len % 2 == 0) {
      if (l >= 0 && r < n) {
        int x = vid[a[l] - 1];
        int y = vid[a[r] - 1];
        if (x >= 0 && y >= 0 && x != y) {
          addEdge(x, y);
        }
      }
    } else {
      if (l >= 0) {
        int x = vid[a[l] - 1];
        if (x >= 0) {
          addEdge(cid, x);
        }
      }
      if (r < n) {
        int y = vid[a[r] - 1];
        if (y >= 0) {
          addEdge(cid, y);
        }
      }
    }
    cid++;
  }

  graph.matching();

  cid = id;
  for (auto[l, r] : gaps) {
    int len = r - l - 1;
    if (len % 2 == 0) {
      if (l >= 0 && r < n) {
        int x = vid[a[l] - 1];
        int y = vid[a[r] - 1];
        if (x >= 0 && y >= 0 && x != y) {
          if (!have[a[l] - 1] && !have[a[r] - 1]) {
            int mt = graph.pa[x];
            if (mt == y) {
              a[l + 1] = a[l];
              a[r - 1] = a[r];
              have[a[l] - 1] = true;
              have[a[r] - 1] = true;
            }
          }
        }
      }
    } else {
      if (l >= 0) {
        int x = vid[a[l] - 1];
        if (x >= 0) {
          int mt = graph.pa[cid];
          if (mt == x && !have[a[l] - 1]) {
            a[l + 1] = a[l];
            have[a[l] - 1] = true;
          }
        }
      }
      if (r < n) {
        int y = vid[a[r] - 1];
        if (y >= 0) {
          int mt = graph.pa[cid];
          if (mt == y && !have[a[r] - 1]) {
            a[r - 1] = a[r];
            have[a[r] - 1] = true;
          }
        }
      }
    }
    cid++;
  }

  int ptr = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != 0) {
      continue;
    }
    int j = i;
    while (j < n && a[j] == 0) {
      ++j;
    }
    int len = j - i;
    int fr = i;
    if (len % 2 == 1) {
      a[fr++] = 1;
    }
    for (int cur = fr; cur < j; cur += 2) {
      while (ptr < n && have[ptr]) {
        ++ptr;
      }
      if (ptr == n) {
        a[cur] = a[cur + 1] = 1;
      } else {
        a[cur] = a[cur + 1] = ptr + 1;
        have[ptr] = true;
      }
    }
    i = j;
  }

  for (auto x : a) cout << x << ' ';
  cout << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}