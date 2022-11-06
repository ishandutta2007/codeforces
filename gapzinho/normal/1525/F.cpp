#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define double long dopuble

 typedef pair<int, int> ii;
typedef long long ll;

const int ms = 200; // Quantidade maxima de vertices
const int me = 3000; // Quantidade maxima de arestas

int adj[ms], to[me], ant[me], wt[me], z;
int copy_adj[ms], fila[ms], level[ms];
int copyWt[me];

void clear() { 
  memset(adj, -1, sizeof adj);
  z = 0;
}

void add(int u, int v, int k = 1) {
  to[z] = v;
  ant[z] = adj[u];
  copyWt[z] = k;
  adj[u] = z++;
  swap(u, v);
  to[z] = v;
  ant[z] = adj[u];
  copyWt[z] = 0; 
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
  memcpy(wt, copyWt, sizeof wt);
  while(bfs(source, sink)) {
    memcpy(copy_adj, adj, sizeof adj);
    while((flow = dfs(source, sink, 1 << 30))) {
      ret += flow;
    }
  }
  return ret;
}

ll x[ms], y[ms];
ll dp[ms][ms];
ll transicao[ms][ms];
ll willNeed[ms];
stack<int> canBlock;
int mf;

void recover(int a, int b) {
    if(a == 0) return;
    willNeed[a] = transicao[a][b];
    recover(a-1, b-transicao[a][b]+(a >= mf));
}
int n, m, k;
pair<int, int> ed[me];
int src, snk;
int lastMf;


int getAnAnswer() {
    for(int i = adj[src]; i != -1; i = ant[i]) {
        if(copyWt[i] != 0) {
            copyWt[i] = 0;
            if(maxflow(src, snk) != lastMf) {
                lastMf--;
                return to[i];
            }
            copyWt[i] = 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        int e = adj[i+n];
        if(copyWt[e] != 0) {
            copyWt[e] = 0;
            if(maxflow(src, snk) != lastMf) {
                lastMf--;
                return -i;
            }
            copyWt[e] = 1;
        }
    }
    return -1;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    clear();
    cin >> n >> m >> k;
    src = 2*n+10;
    snk = 2*n+12;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        ed[i] = {u, v};
        add(u, v+n);
    }
    for(int i = 1; i <= n; i++) {
        add(i+n, snk);
        add(src, i);
    }
    lastMf = maxflow(src, snk);
    mf = n - lastMf;
    int ans = 0;
    for(int i = 1; i <= k; i++) {
        cin >> x[i] >> y[i];
        ans += x[i];
    }
    for(int i = 1; i <= n; i++) {
        dp[0][i] = 0x3f3f3f3f;
    }
    for(int i = 1; i <= k; i++) {
        for(int j = n; j >= 0; j--) {
            int need = j + (i >= mf);
            dp[i][j] = dp[i-1][need];
            transicao[i][j] = 0;
            for(int h = need; h > 0; h--) {
                int temp = dp[i-1][need-h] + x[i] - max(0ll, x[i] - y[i]*h);
                if(temp < dp[i][j]) {
                    dp[i][j] = temp;
                    transicao[i][j] = h;
                }
            }
        }
    }
    
    // cout << ans - dp[k][0] << endl;
    recover(k, 0);
    vector<int> vans;
    for(int i = 1; i <= k; i++) {
        while(willNeed[i]--) {
            vans.emplace_back(getAnAnswer());
            canBlock.pop();
        }
        vans.emplace_back(0);
    }
    cout << vans.size() << endl;
    for(auto e : vans) {
        cout << e << ' ';
    }
    cout << endl;
    return 0;
}