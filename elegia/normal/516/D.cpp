#include <bits/stdc++.h>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

ostream& operator<<(ostream& os, const pair<char, int>& unit) {
  return os << unit.first << "^" << unit.second;
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

const int N = 100010;

int n;
int sz[N], f[N], rk[N];
bool vis[N];
ll d1[N], d2[N];
pair<ll, int> a[N];
vector<pair<int, int>> g[N];

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void unite(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return;
  if (rk[x] > rk[y]) swap(x, y);
  if (rk[x] == rk[y]) ++rk[y];
  f[x] = y;
  sz[y] += sz[x];
}

ll* dp;
void dfs(int u) {
  vis[u] = true;
  for (const auto& pr : g[u]) {
    int v, w;
    tie(v, w) = pr;
    if (!vis[v]) {
      dp[v] = dp[u] + w;
      dfs(v);
    }
  }
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int rep = 1; rep < n; ++rep) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
  dp = d1;
  dfs(1);
  int diamU = max_element(d1 + 1, d1 + n + 1) - d1;
  memset(vis, 0, sizeof(vis));
  d1[diamU] = 0;
  dfs(diamU);
  int diamV = max_element(d1 + 1, d1 + n + 1) - d1;
  dp = d2;
  memset(vis, 0, sizeof(vis));
  dfs(diamV);
  for (int i = 1; i <= n; ++i)
    a[i] = make_pair(max(d1[i], d2[i]), i);
  sort(a + 1, a + n + 1, greater<pair<ll, int>>());
  int q;
  cin >> q;
  while (q--) {
    ll l;
    cin >> l;
    int ans = 0, p = 0;
    memset(f, 0, sizeof(f));
    memset(sz, 0, sizeof(sz));
    memset(rk, 0, sizeof(rk));
    for (int rep = 1; rep <= n; ++rep) {
      int i = a[rep].second;
      while (a[rep].first - a[p + 1].first < -l)
        --sz[find(a[++p].second)];
      sz[i] = 1;
      f[i] = i;
      for (const auto& pr : g[i]) {
        int j;
        tie(j, ignore) = pr;
        if (f[j])
          unite(i, j);
      }
      ans = max(ans, sz[find(i)]);
    }
    cout << ans << '\n';
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
      -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}