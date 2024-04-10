#include <bits/stdc++.h>
using namespace std;

const int ms = 1500; // Quantidade maxima de vertices
const int me = 5005; // Quantidade maxima de arestas

int adj[ms], to[me], ant[me], wt[me], z, n;
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

int deg[ms];
int corVer[ms];

int main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        clear();
        memset(corVer, 0, sizeof corVer);
        memset(deg, 0, sizeof deg);
        int n, m, k;
        cin >> n >> m >> k;
        int src = n + m + 5;
        int snk = n + m + 6;
        for(int i = 1; i <= m; i++) {
            add(src, i, 1);
            int u, v;
            cin >> u >> v;
            add(i, u+m, 1);
            add(i, v+m, 1);
            deg[u+m]++;
            deg[v+m]++;
        }
        int sum = 0;
        for(int i = m+1; i <= m + n; i++) {
            if(deg[i] > k) {
                add(i, snk, 2*(deg[i]-k));
                sum += 2*(deg[i]-k);
            }
        }
        if(maxflow(src, snk) == sum) {
            int curColor = 1;
            for(int i = 1; i <= m; i++) {
                int j = -1;
                for(int e = adj[i]; e > -1; e = ant[e]) {
                    if(!wt[e]) {
                        j = to[e];
                    }
                }
                if(j == src) cout << curColor++ << ' ';
                else {
                    if(!corVer[j]) {
                        corVer[j] = curColor;
                        cout << curColor++ << ' ';
                    } else {
                        cout << corVer[j] << ' ';
                        corVer[j] = 0;
                    }

                }
            }
        } else {
            for(int i = 0; i < m; i++) cout << 0 << ' ';
        }
        cout << '\n';
    }
}