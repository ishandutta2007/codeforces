#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;
using ull = uint64_t;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using i4 = tuple<int, int, int, int>;
using ll = long long;
const int mod = 1e9+7;
const int ms = 1e5; // vertices
const int me = 1e6; // arestas
const double eps = 1e-7;
int adj[ms], to[me], ant[me], wt[me], z;
int copy_adj[ms], fila[ms], level[ms];
void clear() { // Lembrar de chamar no main
  memset(adj, -1, sizeof adj);
  z = 0;
}
void add(int u, int v, int k) {
  to[z] = v;
  ant[z] = adj[u];
  wt[z] = k;
  adj[u] = z++;
  swap(u, v);
  to[z] = v;
  ant[z] = adj[u];
  wt[z] = 0; // Lembrar de colocar = 0
  adj[u] = z++;
}
int bfs(int source, int sink) {
  memset(level, -1, sizeof level);
  level[source] = 0;
  int front = 0, size = 0, v;
  fila[size++] = source;
  while(front < size) {
    v = fila[front++];
    for(int i = adj[v]; i != -1; i = ant[i]) {
      if(wt[i] && level[to[i]] == -1) {
        level[to[i]] = level[v] + 1;
        fila[size++] = to[i];
      }
    }
  }
  return level[sink] != -1;
}
int dfs(int v, int sink, int flow) {
  if(v == sink) return flow;
  int f;
  for(int &i = copy_adj[v]; i != -1; i = ant[i]) {
    if(wt[i] && level[to[i]] == level[v] + 1 && 
      (f = dfs(to[i], sink, min(flow, wt[i])))) {
      wt[i] -= f;
      wt[i ^ 1] += f;
      return f;
    }
  }
  return 0;
}
int maxflow(int source, int sink) {
  int ret = 0, flow;
  while(bfs(source, sink)) {
    memcpy(copy_adj, adj, sizeof adj);
    while((flow = dfs(source, sink, 1 << 30))) {
      ret += flow;
    }
  }
  return ret;
}

map<ii, int> idx;
int a[ms];
bool islft[ms];
vector<int> v[ms];

void solve() {
  clear();
  int src = 0, snk = 1;
  int k = 2;
  int n, m;
  cin >> n >> m;
  // int ans = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    islft[i] = i % 2 == 0;
    for(int j = 2; j*j <= a[i]; j++) {
      int q = 0;
      while(a[i] % j == 0) {
        q++;
        a[i] /= j;
      }
      if(q) {
        int id = idx[ii(i, j)] = k++;
        if(islft[i]) add(src, id, q);
        else add(id, snk, q);
        if(islft[i]) v[i].emplace_back(j);
      }
    }
    if(a[i] > 1) {

        int id = idx[ii(i, a[i])] = k++;
        if(islft[i]) add(src, id, 1);
        else add(id, snk, 1);
        if(islft[i]) v[i].emplace_back(a[i]);
    }
  }
  while(m--) {
    int i, j;
    cin >> i >> j;
    if(!islft[i]) swap(i, j);
    for(int p : v[i]) {
      if(idx.count({j, p})) {
        add(idx[{i, p}], idx[{j, p}], inf);
      }
    }
  }
  cout << maxflow(src, snk) << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(3);
   #ifdef ONLINE_JUDGE
    // freopen("boysgirls.in", "r", stdin);
    // freopen("boysgirls.out", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;
  int T = 0;
  while (t--) {
    T++;
    // cout << "Case " << T << ": ";
    solve(); 
  }
  return 0;
}