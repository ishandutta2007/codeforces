#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

struct Edge {
  int u, v;
  LL cap, flow;
  Edge() {}
  Edge(int u, int v, LL cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
  int N;
  vector<Edge> E;
  vector<vector<int>> g;
  vector<int> d, pt;
  
  Dinic(int N): N(N), E(0), g(N), d(N), pt(N) {}

  void AddEdge(int u, int v, LL cap) {
    if (u != v) {
      E.emplace_back(u, v, cap);
      g[u].emplace_back(E.size() - 1);
      E.emplace_back(v, u, 0);
      g[v].emplace_back(E.size() - 1);
    }
  }

  bool BFS(int S, int T) {
    queue<int> q({S});
    fill(d.begin(), d.end(), N + 1);
    d[S] = 0;
    while(!q.empty()) {
      int u = q.front(); q.pop();
      if (u == T) break;
      for (int k: g[u]) {
        Edge &e = E[k];
        if (e.flow < e.cap && d[e.v] > d[e.u] + 1) {
          d[e.v] = d[e.u] + 1;
          q.emplace(e.v);
        }
      }
    }
    return d[T] != N + 1;
  }

  LL DFS(int u, int T, LL flow = -1) {
    if (u == T || flow == 0) return flow;
    for (int &i = pt[u]; i < g[u].size(); ++i) {
      Edge &e = E[g[u][i]];
      Edge &oe = E[g[u][i]^1];
      if (d[e.v] == d[e.u] + 1) {
        LL amt = e.cap - e.flow;
        if (flow != -1 && amt > flow) amt = flow;
        if (LL pushed = DFS(e.v, T, amt)) {
          e.flow += pushed;
          oe.flow -= pushed;
          return pushed;
        }
      }
    }
    return 0;
  }

  LL MaxFlow(int S, int T) {
    LL total = 0;
    while (BFS(S, T)) {
      fill(pt.begin(), pt.end(), 0);
      while (LL flow = DFS(S, T))
        total += flow;
    }
    return total;
  }
};

int getId(int a, int b)
{
    a--;
    return a * 51 + b;
}

int getId2(int x)
{
    return x + 51 * 50;
}

const int src = 100 + 51 * 50;
const int snk = src + 1;

Dinic dinic(51 * 50 + 50 + 1000);

void add_edge(int u, int v)
{
    dinic.AddEdge(u, v, 0x3f3f3f3f3f3f3f3fLL);
}

int main()
{
    int n, h, m;
    scanf("%d%d%d", &n, &h, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= h; j++)
        {
            if (j > 0)
            {
                add_edge(getId(i, j), getId(i, j-1));
                dinic.AddEdge(src, getId(i, j), j*j - (j-1)*(j-1));
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int l, r, x, c;
        scanf("%d%d%d%d", &l, &r, &x, &c);
        if (x >= h)
        {
            continue;
        }
        for (int j = l; j <= r; j++)
        {
            add_edge(getId(j, x+1), getId2(i));
        }
        dinic.AddEdge(getId2(i), snk, c);
    }
    cout << h*h*n - dinic.MaxFlow(src, snk) << endl;
}