#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 0x3f3f3f3f;
const int ms = 1e5 + 5;
const int mod = 1e9+7;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using ll = long long;
vector<int> g[ms], dis[ms];
int par[ms], sz[ms], rem[ms], h[ms];

void dfsSubtree(int u, int p) {
  sz[u] = 1;
  for(auto v : g[u]) {
    if(v != p && !rem[v]) {
      dfsSubtree(v, u);
      sz[u] += sz[v];
    }
  }
}

int getCentroid(int u, int p, int size) {
  for(auto v : g[u]) {
    if(v != p && !rem[v] && sz[v] * 2 >= size) 
      return getCentroid(v, u, size);
  }
  return u;
}

void setDis(int u, int p, int nv){
  for (auto v : g[u]) {
    if (v == p || rem[v]) continue;
    dis[v][nv] = dis[u][nv]+1;
    setDis(v, u, nv);
  }
}

void decompose(int u, int p = -1, int nv = 0) {
  dfsSubtree(u, -1);
  int ctr = getCentroid(u, -1, sz[u]);
  par[ctr] = p;
  // cout << ctr << " -> " << nv << endl; 
  h[ctr] = nv; 
  rem[ctr] = 1;
  setDis(ctr, p, nv);
  for(auto v : g[ctr]) {
    if(v != p && !rem[v]) {
      decompose(v, ctr, nv+1);
    }
  }
}

int ans[ms];

void solve() {
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++) dis[i].resize(30);
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  decompose(0);
  memset(ans, 0x3f, sizeof ans);
  {
      int u = 0;
      while(u != -1) {
        // cout << u << " " << h[u] << endl;
        ans[u] = min(ans[u], dis[0][h[u]]);
        u = par[u];
      }
  }
  while(m--) {
    int t, v;
    cin >> t >> v;
    v--;
    if(t == 1) {
      int u = v;
      while(u != -1) {
        // cout << u << " " << h[u] << endl;
        ans[u] = min(ans[u], dis[v][h[u]]);
        u = par[u];
      }
    } else {
      int u = v;
      int trueAns = inf;
      while(u != -1) {
        // cout << u << " " << h[u] << endl;
        trueAns = min(trueAns, ans[u] + dis[v][h[u]]);
        u = par[u];
      }
      cout << trueAns << '\n';
    }
  }
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  while (t--) {
    solve(); 
  }
  return 0;
}