//  Copyright 2022 Nikita Golikov

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

struct DSU {
  int n;
  vector<int> dsu;

  DSU(int n_) : n(n_), dsu(n, -1) {}

  int find(int v) {
    return dsu[v] < 0 ? v : dsu[v] = find(dsu[v]);
  }

  bool unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (-dsu[u] > -dsu[v]) swap(u, v);
    dsu[v] += dsu[u];
    dsu[u] = v;
    return true;
  }

  bool same(int u, int v) {
    return find(u) == find(v);
  }

  int size(int v) {
    return -dsu[find(v)];
  }

  void clear() {
    fill(dsu.begin(), dsu.end(), -1);
  }
};

//  adj - vector of adjacency masks
int min_colors(vector<int> adj) {
  static int const MD = int(1e9) + 7;
  int n = int(adj.size());
  if (n == 0) {
    return 0;
  }

  vector<int> ind(1 << n);
  vector<int> sgn(1 << n);
  ind[0] = 1;
  for (int bit = 0, msk = 1; msk < (1 << n); ++msk) {
    if (msk >> (bit + 1) & 1) {
      ++bit;
    }
    ind[msk] = ind[msk ^ (1 << bit)] + ind[msk & ~(adj[bit] | (1 << bit))];
    sgn[msk] = __builtin_parity(msk);
  }

  vector<int> pwr((1 << n) + 1, 1);

  for (int c = 1; c <= n; ++c) {
    for (int i = 0; i <= (1 << n); ++i) {
      pwr[i] = ll(pwr[i]) * i % MD;
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
      int v = pwr[ind[i]];
      if (sgn[i]) {
        ans += v;
        if (ans >= MD) {
          ans -= MD;
        }
      } else {
        ans -= v;
        if (ans < 0) {
          ans += MD;
        }
      }
    }

    if (ans != 0) {
      return c;
    }
  }

  assert(false);
}

int main() {
#ifdef GOLIKOV
  assert(freopen("in", "rt", stdin));
  auto _clock_start = chrono::high_resolution_clock::now();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<string> a(n);
  for (auto& s : a) {
    cin >> s;
  }

  DSU dsu(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] == 'A') {
        dsu.unite(i, j);
      }
    }
  }

  int cc = 0;
  int ones = 0;
  vector<int> no;
  vector<vector<int>> comps;
  for (int i = 0; i < n; ++i) {
    if (dsu.find(i) != i) {
      continue;
    }
    ++cc;
    int sz = dsu.size(i);
    if (sz == 1) {
      ++ones;
      continue;
    }
    no.push_back(i);
    vector<int> here;
    for (int j = 0; j < n; ++j) {
      if (dsu.find(j) == i) {
        here.push_back(j);
      }
    }
    comps.push_back(here);
    for (int x : here) {
      for (int y : here) {
        if (a[x][y] == 'X') {
          cout << -1 << '\n';
          return 0;
        }
      }
    }
  }

  int sz = int(no.size());
  assert(sz <= 23);
  vector<int> adj(sz);
  for (int i = 0; i < sz; ++i) {
    for (int j = 0; j < sz; ++j) {
      if (i == j) {
        continue;
      }
      auto& ci = comps[i];
      auto& cj = comps[j];
      bool bad = false;
      for (int x : ci) {
        for (int y : cj) {
          if (a[x][y] == 'X') {
            bad = true;
          }
        }
      }
      adj[i] |= int(bad) << j;
    }
  }

  cout << cc - 1 + (n - ones) - (sz - min_colors(adj)) << '\n';

#ifdef GOLIKOV
  cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
      chrono::high_resolution_clock::now()
          - _clock_start).count() << "ms." << endl;
#endif
  return 0;
}