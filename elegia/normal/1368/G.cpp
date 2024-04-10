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

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
  for (T &x : v)
    is >> x;
  return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

namespace Rect {

  const int N = 100010;

  int n, m;

  namespace SegT {

    struct Node {
      int cov, area;
    } P[N << 2];

    void update(int o, int l, int r) {
      if (P[o].cov) P[o].area = r - l + 1;
      else if (l == r) P[o].area = 0;
      else P[o].area = P[o << 1].area + P[o << 1 | 1].area;
    }

    void modify(int o, int l, int r, int ql, int qr, int x) {
      if (l == ql && r == qr) {
        P[o].cov += x;
      } else {
        int mid = (l + r) >> 1;
        if (qr <= mid)
          modify(o << 1, l, mid, ql, qr, x);
        else if (ql > mid)
          modify(o << 1 | 1, mid + 1, r, ql, qr, x);
        else {
          modify(o << 1, l, mid, ql, mid, x);
          modify(o << 1 | 1, mid + 1, r, mid + 1, qr, x);
        }
      }
      update(o, l, r);
    }

  }

  vector<tuple<int, int, int>> modify[N];

  void cover(int x1, int x2, int y1, int y2) {
    modify[x1].emplace_back(y1, y2, 1);
    modify[x2 + 1].emplace_back(y1, y2, -1);
  }

  ll solve() {
    ll ret = 0;
    for (int i = 1; i <= n; ++i) {
      for (const auto&[l, r, x] : modify[i])
        SegT::modify(1, 1, m, l, r, x);
      ret += SegT::P[1].area;
    }
    return ret;
  }

}

int main() {
#ifdef ELEGIA
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  cin >> grid;

  auto label = [&](int x, int y) {
    return x * m + y;
  };
  vector<int> match(n * m);
  vector<vector<int>> g(n * m);
  vector<int> deg(n * m);

  auto apply = [&](int x1, int y1, int x2, int y2) {
    if (x1 >= 0 && x1 < n && x2 >= 0 && x2 < n
        && y1 >= 0 && y1 < m && y2 >= 0 && y2 < m) {
      ++deg[label(x2, y2)];
      g[label(x1, y1)].push_back(label(x2, y2));
    }
  };

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == 'U') {
        match[label(i, j)] = label(i + 1, j);
        apply(i - 1, j, i + 1, j);
        apply(i + 2, j, i, j);
      }
      if (grid[i][j] == 'D')
        match[label(i, j)] = label(i - 1, j);
      if (grid[i][j] == 'L') {
        match[label(i, j)] = label(i, j + 1);
        apply(i, j - 1, i, j + 1);
        apply(i, j + 2, i, j);
      }
      if (grid[i][j] == 'R')
        match[label(i, j)] = label(i, j - 1);
    }

  int t = 0;

  vector<int> dfn(n * m), dfnr(n * m);

  function<void(int)> dfs = [&](int u) {
    dfn[u] = ++t;
    for (int v : g[u])
      dfs(v);
    dfnr[u] = t;
  };

  for (int i = 0; i < n; ++i)
    for (int j = i & 1; j < m; j += 2)
      if (!deg[label(i, j)])
        dfs(label(i, j));
  Rect::n = t;

  t = 0;
  for (int i = 0; i < n; ++i)
    for (int j = (i & 1) ^1; j < m; j += 2)
      if (!deg[label(i, j)])
        dfs(label(i, j));
  Rect::m = t;

  for (int i = 0; i < n; ++i)
    for (int j = i & 1; j < m; j += 2) {
      int u = label(i, j), v = match[u];
      Rect::cover(dfn[u], dfnr[u], dfn[v], dfnr[v]);
    }
  cout << Rect::solve() << '\n';

#ifdef ELEGIA
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}