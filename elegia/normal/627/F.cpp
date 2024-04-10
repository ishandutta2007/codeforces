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

const int N = 200010;

int n;
int a[N], b[N], c[N], dep[N], prt[N], dfn[N], dfnr[N];
bool tag[N];
bool vis[N];
int xb[N], xc[N];

vector<int> g[N];

void dfs(int u) {
  static int t;
  vis[u] = true;
  dfn[u] = ++t;
  for (int v : g[u])
    if (!vis[v]) {
      dep[v] = dep[u] + 1;
      prt[v] = u;
      dfs(v);
    }
  dfnr[u] = t;
}

int lca(int u, int v) {
  while (dfn[u] > dfn[v] || dfnr[u] < dfn[v]) u = prt[u];
  return u;
}

int dist(int u, int v) {
  return dep[u] + dep[v] - dep[lca(u, v)] * 2;
}

void gg() {
  cout << "-1\n";
  exit(0);
}

int walk(int* arr, int u, int v) {
  int ret = 0;
  while (dfn[u] > dfn[v] || dfnr[u] < dfn[v]) {
    ++ret;
    swap(arr[u], arr[prt[u]]);
    u = prt[u];
  }
  while (u != v) {
    ++ret;
    for (int x : g[u])
      if (prt[x] == u && dfn[x] <= dfn[v] && dfn[v] <= dfnr[x]) {
        swap(arr[u], arr[x]);
        u = x;
        break;
      }
  }
  return ret;
}

int shiftDist(int u, int v, int p) {
  vector<int> x, y, tx, ty;
  while (u != p) {
    x.push_back(a[u]);
    y.push_back(b[u]);
    u = prt[u];
  }
  x.push_back(a[p]);
  y.push_back(b[p]);
  while (v != p) {
    tx.push_back(a[v]);
    ty.push_back(b[v]);
    v = prt[v];
  }
  reverse(tx.begin(), tx.end());
  reverse(ty.begin(), ty.end());
  x.insert(x.end(), tx.begin(), tx.end());
  y.insert(y.end(), ty.begin(), ty.end());
  x.erase(find(x.begin(), x.end(), 0));
  y.erase(find(y.begin(), y.end(), 0));
  int ret = 0;
  while (x[ret] != y[0]) ++ret;
  return ret;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  for (int rep = 1; rep < n; ++rep) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int s = find(a + 1, a + n + 1, 0) - a, t = find(b + 1, b + n + 1, 0) - b;
  copy(a + 1, a + n + 1, c + 1);
  dfs(t);
  int u = s;
  while (u != t) {
    swap(c[u], c[prt[u]]);
    u = prt[u];
  }
  if (equal(c + 1, c + n + 1, b + 1, b + n + 1)) {
    cout << "0 " << dep[s] << '\n';
    return 0;
  }
  int p = -1;
  for (int i = 1; i <= n; ++i)
    if (b[i] != c[i])
      p = (p == -1) ? prt[i] : lca(p, prt[i]);
  for (int i = 1; i <= n; ++i)
    if (b[i] != c[i]) {
      if (prt[i] != p && b[prt[i]] == c[prt[i]]) gg();
      tag[prt[i]] = true;
    }
  vector<int> leaf;
  for (int i = 1; i <= n; ++i)
    if (b[i] != c[i] && !tag[i])
      leaf.push_back(i);
  if (leaf.size() > 2) gg();
  leaf.push_back(p);
  u = leaf[0];
  int v = leaf[1];
  if (u > v) swap(u, v);
  int u1 = 0, v1 = 0;
  int tu = u, tv = v;
  while (tu != p) {
    xb[u1] = b[tu];
    xc[u1++] = c[tu];
    tu = prt[tu];
  }
  while (tv != p) {
    xb[u1 + v1] = b[tv];
    xc[u1 + v1++] = c[tv];
    tv = prt[tv];
  }
  reverse(xb + u1, xb + u1 + v1);
  reverse(xc + u1, xc + u1 + v1);
  int l = u1 + v1;
  int d = find(xb, xb + l, xc[0]) - xb;
  for (int i = 0; i < l; ++i)
    if (xc[i] != xb[(i + d) % l]) gg();
  cout << u << ' ' << v << ' ';
  ll ans = 1LL << 60;
  ll cur = 0;
  cur += walk(a, s, u);
  cur += 1; swap(a[u], a[v]);
  cur += walk(b, t, v);
  ++l;
  cur += shiftDist(v, u, p) * (ll)l;
  walk(b, v, t); swap(a[u], a[v]); walk(a, u, s);
  ans = cur;

  cur = 0;
  swap(u, v);
  cur += walk(a, s, u);
  cur += 1; swap(a[u], a[v]);
  cur += walk(b, t, v);
  cur += shiftDist(v, u, p) * (ll)l;
  ans = min(ans, cur);

  cout << ans << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}