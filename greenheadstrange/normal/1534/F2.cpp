// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {
  return x < y ? x = y, true : false;
}
template <typename T> bool chkmin(T &x, T y) {
  return x > y ? x = y, true : false;
}

using namespace std;

ll ksm(ll a, ll b) {
  if (!b)
    return 1;
  ll ns = ksm(a, b >> 1);
  ns = ns * ns % mod;
  if (b & 1)
    ns = ns * a % mod;
  return ns;
}

char t[maxn];
string s[maxn];

int dfn[maxn], low[maxn], ins[maxn], st[maxn], d[maxn], a[maxn], ord[maxn],
    L[maxn], R[maxn];
int top, cnt, wtf, n, m;
vi e[maxn], r[maxn];
void tarjan(int u) {
  dfn[u] = low[u] = ++wtf;
  ins[u] = 1;
  st[++top] = u;
  for (int v : e[u]) {
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (ins[v]) {
      low[u] = min(low[u], low[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++cnt;
    while (1) {
      d[st[top]] = cnt;
      ins[st[top]] = 0;
      if (st[top--] == u)
        break;
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  vector<vi> id(n, vi(m, 0));
  int c = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", t);
    s[i] = t;
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '#')
        id[i][j] = ++c;
    }
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
  }
  auto add = [&](int a, int b, int c, int d) {
    assert(id[a][b]);
    assert(id[c][d]);
    e[id[a][b]].pb(id[c][d]);
  };
  vi q;
  for (int j = 0; j < m; j++) {
    vi c;
    for (int i = 0; i < n; i++) {
      if (s[i][j] == '#') {
        c.pb(id[i][j]);
        if (i >= 1 && s[i - 1][j] == '#')
          add(i, j, i - 1, j);
        for (int k = i; k < n; k++) {
          if (j > 0 && s[k][j - 1] == '#')
            add(i, j, k, j - 1);
          if (j + 1 < m && s[k][j + 1] == '#')
            add(i, j, k, j + 1);
          if (k != i && s[k][j] == '#') {
            add(i, j, k, j);
            break;
          }
        }
      }
    }
    if (a[j]) {
      reverse(c.begin(), c.end());
      q.pb(c[a[j] - 1]);
    }
  }
  for (int i = 1; i <= c; i++)
    if (!dfn[i])
      tarjan(i);
  vi indeg(cnt + 1, 0);
  for (int u = 1; u <= c; u++) {
    for (auto v : e[u])
      if (d[u] != d[v]) {
        indeg[d[v]]++;
        assert(d[v] <= d[u]);
        r[d[v]].pb(d[u]);
      }
  }
  int c2 = 0;
  for (int j = 0; j < m; j++)
    for (int i = 0; i < n; i++)
      if (id[i][j] && indeg[d[id[i][j]]] == 0) {
        int o = d[id[i][j]];
        if (ord[o] == 0)
          ord[o] = ++c2;
      }
  for (int i = cnt; i >= 1; i--) {
    if (ord[i]) {
      L[i] = R[i] = ord[i];
    } else {
      L[i] = c2 + 1;
      R[i] = 0;
      for (auto v : r[i]) {
        L[i] = min(L[i], L[v]);
        R[i] = max(R[i], R[v]);
      }
    }
  }
  vector<pi> seg;
  for (auto x : q) {
    seg.push_back({L[d[x]], R[d[x]]});
  }
  sort(seg.begin(), seg.end(), [&](pi a, pi b) { return a.se < b.se; });
  int segr = -1, ans = 0;
  for (auto p : seg) {
    if (p.fi <= segr)
      continue;
    ans += 1;
    segr = p.se;
  }
  printf("%d\n", ans);
}