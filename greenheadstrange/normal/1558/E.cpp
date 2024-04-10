// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 4005 /*rem*/
#define mod 998244353
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

int n, m, a[maxn], b[maxn], u[maxn], v[maxn], dis[maxn];
ll power;
int cur;
bool vis[maxn];
vector<pi> e[maxn];
vi E[maxn];

ll refresh() {
  for (int i = 1; i <= n; i++) {
    E[i].clear();
    for (auto x : e[i])
      E[i].pb(x.se);
  }
  ll del = 1 << 30;
  queue<int> q;
  for (auto x : E[1])
    if (dis[x] <= power)
      q.push(x);
    else
      del = min(del, dis[x] - power);
  E[1].clear();
  while (!q.empty()) {
    int id = q.front();
    q.pop();
    if (!vis[v[id]]) {
      vis[v[id]] = 1;
      power += b[v[id]];
      del = -1;
      return del;
    }
    bool rid = false;
    for (auto x : E[v[id]]) {
      if (x == (id ^ 1)) {
        rid = true;
        continue;
      }
      if (dis[x] <= power)
        q.push(x);
      else
        del = min(del, dis[x] - power);
    }
    E[v[id]].clear();
    if (rid)
      E[v[id]].pb(id ^ 1);
  }
  return del;
}

void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    e[i].clear(), vis[i] = 0;
  for (int i = 2; i <= n; i++)
    scanf("%d", &a[i]), a[i] += 1;
  for (int i = 2; i <= n; i++)
    scanf("%d", &b[i]);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &u[2 * i], &v[2 * i]);
    u[2 * i + 1] = v[2 * i];
    v[2 * i + 1] = u[2 * i];
    e[u[2 * i]].pb(mp(v[2 * i], 2 * i));
    e[u[2 * i + 1]].pb(mp(v[2 * i + 1], 2 * i + 1));
  }
  for (int i = 0; i < 2 * m; i++)
    dis[i] = a[v[i]];
  for (int r = 0; r < 2 * m; r++) {
    for (int i = 1; i <= n; i++) {
      pi m1(1 << 30, -1), m2(1 << 30, -1);
      for (auto x : e[i]) {
        if (dis[x.se] < m2.fi)
          m2 = {dis[x.se], x.se};
        if (m2 < m1)
          swap(m2, m1);
      }
      for (auto x : e[i]) {
        int id = x.se ^ 1;
        if (m1.se == x.se)
          dis[id] = max(dis[id], m2.fi - b[i]);
        else
          dis[id] = max(dis[id], m1.fi - b[i]);
      }
      // printf("oo %d %d %d %d %d\n", i, m1.fi, m1.se, m2.fi, m2.se);
    }
  }
  // for (int i = 0; i < 2 * m; i++)
  // printf("pp %d %d %d\n", u[i], v[i], dis[i]);
  cur = 0;
  power = 0;
  while (true) {
    int del = refresh();
    if (del == (1 << 30))
      break;
    if (del > 0) {
      cur += del;
      power += del;
    }
  }
  printf("%d\n", cur);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 0; i < T; i++) {
    solve();
  }
}