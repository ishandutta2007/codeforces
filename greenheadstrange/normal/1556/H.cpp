// Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 55 /*rem*/
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

int n, m, k, N, deg[maxn], d[maxn][maxn], par[maxn];
vector<array<int, 3>> E, e, e2;

int findPar(int x) {
  if (par[x] == x)
    return x;
  else
    return par[x] = findPar(par[x]);
}

int matroid_intersection(int n, vector<array<int, 3>> w,
                         vector<array<int, 3>> w2) {
  // maximize
  vector<bool> used(n);
  for (auto &x : w)
    x[0] = -x[0];
  for (auto &x : w2)
    x[0] = -x[0];
  int m = w2.size();
  auto find_path = [&]() {
    vector<vector<int>> g(n + 2);
    for (int j = 0; j < n; ++j)
      if (used[j]) {
        vi cdeg(N, 0);
        used[j] = false;
        for (int i = 0; i < N; i++)
          par[i] = i;
        for (int i = 0; i < n; i++)
          if (used[i]) {
            int u = w[i][1], v = w[i][2];
            cdeg[u]++, cdeg[v]++;
            par[findPar(u)] = findPar(v);
          }
        for (int i = 0; i < m; i++) {
          int u = w2[i][1], v = w2[i][2];
          cdeg[u]++, cdeg[v]++;
          par[findPar(u)] = findPar(v);
        }

        for (int i = 0; i < n; ++i)
          if (!used[i] && i != j) {
            int u = w[i][1], v = w[i][2];
            cdeg[u] += 1;
            cdeg[v] += 1;
            bool w = true;
            for (int r = 0; r < k; r++)
              w &= cdeg[r] <= deg[r];
            cdeg[u] -= 1;
            cdeg[v] -= 1;

            if (w)
              g[i].push_back(j);
            if (findPar(u) != findPar(v))
              g[j].push_back(i);
          }
        used[j] = true;
      }
    vi cdeg(N, 0);
    for (int i = 0; i < N; i++)
      par[i] = i;
    for (int i = 0; i < n; i++)
      if (used[i]) {
        int u = w[i][1], v = w[i][2];
        cdeg[u]++, cdeg[v]++;
        par[findPar(u)] = findPar(v);
      }
    for (int i = 0; i < m; i++) {
      int u = w2[i][1], v = w2[i][2];
      cdeg[u]++, cdeg[v]++;
      par[findPar(u)] = findPar(v);
    }

    for (int i = 0; i < n; ++i)
      if (!used[i]) {
        int u = w[i][1], v = w[i][2];
        cdeg[u] += 1;
        cdeg[v] += 1;
        bool w = true;
        for (int r = 0; r < k; r++)
          w &= cdeg[r] <= deg[r];
        cdeg[u] -= 1;
        cdeg[v] -= 1;
        if (w)
          g[i].push_back(n + 1);
        if (findPar(u) != findPar(v))
          g[n].push_back(i);
      }
    /*for (int i = 0; i <= n + 1; i++) {
      for (auto x : g[i])
        printf("edge %d %d\n", i, x);
    }*/
    const int INF = 1 << 29;
    vector<int> dist(n + 2, INF);
    vector<bool> vis(n + 2);
    vector<int> pre(n + 2, -1);
    queue<int> q;
    dist[n] = 0;
    q.push(n);
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      vis[x] = false;
      for (int y : g[x]) {
        int cost = 0;
        if (y < n)
          cost = used[y] ? w[y][0] : -w[y][0];
        if (dist[y] > dist[x] + cost) {
          dist[y] = dist[x] + cost;
          pre[y] = x;
          if (!vis[y])
            vis[y] = true, q.push(y);
        }
      }
    }
    if (dist[n + 1] == INF)
      return false;
    for (int i = pre[n + 1]; i != n; i = pre[i]) {
      // printf("flip %d %d %d\n", w[i][0], w[i][1], w[i][2]);
      used[i] = !used[i];
    }
    // puts("------");
    return true;
  };
  int z = 0;
  while (find_path())
    ++z;
  int res = 0;
  for (int i = 0; i < n; ++i)
    if (used[i])
      res += w[i][0];
  for (auto x : w2)
    res += x[0], z += 1;
  if (z != N - 1)
    return -(1 << 29);
  return res;
}

int main() {
  scanf("%d%d", &n, &k);
  // n = 50;
  // k = 5;
  N = n;
  for (int i = 0; i < k; i++) {
    scanf("%d", deg + i);
    // deg[i] = rand() % 10 + 1;
  }
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      scanf("%d", &d[i][j]);
      // d[i][j] = rand() % 100 + 1;
      if (j < k) {
        e2.pb({d[i][j], i, j});
      } else if (i < k && j >= k)
        e.pb({d[i][j], i, j});
      else {
        E.pb({d[i][j], i, j});
      }
    }
  sort(E.begin(), E.end());
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
  for (auto x : E) {
    int u = x[1], v = x[2];
    if (findPar(u) != findPar(v)) {
      par[findPar(v)] = findPar(u);
      e.pb(x);
    }
  }
  int ans = 1 << 29;
  int m = e2.size();
  for (int s = 0; s < (1 << m); s++) {
    for (int i = 0; i < k; i++) {
      par[i] = i;
    }
    bool ww = true;
    vector<array<int, 3>> e3;
    int d = 0;
    for (int j = 0; j < m; j++)
      if (s & (1 << j)) {
        int u = e2[j][1], v = e2[j][2];
        if (findPar(u) == findPar(v)) {
          ww = false;
          break;
        }
        e3.pb(e2[j]);
        par[findPar(v)] = findPar(u);
      }
    if (!ww)
      continue;
    int w = -matroid_intersection(e.size(), e, e3);
    if (w >= (1 << 29))
      continue;
    ans = min(ans, w);
  }
  printf("%d\n", ans);
}