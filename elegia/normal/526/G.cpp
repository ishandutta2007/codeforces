#include <cstdio>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <tuple>
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

const int N = 100010, L = 17;

int n, ns, nt, cnt;
int dist[N], ds[N], dt[N], ts[N], tt[N];
pair<int, int> cs[N], ct[N], c[N], de[N], des[N], det[N];
int ss[N], st[N];
bool vis[N];
vector<pair<int, int>> g[N];
int prs[N][L], prt[N][L];

bool tag;

void dfs(int u) {
  vis[u] = true;
  for (const auto& pr : g[u]) {
    int v, w;
    tie(v, w) = pr;
    if (!vis[v]) {
      dist[v] = dist[u] + w;
      dfs(v);
    }
  }
}

pair<int, int> decomp(int u) {
  if (tag)
    for (int i = 1; i < L; ++i) prt[u][i] = prt[prt[u][i - 1]][i - 1];
  else
    for (int i = 1; i < L; ++i) prs[u][i] = prs[prs[u][i - 1]][i - 1];
  pair<int, int> ret(0, u);
  vis[u] = true;
  for (const auto& pr : g[u]) {
    int v, w;
    tie(v, w) = pr;
    if (!vis[v]) {
      if (tag) prt[v][0] = u;
      else prs[v][0] = u;
      dist[v] = dist[u] + w;
      auto cur = decomp(v);
      cur.first += w;
      if (cur > ret) {
        if (ret.first) c[++cnt] = ret;
        ret = cur;
      } else
        c[++cnt] = cur;
    }
  }
  return de[u] = ret;
}

int s, t;

int query(int x, int y) {
//  cerr << x << ' ' << y << ' ' << ds[x] << ' ' << dt[x] << '\n';
  if (ds[x] > dt[x]) {
    //cerr << "start " << s << '\n';
    if (y >= ns) return ss[ns];
    if (ts[x] <= y) return ss[y];
    int ret = ss[y] + ds[x] + des[x].first;
    for (int i = L - 1; i >= 0; --i)
      if (ts[prs[x][i]] > y) x = prs[x][i];
    x = prs[x][0];
    return ret - ds[x] - min(des[x].first, cs[y].first);
  }
//    cerr << "start " << t << '\n';
  if (y >= nt) return st[nt];
  if (tt[x] <= y) return st[y];
  int ret = st[y] + dt[x] + det[x].first;
  for (int i = L - 1; i >= 0; --i)
    if (tt[prt[x][i]] > y) x = prt[x][i];
  x = prs[x][0];
  return ret - dt[x] - min(det[x].first, ct[y].first);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> n >> q;
  for (int rep = 1; rep < n; ++rep) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  dfs(1);
  s = max_element(dist + 1, dist + n + 1) - dist;

  memset(vis, 0, sizeof(vis));
  dist[s] = 0;
  auto diam = decomp(s);
  t = diam.second;
  c[++cnt] = diam;
  sort(c + 1, c + cnt + 1, greater<pair<int, int>>());
  copy(c + 1, c + cnt + 1, cs + 1);
  copy(dist + 1, dist + n + 1, ds + 1);
  copy(de + 1, de + n + 1, des + 1);
  ns = cnt;

  cnt = 0;
  memset(vis, 0, sizeof(vis));
  dist[t] = 0;
  tag = true;
  diam = decomp(t);
  c[++cnt] = diam;
  sort(c + 1, c + cnt + 1, greater<pair<int, int>>());
  copy(c + 1, c + cnt + 1, ct + 1);
  copy(dist + 1, dist + n + 1, dt + 1);
  copy(de + 1, de + n + 1, det + 1);
  nt = cnt;

  for (int i = 1; i <= ns; ++i) ss[i] = ss[i - 1] + cs[i].first;
  for (int i = 1; i <= nt; ++i) st[i] = st[i - 1] + ct[i].first;

  fill(ts + 1, ts + n + 1, -1);
  ts[s] = 0;
  for (int i = 1; i <= ns; ++i) {
    int u = cs[i].second;
    while (ts[u] == -1) {
      ts[u] = i;
      u = prs[u][0];
    }
  }
  fill(tt + 1, tt + n + 1, -1);
  tt[t] = 0;
  for (int i = 1; i <= nt; ++i) {
    int u = ct[i].second;
    while (tt[u] == -1) {
      tt[u] = i;
      u = prt[u][0];
    }
  }

/*  cerr << s << ": ";
  for (int i = 1; i <= ns; ++i) cerr << cs[i].first << ' ' << cs[i].second << ", ";
  cerr << '\n';

  cerr << t << ": ";
  for (int i = 1; i <= nt; ++i) cerr << ct[i].first << ' ' << ct[i].second << ", ";
  cerr << '\n';*/

  int ans = 0;
  while (q--) {
    int x, y;
    cin >> x >> y;
    x = (x + ans - 1) % n + 1;
    y = (y + ans - 1) % n + 1;
    cout << (ans = query(x, y * 2 - 1)) << '\n';
  }

  return 0;
}