#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;
typedef vector <pil> vpil;
typedef vector <vpil> vvpil;
typedef vector <int> vi;

const ll INF = 1e18;

vvpil g;
vi leftkid, rightkid;

int builda(int tl, int tr, int val) {
  if (tl == tr)
    return tl;
  int tm = (tl + tr) / 2;
  int l = builda(tl, tm, val);
  int r = builda(tm + 1, tr, max(l + 1, val));
  int v = max({l + 1, r + 1, val});
  leftkid[v] = l, rightkid[v] = r;
  g[v].push_back({l, 0});
  g[v].push_back({r, 0});
  return v;
}

void upda(int v, int tl, int tr, int l, int r, int u, int w) {
  if (l > r)
    return;
  if (l == tl && r == tr) {
    g[u].push_back({v, w});
    return;
  }
  int tm = (tl + tr) / 2;
  upda(leftkid[v], tl, tm, l, min(r, tm), u, w);
  upda(rightkid[v], tm + 1, tr, max(l, tm + 1), r, u, w);
}

int buildb(int tl, int tr, int val) {
  if (tl == tr)
    return tl;
  int tm = (tl + tr) / 2;
  int l = buildb(tl, tm, val);
  int r = buildb(tm + 1, tr, max(l + 1, val));
  int v = max({l + 1, r + 1, val});
  leftkid[v] = l, rightkid[v] = r;
  g[l].push_back({v, 0});
  g[r].push_back({v, 0});
  return v;
}

void updb(int v, int tl, int tr, int l, int r, int u, int w) {
  if (l > r)
    return;
  if (l == tl && r == tr) {
    g[v].push_back({u, w});
    return;
  }
  int tm = (tl + tr) / 2;
  updb(leftkid[v], tl, tm, l, min(r, tm), u, w);
  updb(rightkid[v], tm + 1, tr, max(l, tm + 1), r, u, w);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, st;
  cin >> n >> m >> st;
  st--;
  g.resize(9 * n), leftkid.resize(9 * n), rightkid.resize(9 * n);
  int roota = builda(0, n - 1, n);
  int rootb = buildb(0, n - 1, roota + 1);
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int v, u, w;
      cin >> v >> u >> w;
      u--, v--;
      g[v].push_back({u, w});
    }
    if (t == 2) {
      int v, l, r, w;
      cin >> v >> l >> r >> w;
      l--, r--;
      v--;
      upda(roota, 0, n - 1, l, r, v, w);
    }
    if (t == 3) {
      int v, l, r, w;
      cin >> v >> l >> r >> w;
      v--;
      l--, r--;
      updb(rootb, 0, n - 1, l, r, v, w);
    }
  }
  vector <ll> d(rootb + 1, INF);
  d[st] = 0;
  set <pli> s;
  for (int i = 0; i <= rootb; i++)
    s.insert({d[i], i});
  while (!s.empty()) {
    int v = s.begin()->second;
    s.erase(s.begin());
    for (pil now : g[v]) {
      int u = now.fi, w = now.se;
      if (d[v] + w < d[u]) {
        s.erase({d[u], u});
        d[u] = d[v] + w;
        s.insert({d[u], u});
      }
    }
  }
  for (int i = 0; i <= rootb; i++)
    if (d[i] == INF)
      d[i] = -1;
  for (int i = 0; i < n; i++)
    cout << d[i] << ' ';
  return 0;
}