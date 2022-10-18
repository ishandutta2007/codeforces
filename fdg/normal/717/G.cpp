#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <map>
#include <queue>

using namespace std;

const int inf=1000000009;

struct MinCostFlow {
  MinCostFlow(int _n,int _s,int _t) : n(_n), s(_s), t(_t), fl(0), cost(0) {
    first.resize(n,-1);
    phi.resize(n,0);
    dist.resize(n);
    prev.resize(n);
  };
  struct Edge {
    Edge(int _to,int _cap,int _cost,int _next) : to(_to), cap(_cap), cost(_cost), next(_next) {};
    int to,next,cap,cost;
  };
  void addEdge(int u,int v,int cap,int cost) {
    a.push_back(Edge(v,cap,cost,first[u])); first[u]=a.size()-1;
    a.push_back(Edge(u,0,-cost,first[v])); first[v]=a.size()-1;
  }
  bool augment() {
    dist.assign(n,inf);
    dist[s]=0;
    priority_queue < pair <int,int> > q; q.push(make_pair(0,s));
    while(q.size()) {
      pair <int,int> top=q.top(); q.pop();
      if (dist[top.second]!=-top.first) continue;
      int u=top.second;
      for(int e=first[u];e!=-1;e=a[e].next) {
        int v=a[e].to,ndist=-top.first+a[e].cost+phi[u]-phi[v];
        if (a[e].cap>0&&dist[v]>ndist) {
          dist[v]=ndist;
          q.push(make_pair(-ndist,v));
          prev[v]=e;
        }
      }
    }
    return dist[t]!=inf;
  }
  pair <int,int> flow() {
    while(augment()) {
      int cur=t,size=inf;
      while(cur!=s) {
        int e=prev[cur];
        size=min(size,a[e].cap);
        cur=a[e^1].to;
      }
      // if ((dist[t]+phi[t]-phi[s])*size>=0) break;
      fl+=size; cost+=(dist[t]+phi[t]-phi[s])*size;
      cur=t;
      while(cur!=s) {
        int e=prev[cur];
        a[e].cap-=size;
        a[e^1].cap+=size;
        cur=a[e^1].to;
      }
      for(int i=0;i<n;++i)
        if (phi[i]<inf) phi[i]+=dist[i];
    }
    return make_pair(fl,cost);
  }
  int n,s,t,fl,cost;
  vector <int> first,phi,prev,dist;
  vector <Edge> a;
};

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string ss;
  map<string, int> f;
  int m;
  cin >> ss;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    string w; int p;
    cin >> w >> p;
    f[w] = max(f[w], p);
  }
  int x;
  cin >> x;
  int s = n + 2, t = s + 1;
  MinCostFlow flow(t + 1, s, t);
  flow.addEdge(s, 0, x, 0);
  flow.addEdge(n, t, x, 0);
  for (int i = 0; i < n; ++i)
    flow.addEdge(i, i + 1, x, 0);
  for (int i = 0; i < n; ++i) {
    for (auto p : f) {
      if (i + p.first.size() <= n && ss.substr(i, p.first.size()) == p.first) {
        flow.addEdge(i, i + p.first.size(), 1, -p.second);
      }
    }
  }
  cout << -flow.flow().second << endl;
  return 0;
}