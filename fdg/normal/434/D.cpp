#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

struct DinicFlow{
  struct Edge{
    Edge(int _to,int _cap,int _next) : to(_to), cap(_cap), next(_next) {};
    int to,cap,next;
  };
  int n,s,t,fl;
  vector <int> first,d,q,ptr;
  vector <bool> used;
  vector <Edge> a;
  DinicFlow(int _n,int _s,int _t) : n(_n), s(_s), t(_t) {
    first.resize(n,-1);
  };
  void addEdge(int u,int v,int cap,bool oriented = true) {
    // cout << u << "  " << v << " " << cap << endl;
    a.push_back(Edge(v,cap,first[u])); first[u]=a.size()-1;
    a.push_back(Edge(u,oriented ? 0 : cap,first[v])); first[v]=a.size()-1;
  }
  bool bfs() {
    d.clear(); d.resize(n,-1);
    d[s]=0; q.clear(); q.push_back(s);
    for(int i=0;i<q.size();++i) {
      int v=q[i];
      for(int e=first[v];e!=-1;e=a[e].next) {
        int u=a[e].to;
        if (d[u]==-1&&a[e].cap) {
          d[u]=d[v]+1;
          q.push_back(u);
        }
      }
    }
    return d[t]!=-1;
  }
  int dfs(int v,int push = 1000000000) {
    if (v==t||push<=0) {
      fl+=push;
      return push;
    }
    int pushed=0;
    for(int e=ptr[v];e!=-1;e=a[e].next) {
      int u=a[e].to; ptr[v]=a[e].next;
      if (d[v]+1==d[u]) {
        if (int val=dfs(u,min(push-pushed,a[e].cap))) {
          pushed+=val;
          a[e].cap-=val;
          a[e^1].cap+=val;
        }
      }
    }
    return pushed;
  }
  int flow() {
    fl=0;
    while(bfs()) {
      ptr=first;
      dfs(s);
    }
    return fl;
  }
};

const int MAX = 10000000;
int a[51], b[51], c[51], l[51], r[51], L[51], R[51];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
  }
  int s = 0, t = 201 * n + 1, last = 0;
  DinicFlow flow(t + 1, s, t);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &l[i], &r[i]);
    L[i] = l[i]; R[i] = r[i];
    flow.addEdge(s, last + 1, 10 * MAX);
    for (int j = l[i]; j <= r[i]; ++j) {
      flow.addEdge(last + j - l[i] + 1, last + j - l[i] + 2, MAX - (a[i] * j * j + b[i] * j + c[i]));
    }
    flow.addEdge(last + r[i] - l[i] + 2, t, 10 * MAX);
    r[i] = last + r[i] - l[i] + 2;
    l[i] = last + 2;
    last = r[i];
  }
  for (int i = 0; i < m; ++i) {
    int u, v, d;
    scanf("%d%d%d", &u, &v, &d);
    --u; --v;
    for (int j = L[u] - 1; j <= R[u]; ++j) {
      int ind = (j - d - L[v]) + l[v];
      if (l[v] - 1 <= ind && ind <= r[v]) {
        flow.addEdge(l[u] + (j - L[u]), ind, 10 * MAX);
      }
    }
  }
  printf("%d\n", MAX * n - flow.flow());
  return 0;
}