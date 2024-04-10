#include <bits/stdc++.h>

using namespace std;

#define INF 2000000000
#define N 100100

int nodes = N, ini = N-2, fim = N-1;
int dist[N], work[N];

struct Edge {
  int to, rev, used_flow, cap;
};

vector < Edge > graph[N];

void addEdge(int from, int to, int cap) {
  Edge a = {to, graph[to].size(), 0, cap};
  Edge b = {from, graph[from].size(), 0, 0};
  graph[from].push_back(a);
  graph[to].push_back(b);
}

bool dinic_bfs() {
  fill(dist, dist + nodes, -1);
  dist[ini] = 0;

  queue < int > fila;
  fila.push(ini);

  while (!fila.empty()) {
    int u = fila.front();
    fila.pop();

    for (int i = 0; i < graph[u].size(); i++) {
      Edge &e = graph[u][i];
      int v = e.to;
      if (dist[v] < 0 && e.used_flow < e.cap) {
        dist[v] = dist[u] + 1;
        fila.push(v);
      }
    }
  }

  return dist[fim] >= 0;
}

int dinic_dfs(int u, int flow) {
  if (u == fim)
    return flow;

  for (int &i = work[u]; i < graph[u].size(); i++) {
    Edge &e = graph[u][i];

    if (e.cap > e.used_flow) {
      int v = e.to;

      if (dist[v] == dist[u] + 1) {
        int minf = dinic_dfs(v, min(flow, e.cap - e.used_flow));
        if (minf > 0) {
          e.used_flow += minf;
          graph[v][e.rev].used_flow -= minf;
          return minf;
        }
      }
    }
  }

  return 0;
}

int flow(int _ini, int _fim) {
  ini = _ini;
  fim = _fim;
  int result = 0;

  while (dinic_bfs()) {
    fill(work, work + nodes, 0);
    while (int delta = dinic_dfs(ini, INT_MAX))
      result += delta;
  }

  return result;
}

int n, sz;
char s[20]; string str, tmp;
vector<string> adj[N];

int who(string s) {
    if(s == "S") return 0;
    if(s == "M") return 1;
    if(s == "L") return 2;
    if(s == "XL") return 3;
    if(s == "XXL") return 4;
    if(s == "XXXL") return 5;
}

int main() {
    for(int i = 0; i < 6; i++) {
        scanf("%d", &sz);
        addEdge(100001 + i, fim, sz);
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        addEdge(ini, i, 1);

        scanf("%s", s);
        str = s;
        tmp = "";
        for(int j = 0; j < str.size(); j++) {
            if(str[j] == ',') {
                addEdge(i, 100001 + who(tmp), 1);
                adj[i].push_back(tmp);
                tmp = "";
            } else tmp += str[j];
        }
        addEdge(i, 100001 + who(tmp), 1);
        adj[i].push_back(tmp);
    }

    if(flow(ini, fim) == n) {
        puts("YES");
        for(int i = 0; i < n; i++) {
            int j = 0;
            for(Edge ed : graph[i]) {
                if(ed.used_flow == 1) {
                    printf("%s\n", adj[i][j].c_str());
                    break;
                }
                if(ed.to != ini) j++;
            }
        }
    } else puts("NO");
}