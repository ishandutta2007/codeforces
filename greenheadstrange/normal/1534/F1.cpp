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

int dfn[maxn], low[maxn], ins[maxn], st[maxn], d[maxn];
int top, cnt, wtf, n, m;
vi e[maxn];
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
  auto add = [&](int a, int b, int c, int d) {
    assert(id[a][b]);
    assert(id[c][d]);
    // printf("add %d %d %d %d\n", a, b, c, d);
    e[id[a][b]].pb(id[c][d]);
  };
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (s[i][j] == '#') {
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
  }
  for (int i = 1; i <= c; i++)
    if (!dfn[i])
      tarjan(i);
  vi indeg(cnt + 1, 0);
  for (int u = 1; u <= c; u++) {
    for (auto v : e[u])
      if (d[u] != d[v]) {
        indeg[d[v]]++;
      }
  }
  int ans = 0;
  for (int u = 1; u <= cnt; u++)
    if (indeg[u] == 0)
      ans += 1;
  printf("%d\n", ans);
}