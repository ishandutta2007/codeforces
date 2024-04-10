//#pragma GCC optimize("O3")
//#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define FILENAME sadcactussociety

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;
const ld EPS = 1e-9;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3e5 + 1;
const int M = 3e5 + 1;

namespace BCC {
  int vcompNum,ecompNum,I,m;
  int first[N],low[N],vis[N],ecomp[N];
  int nxt[2*M],ep[2*M],vcomp[2*M];
  stack<int> edges, verts;
  void init() { m = 0; memset(first, -1, sizeof(first)); }
  void add_edge(int a, int b) {
      nxt[m] = first[ep[m] = a]; first[ep[m]] = m; ++m;
      nxt[m] = first[ep[m] = b]; first[ep[m]] = m; ++m; }
  void biconnected(int u, int par){ int v,E; low[u] = vis[u] = ++I;
    verts.push(u); for (int e=first[u]; e!=-1; e=nxt[e]) { v = ep[e^1];
      if (!vis[v]) { edges.push(e); biconnected(v,e);
        low[u] = min(low[u],low[v]);
        if (vis[u] <= low[v]) {
          // u is a cut vertex unless it's a one-child root
          do { E=edges.top(); edges.pop(); vcomp[E]=vcomp[E^1]=vcompNum; }
          while (e != E && e != (E^1)); ++vcompNum; }}
      else if (vis[v] < vis[u] && e != (par^1)) {
        low[u] = min(low[u], vis[v]); edges.push(e); }
      else if (v == u) vcomp[e]=vcomp[e^1]=vcompNum++; } // e is self-loop
    if (vis[u] <= low[u]) { // par is a cut edge unless par==-1
      do { v = verts.top(); verts.pop(); ecomp[v] = ecompNum; }
      while (v != u); ++ecompNum; }
  }
  void get_bcc(int n) { memset(vis,0,sizeof vis); vcompNum=ecompNum=I=1;
    for (int i=1; i<=n; ++i) if (!vis[i]) biconnected(i, -1);
  }
  // tree-independent criteria for identifying cut vertices and bridges
  bool isCutVertex(int u) { for (int e = first[u]; e != -1; e = nxt[e]) {
    if (vcomp[e] != vcomp[first[u]]) return true; } return false; }
  bool isCutEdge(int e) { return ecomp[ep[e]] != ecomp[ep[e^1]]; }
}

int invalue[N], incost[N], inspecial[N];
ll value[N], cost[N], special[N];
vector<int> adj[N];
int par[N];

int build(int u, int p) {
  auto it = find(adj[u].begin(), adj[u].end(), p);
  if(it != adj[u].end()) adj[u].erase(it);
  par[u] = p;
  for(int v : adj[u]) {
    special[u] += build(v, u);
  }
  return special[u];
}

ll dp[N], up[N];

void solve_down(int u) {
  dp[u] = value[u];
  for(int v : adj[u]) {
    solve_down(v);
    if(special[v] == 0 || special[v] == special[1]) {
      dp[u] += dp[v];
    } else {
      dp[u] += max((ll)0, dp[v] - cost[v]);
    }
  }
}

void solve_up(int u) {
  int p = par[u];
  if(p) {
    up[u] = dp[p];
    if(special[u] == 0 || special[u] == special[1]) {
      up[u] -= dp[u];
    } else {
      up[u] -= max((ll)0, dp[u] - cost[u]);
    }
    if(special[p] == 0 || special[p] == special[1]) {
      up[u] += up[p];
    } else {
      up[u] += max((ll)0, up[p] - cost[p]);
    }
  }
  for(int v : adj[u]) {
    solve_up(v);
  }
}

// double-check correctness
// read limits carefully
// characterize valid solutions
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed << setprecision(10);
/*
#ifdef ONLINE_JUDGE
  freopen(FILENAME ".in", "r", stdin);
  freopen(FILENAME ".out", "w", stdout);
#endif
*/

  int n, m, k;
  cin >> n >> m >> k;

  for(int i=0; i<k; i++) {
    int v;
    cin >> v;
    inspecial[v] = 1;
  }

  for(int i=1; i<=n; i++) {
    cin >> invalue[i];
  }

  for(int i=0; i<m; i++) {
    cin >> incost[i];
  }

  BCC::init();
  vector<int> a(m), b(m);
  for(int i=0; i<m; i++) {
    cin >> a[i] >> b[i];
    BCC::add_edge(a[i], b[i]);
  }
  BCC::get_bcc(n);

  for(int i=0; i<m; i++) {
    int u = BCC::ecomp[a[i]];
    int v = BCC::ecomp[b[i]];
    if(u != v) {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  for(int i=1; i<BCC::ecompNum; i++) {
    sort(adj[i].begin(), adj[i].end());
    adj[i].resize(unique(adj[i].begin(), adj[i].end()) - adj[i].begin());
    cost[i] = INF;
  }

  for(int i=1; i<=n; i++) {
    int u = BCC::ecomp[i];
    value[u] += invalue[i];
    special[u] += inspecial[i];
  }

  build(1, 0);

  for(int i=0; i<m; i++) {
    int u = BCC::ecomp[a[i]];
    int v = BCC::ecomp[b[i]];
    if(u == v) continue;
    if(v == par[u]) swap(u, v);
    cost[v] = min(cost[v], (ll)incost[i]);
  }

  solve_down(1);
  solve_up(1);

  for(int i=1; i<=n; i++) {
    int u = BCC::ecomp[i];
    if(special[u] == 0 || special[u] == special[1]) {
      cout << dp[u] + up[u] << " ";
    } else {
      cout << max(dp[u], dp[u] + up[u] - cost[u]) << " ";
    }
  }
  cout << nl;

  return 0;
}