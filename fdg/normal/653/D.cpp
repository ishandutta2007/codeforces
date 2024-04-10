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

int a[505], b[505], c[505];

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i] >> c[i]; --a[i]; --b[i];
  }
  long double l = 0, r = 1000909;
  for (int it = 0; it < 100; ++it) {
    long double mid = (l + r) / 2;
    DinicFlow flow(n, 0, n - 1);
    for (int i = 0; i < m; ++i) {
      long long cap = min((long long) (c[i] / mid), 1000000LL);
      flow.addEdge(a[i], b[i], cap);
    }

    if (flow.flow() >= x) l = mid;
    else r = mid;
  }
  printf("%.10lf\n", (double) (x * (l + r) / 2));
  return 0;
}